#include<cstdio>
#include<cstring>
#include<list>
#include<bitset>
#include<algorithm>
using namespace std;

const int maxn=105;

int N, M, S, T, K, f[maxn][maxn], g[maxn][maxn], t[maxn][maxn], dcnt[maxn][maxn], X[maxn], Y[maxn];
bool A[maxn][maxn];
bitset<maxn> cut[maxn][maxn];
list< pair<int, pair<int,int> > > L;

#define fi first
#define se second
#define mkp(x,y) make_pair(x,y)

int main()
{
	freopen("meeting.in","r",stdin);
	freopen("meeting.out","w",stdout);
	scanf("%d%d%d%d",&N,&M,&S,&T);
	memset(f,63,sizeof f);
	memset(g,63,sizeof g);
	for (int i=1;i<=N;i++)
		f[i][i]=0;
	for (int i=1;i<=M;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		A[x][y]=true, f[x][y]=1;
	}
	for (int k=1;k<=N;k++)
		for (int i=1;i<=N;i++) if (i!=k)
			for (int j=1;j<=N;j++) if (j!=k)
				if (f[i][k]+f[k][j]<f[i][j])
				{
					f[i][j]=f[i][k]+f[k][j];
					cut[i][j]=(cut[i][k]|cut[k][j]);
					cut[i][j][k]=true;
				} else
				if (f[i][k]+f[k][j]==f[i][j])
					cut[i][j]&=(cut[i][k]|cut[k][j]);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			cut[i][j][i]=cut[i][j][j]=true;
	scanf("%d",&K);
	for (int i=1;i<=K;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		if (f[X[i]][Y[i]]==f[X[i]][T]+f[T][Y[i]])
			L.push_back(mkp(g[T][i]=1,mkp(T,i)));
		for (int j=1;j<=N;j++)
			for (int k=1;k<=N;k++)
				dcnt[j][i]+=(A[j][k] && f[X[i]][Y[i]]==f[X[i]][j]+1+f[k][Y[i]]);
	}
	while (!L.empty())
	{
		while (!L.empty() && L.front().fi>g[L.front().se.fi][L.front().se.se]) L.pop_front();
		if (L.empty()) break;
		int x(L.front().se.fi), y(L.front().se.se);
		L.pop_front();
		if (cut[X[y]][Y[y]][x])
			for (int i=1;i<=K;i++)
				if (i!=y && f[X[i]][Y[i]]==f[X[i]][x]+f[x][Y[i]] && g[x][i]>g[x][y]+1)
					L.push_back(mkp(g[x][i]=g[x][y]+1,mkp(x,i)));
		for (int i=1;i<=N;i++)
			if (A[i][x] && f[X[y]][Y[y]]==f[X[y]][i]+1+f[x][Y[y]])
			{
				t[i][y]=max(t[i][y],g[x][y]);
				if (!--dcnt[i][y] && t[i][y]<g[i][y])
					L.push_front(mkp(g[i][y]=t[i][y],mkp(i,y)));
			}
	}
	int ans(0x3f3f3f3f);
	for (int i=1;i<=K;i++) if (cut[X[i]][Y[i]][S])
		ans=min(ans,g[S][i]);
	printf("%d\n",ans==0x3f3f3f3f?-1:ans);
	return 0;
}

