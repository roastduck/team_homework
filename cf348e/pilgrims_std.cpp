// STD !!!

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 100005
using namespace std;

int N,M,head[maxn],lk[maxn*2],next[maxn*2],le[maxn*2],w[maxn],fa[maxn],f[maxn][3],g[maxn][3],s[maxn];
bool c[maxn];

void add(int u,int v,int x,int t) {lk[t]=v,le[t]=x,next[t]=head[u],head[u]=t;}

void init()
{
	scanf("%d%d",&N,&M);
	for (int i=1,x; i<=M; i++) scanf("%d",&x),c[x]=1;
	for (int i=1,u,v,w; i<N; i++) scanf("%d%d%d",&u,&v,&w),add(u,v,w,i),add(v,u,w,i+N-1);
}

void dfs1(int u)
{
	int x=c[u]?0:-1e9,y=0;
	for (int i=head[u],v; v=lk[i],i; i=next[i]) if (v!=fa[u])
	{
		fa[v]=u,w[v]=le[i],dfs1(v);
		if (f[v][0]+w[v]>x) x=f[v][0]+w[v],y=f[v][1]; else if (f[v][0]+w[v]==x) y=0;
	}
	f[u][0]=x,f[u][1]=!y?u:y,f[u][2]=u;
}

void dfs2(int u)
{
	int z=fa[u],x=-1e9,y=0;
	for (int i=head[z],v; v=lk[i],i; i=next[i]) if (fa[v]==z&&v!=u)
		if (f[v][0]+w[v]+w[u]>x) x=f[v][0]+w[v]+w[u],y=f[v][1]; else if (f[v][0]+w[v]+w[u]==x) y=0;
	if (g[z][0]+w[u]>x) g[u][0]=g[z][0]+w[u],g[u][1]=g[z][1],g[u][2]=g[z][2];
	else if (x>g[z][0]+w[u]) g[u][0]=x,g[u][1]=!y?z:y,g[u][2]=z;
	else g[u][0]=x,g[u][1]=g[u][2]=z;
	if (g[u][0]<0&&c[u]) g[u][0]=0,g[u][1]=g[u][2]=u;
	for (int i=head[u],v; v=lk[i],i; i=next[i]) if (v!=fa[u]) dfs2(v);
}

void dfs(int u) {for (int i=head[u],v; v=lk[i],i; i=next[i]) if (v!=fa[u]) dfs(v),s[u]+=s[v];}

void doit()
{
	memset(f,192,sizeof(f)),memset(g,192,sizeof(g)),dfs1(1),dfs2(1);
	for (int i=1,x,y; i<=N; i++) if (c[i]&&f[i][0]!=g[i][0])
	{
		if (f[i][0]>g[i][0]) x=f[i][1],y=f[i][2]; else if (g[i][0]>f[i][0]) x=g[i][1],y=g[i][2];
		s[i]++,s[x]++,s[y]--,s[fa[y]]--;
	}
	dfs(1);
	int x=-1e9,y;
	for (int i=1; i<=N; i++) if (!c[i]) if (s[i]>x) x=s[i],y=1; else if (s[i]==x) y++;
	printf("%d %d\n",x,y);
}

int main()
{
	freopen("pilgrims.in","r",stdin), freopen("pilgrims.ans","w",stdout);
	init();
	doit();
	return 0;
}


// STD !!!
