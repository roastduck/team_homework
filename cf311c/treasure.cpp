#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> PI;
typedef pair<ll,int> PL;
#define fi first
#define se second

const int maxn=1e5+5, maxk=1e4+5;

int N, M, K, V[maxn], pos[maxn], P[maxk], n;
ll H, X[maxn], f[maxk], KK[25];
vector<PL> A[maxk];
priority_queue<PI> heap;

void Dij()
{
	priority_queue< PL,vector<PL>,greater<PL> > heap;
	memset(f,127,sizeof f);
	f[1]=1;
	heap.push(PL(1,1));
	while (!heap.empty())
	{
		while (!heap.empty() && heap.top().fi>f[heap.top().se])
			heap.pop();
		if (heap.empty()) break;
		int x(heap.top().se);
		heap.pop();
		for (int i=1;i<=n;i++)
		{
			int y((x+KK[i])%K);
			if (f[y]>f[x]+KK[i])
			{
				f[y]=f[x]+KK[i];
				heap.push(PL(f[y],y));
			}
		}
	}
}

int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%I64u%d%d%d",&H,&N,&M,&K);
	for (int i=1;i<=N;i++)
	{
		scanf("%I64u%d",&X[i],&V[i]);
		A[X[i]%K].push_back(PL(X[i],i));
		if (X[i]%K==1 || K==1) heap.push(PI(V[i],-i));
	}
	for (int i=0;i<K;i++)
	{
		sort(A[i].begin(),A[i].end());
		for (int j=0;j<A[i].size();j++)
			pos[A[i][j].se]=j;
		P[i]=A[i].size();
	}
	memset(f,127,sizeof f);
	f[1]=1, P[1]=0;
	while (M--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			ll x;
			scanf("%I64u",&x);
			KK[++n]=x;
			Dij();
			for (int i=0;i<K;i++)
				for (;P[i] && A[i][P[i]-1].fi>=f[i];P[i]--)
					heap.push(PI(V[A[i][P[i]-1].se],-A[i][P[i]-1].se));
		} else
		if (t==2)
		{
			int x, y;
			scanf("%d%d",&x,&y);
			V[x]-=y;
			if (pos[x]>=P[X[x]%K])
				heap.push(PI(V[x],-x));
		} else
		{
			while (!heap.empty() && heap.top().fi>V[-heap.top().se])
				heap.pop();
			if (heap.empty())
				puts("0");
			else
			{
				int x=-heap.top().se;
				printf("%d\n",V[x]), heap.pop();
				V[x]=0;
			}
		}
	}
	return 0;
}

