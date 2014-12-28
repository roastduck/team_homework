#include<cstdio>

int N, K, f[2005][2005], d[2005];
long long ans;

int main()
{
	freopen("blueprint.in","r",stdin);
	freopen("blueprint.out","w",stdout);
	scanf("%d%d",&N,&K);
	for (int i=1;i<=N;i++)
		for (int j=i+1;j<=N;j++)
		{
			int x;
			scanf("%d",&x);
			if (!~x) continue;
			f[j][i]=f[i][j]=x;
			d[i]++, d[j]++;
			ans+=f[i][j]*2;
		}
	if (K==2)
		for (int i=1;i<=N;i++) if (d[i]==N-1)
			for (int j=1;j<=N;j++)
				ans+=(long long)f[i][j]*(N-3);
	printf("%I64d\n",K==2?ans*2/(N*(N-1)):ans/N);
	return 0;
}

