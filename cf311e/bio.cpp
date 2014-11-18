#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn=1e4+5, maxm=2005, maxp=(maxn+maxm)*2, maxe=(maxn*3+maxm*11)*2;
const ll big=1e9, inf=~(1ll<<63);

int N, M, G, m(1), a[maxp], b[maxe], c[maxe], sex[maxn], dist[maxp];
ll ans, d[maxe];

#define S 0
#define male(x) (x)
#define female(x) ((x)+N)
#define folk(x) ((x)+N+N)
#define T (N+N+M+1)

inline void Add(int x, int y, ll z)
{
	m++, b[m]=y, c[m]=a[x], a[x]=m, d[m]=z;
	m++, b[m]=x, c[m]=a[y], a[y]=m, d[m]=0;
}

void Bfs()
{
	int st, en;
	static int list[maxp];
	list[st=en=1]=S;
	memset(dist,255,sizeof dist);
	dist[S]=0;
	for (;st<=en;st++)
	{
		int x(list[st]);
		for (int i=a[x];i;i=c[i]) if (!~dist[b[i]] && d[i])
		{
			dist[b[i]]=dist[x]+1;
			list[++en]=b[i];
		}
	}
}

ll Dfs(int x, ll flow)
{
	if (x==T) return flow;
	ll ret(0);
	for (int i=a[x];i;i=c[i]) if (d[i] && dist[b[i]]==dist[x]+1)
	{
		ll now=Dfs(b[i],min(flow,d[i]));
		ret+=now, flow-=now;
		d[i^1]+=now, d[i]-=now;
		if (!flow) return ret;
	}
	dist[x]=-1;
	return ret;
}

inline ll Flow()
{
	ll ret(0);
	while (true)
	{
		Bfs();
		if (!~dist[T]) return ret;
		ret+=Dfs(S,inf);
	}
}

int main()
{
	freopen("bio.in","r",stdin);
	freopen("bio.out","w",stdout);
	scanf("%d%d%d",&N,&M,&G);
	for (int i=1;i<=N;i++) scanf("%d",&sex[i]);
	for (int i=1;i<=N;i++)
	{
		int v;
		scanf("%d",&v);
		Add(S,male(i),big+v*!sex[i]);
		Add(male(i),female(i),inf);
		Add(female(i),T,big+v*sex[i]);
		ans+=big;
	}
	for (int i=1;i<=M;i++)
	{
		int s, w, k, fri;
		scanf("%d%d%d",&s,&w,&k);
		for (int j=1;j<=k;j++)
		{
			int x;
			scanf("%d",&x);
			if (s)
				Add(male(x),folk(i),inf);
			else
				Add(folk(i),female(x),inf);
		}
		scanf("%d",&fri);
		ans+=w;
		if (s)
			Add(folk(i),T,w+fri*G);
		else
			Add(S,folk(i),w+fri*G);
	}
	printf("%I64d\n",ans-Flow());
	return 0;
}

