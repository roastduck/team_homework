#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=505, inf=0x7fffffff;

int N, m, ans, X[maxn], Y[maxn], R[maxn], a[maxn], b[maxn*maxn*2], c[maxn*maxn*2], d[maxn*maxn*2], dist[maxn];

inline void Add(int x, int y, int z)
{
	m++, b[m]=y, c[m]=a[x], a[x]=m, d[m]=z;
	m++, b[m]=x, c[m]=a[y], a[y]=m, d[m]=0;
}

#define sqr(x) ((x)*(x))
#define S 0
#define T (N+1)

void Bfs()
{
	static int list[maxn];
	int st, en;
	list[st=en=1]=S;
	memset(dist,255,sizeof dist);
	dist[S]=0;
	for (;st<=en;st++)
	{
		int x(list[st]);
		for (int i=a[x];i;i=c[i]) if (d[i] && !~dist[b[i]])
		{
			dist[b[i]]=dist[x]+1;
			list[++en]=b[i];
		}
	}
}

int Dfs(int x, int flow)
{
	if (x==T) return flow;
	int ret(0);
	for (int i=a[x];i;i=c[i]) if (d[i] && dist[b[i]]==dist[x]+1)
	{
		int now=Dfs(b[i],min(flow,d[i]));
		ret+=now, flow-=now;
		d[i^1]+=now, d[i]-=now;
		if (!flow) return ret;
	}
	dist[x]=-1;
	return ret;
}

int Flow()
{
	int ret(0);
	while (true)
	{
		Bfs();
		if (!~dist[T]) return ret;
		ret+=Dfs(S,inf);
	}
}

int main()
{
	freopen("wifi.in","r",stdin);
	freopen("wifi.out","w",stdout);
	int TT;
	scanf("%d",&TT);
	for (int tt=1;tt<=TT;tt++)
	{
		memset(a,0,sizeof a);
		m=1;
		ans=0;
		scanf("%d",&N);
		for (int i=1;i<=N;i++)
		{
			int s;
			scanf("%d%d%d%d",&X[i],&Y[i],&R[i],&s);
			if (s>0)
				Add(S,i,s), ans+=s;
			else
				Add(i,T,-s);
		}
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				if (i!=j && sqr(X[i]-X[j])+sqr(Y[i]-Y[j])<=sqr(R[i]))
					Add(i,j,inf);
		ans-=Flow();
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

