#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e6+5, mo=1000000007;

int N, M, K, f, b, n, e[maxn], ans;

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	K++;
	for (int i=1;i<=M;i++)
	{
		int u, v;
		scanf("%d%d",&u,&v);
		if (v-u==K)
			(f?b:f)=b=u, n++;
		else if (v-u!=1)
			return puts("0"), 0;
	}
	e[0]=1;
	if (!b) f=N;
	for (int i=1;i<=K-n;i++)
		e[i]=e[i-1]*2%mo;
	for (int i=max(1,b-K+1); i<=f && i+K<=N; i++)
		ans+=e[min(N-K-i+1,K)-n-(i<f)], ans%=mo;
	printf("%d\n",ans+!M);
	return 0;
}

