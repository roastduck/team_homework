#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=40005;

int N, M, A[maxn], pre[maxn], f[maxn], eat[maxn], num[maxn];

int main()
{
	freopen("cleaning.in","r",stdin);
	freopen("cleaning.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		scanf("%d",&A[i]);
		for (int j=1; j*j<=N && j<=M; j++)
			if (pre[A[i]]<=eat[j] && ++num[j]>j)
			{
				do eat[j]++; while (pre[A[eat[j]]]>eat[j]);
				num[j]--;
			}
		pre[A[i]]=i;
		f[i]=0x7fffffff;
		for (int j=1; j*j<=N && j<=M; j++)
			f[i]=min(f[i],f[eat[j]]+j*j);
	}
	printf("%d\n",f[N]);
	return 0;
}

