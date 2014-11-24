#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int,int> PI;
#define fi first
#define se second

const int maxn=205, maxm=1005;

int N, M, X[maxm], Y[maxm], Z[maxm], color[maxn], size[maxn], V[maxn][maxn], V2[maxn][maxn], S, T, m, a[maxn], b[maxm<<1], c[maxm<<1], d[maxm<<1], dist[maxn], next[maxn], pos[maxn];

void Bfs()
{
	static int list[maxn];
	int st, en;
	list[st=en=1]=S;
	memset(dist,255,sizeof dist);
	dist[S]=0;
	for (;st<=en;st++)
	{
		int now(list[st]);
		for (int i=a[now];i;i=c[i]) if (!~dist[b[i]] && d[i])
		{
			dist[b[i]]=dist[now]+1;
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
		flow-=now, ret+=now;
		d[i]-=now, d[i^1]+=now;
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
		ret+=Dfs(S,0x7fffffff);
	}
}

void FF(int x, int forb, int ori, int nxt)
{
	color[x]=nxt;
	for (int i=1;i<=M;i++)
	{
		if (X[i]==x && color[Y[i]]==ori && Y[i]!=forb) FF(Y[i],forb,ori,nxt);
		if (Y[i]==x && color[X[i]]==ori && X[i]!=forb) FF(X[i],forb,ori,nxt);
	}
}

PI Dfs(int c)
{
	int MIN(0);
	for (int i=1;i<=M;i++)
		if (color[X[i]]==c && color[Y[i]]==c && (!MIN || Z[i]<Z[MIN]))
			MIN=i;
	if (!MIN)
	{
		int single(-1);
		for (int i=0;!~single;i++)
			if (color[i]==c) single=pos[i];
		return PI(single,single);
	}
	static int COLOR;
	int tmp;
	FF(Y[MIN],X[MIN],c,tmp=++COLOR);
	PI L=Dfs(c), R=Dfs(tmp);
	next[L.se]=R.fi;
	return PI(L.fi,R.se);
}

int main()
{
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
	size[0]=N;
	int tot(0);
	for (int t=1;t<N;t++)
	{
		int cc(-1);
		for (int i=0;!~cc;i++)
			if (size[i]>1) cc=i;
		memset(V,0,sizeof V);
		for (int i=1;i<=M;i++)
		{
			int x(color[X[i]]==cc?X[i]:pos[color[X[i]]]);
			int y(color[Y[i]]==cc?Y[i]:pos[color[Y[i]]]);
			V[min(x,y)][max(x,y)]+=Z[i];
		}
		m=1;
		memset(a,0,sizeof a);
		for (int i=0;i<N;i++)
			for (int j=i+1;j<=N;j++) if (V[i][j])
			{
				m++, b[m]=j, c[m]=a[i], a[i]=m, d[m]=V[i][j];
				m++, b[m]=i, c[m]=a[j], a[j]=m, d[m]=V[i][j];
			}
		S=T=0;
		for (int i=1;!T;i++)
			if (color[i]==cc) (S?T:S)=i;
		int cut=Flow();
		tot+=cut;
		for (int i=1;i<=N;i++) if (color[i]==cc && ~dist[i])
			size[cc]--, color[i]=t, size[t]++;
		V2[cc][t]=V2[t][cc]=cut;
		/*if (~dist[0])
			for (int i=0;i<t;i++) if (V2[i][cc])
			{
				V2[i][t]=V2[t][i]=V2[i][cc];
				V2[i][cc]=V2[cc][i]=0;
			}*/
		for (int i=0;i<t;i++) if (V2[i][cc] && ~dist[pos[i]])
		{
			V2[i][t]=V2[t][i]=V2[i][cc];
			V2[i][cc]=V2[cc][i]=0;
		}
		for (int i=1;i<=N;i++) pos[color[i]]=i;
	}
	printf("%d\n",tot);
	M=0;
	for (int i=0;i<N-1;i++)
		for (int j=i+1;j<N;j++) if (V2[i][j])
			M++, X[M]=i, Y[M]=j, Z[M]=V2[i][j];
	//for (int i=1;i<=N;i++) pos[color[i]]=i;
	memset(color,0,sizeof color);
	PI ans=Dfs(0);
	for (int i=ans.fi;i!=ans.se;i=next[i])
		printf("%d ",i);
	printf("%d\n",ans.se);
	return 0;
}

