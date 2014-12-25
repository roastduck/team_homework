#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5+5, maxm=105;

int N, Q, ori[maxn], num[maxn];
double ans, f[maxn][maxm];

int main()
{
	freopen("birthday.in","r",stdin);
	freopen("birthday.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&num[i]);
		f[i][num[i]]=1;
		ans+=!num[i];
		ori[i]=num[i];
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		int u, v, k;
		scanf("%d%d%d",&u,&v,&k);
		ans-=f[u][0];
		for (int kk=1;kk<=k;kk++)
		{
			for (int j=0;j<=ori[u];j++)
				f[u][j]=f[u][j]*(num[u]-j)/num[u]+f[u][j+1]*(j+1)/num[u];
			num[u]--;
			if (num[u]<ori[u]) ori[u]=num[u];
		}
		num[v]+=k;
		ans+=f[u][0];
		printf("%.11f\n",ans);
	}
	return 0;
}

