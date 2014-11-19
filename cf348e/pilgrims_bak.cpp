#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

int N, M, m, ans1, ans2, a[maxn], b[maxn<<1], c[maxn<<1], d[maxn<<1], father[maxn], depth[maxn], maxDep[maxn], botCnt[maxn], monaCnt[maxn];
bool mona[maxn];

int Far(int x)
{
	int ret=mona[x]*x;
	for (int i=a[x];i;i=c[i]) if (b[i]!=father[x])
	{
		father[b[i]]=x;
		depth[b[i]]=depth[x]+d[i];
		int t=Far(b[i]);
		if (t && depth[t]>depth[ret]) ret=t;
	}
	return ret;
}

void Dfs1(int x)
{
	maxDep[x]=mona[x]*depth[x];
	for (int i=a[x];i;i=c[i]) if (b[i]!=father[x])
	{
		father[b[i]]=x;
		depth[b[i]]=depth[x]+d[i];
		Dfs1(b[i]);
		maxDep[x]=max(maxDep[x],maxDep[b[i]]);
	}
}

void Dfs2(int x, int maxDep)
{
	botCnt[x]=(mona[x] && depth[x]==maxDep);
	monaCnt[x]=mona[x];
	for (int i=a[x];i;i=c[i]) if (b[i]!=father[x])
	{
		Dfs2(b[i],maxDep);
		botCnt[x]+=botCnt[b[i]];
		monaCnt[x]+=monaCnt[b[i]];
	}
}

void Dfs3(int x, int cnt)
{
	int tot=(botCnt[x]==cnt)*(M-monaCnt[x])+monaCnt[x];
	if (tot>ans1) ans1=tot, ans2=0;
	if (tot==ans1) ans2++;
	for (int i=a[x];i;i=c[i]) if (b[i]!=father[x])
		Dfs3(b[i],cnt);
}

int main()
{
	freopen("pilgrims.in","r",stdin);
	freopen("pilgrims.out","w",stdout);
	scanf("%d%d",&N,&M);
	int aMona;
	for (int i=1;i<=M;i++)
	{
		scanf("%d",&aMona);
		mona[aMona]=true;
	}
	for (int i=1;i<N;i++)
	{
		int x, y, z;
		scanf("%d%d%d",&x,&y,&z);
		m++, b[m]=y, c[m]=a[x], a[x]=m, d[m]=z;
		m++, b[m]=x, c[m]=a[y], a[y]=m, d[m]=z;
	}
	int term=Far(aMona);
	father[term]=depth[term]=0;
	term=Far(term);
	int root=term;
	while (depth[root]*2>depth[term]) root=father[root];
	father[root]=depth[root]=0;
	Dfs1(root);
	if (mona[root]) ans1=M, ans2=1;
	for (int i=a[root];i;i=c[i])
	{
		Dfs2(b[i],maxDep[b[i]]);
		Dfs3(b[i],botCnt[b[i]]);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}

