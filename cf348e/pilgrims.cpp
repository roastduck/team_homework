#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

int N, M, m, ans1, ans2, root, deepest, second, third, a[maxn], b[maxn<<1], c[maxn<<1], d[maxn<<1], father[maxn], depth[maxn], maxDep[maxn], maxDepCnt[maxn], monaCnt[maxn];
bool mona[maxn];

int Far(int x)
{
	int ret(mona[x]*x);
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
	maxDepCnt[x]=mona[x];
	monaCnt[x]=mona[x];
	for (int i=a[x];i;i=c[i]) if (b[i]!=father[x])
	{
		father[b[i]]=x;
		depth[b[i]]=depth[x]+d[i];
		Dfs1(b[i]);
		monaCnt[x]+=monaCnt[b[i]];
		if (maxDep[b[i]]>maxDep[x]) maxDep[x]=maxDep[b[i]], maxDepCnt[x]=0;
		if (maxDep[b[i]]==maxDep[x]) maxDepCnt[x]+=maxDepCnt[b[i]];
	}
}

void Dfs2(int x, int y)
{
	if (!mona[x])
	{
		int tot=monaCnt[x];
		if (maxDep[x]==maxDep[y] && maxDepCnt[x]==maxDepCnt[y])
		{
			if (y==deepest)
				tot+=(M-monaCnt[y])*(maxDep[second]<maxDep[y])+monaCnt[second]*(maxDep[second]==maxDep[y]&&maxDep[third]<maxDep[y]);
			if (y==second)
				tot+=monaCnt[deepest]*(maxDep[y]<maxDep[deepest]||maxDep[y]==maxDep[deepest]&&maxDep[third]<maxDep[y]);
		}
		if (tot>ans1) ans1=tot, ans2=0;
		if (tot==ans1) ans2++;
	}
	for (int i=a[x];i;i=c[i]) if (b[i]!=father[x])
		Dfs2(b[i],y);
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
	root=term;
	while (depth[root]*2>depth[term]) root=father[root];
	father[root]=depth[root]=0;
	Dfs1(root);
	for (int i=a[root];i;i=c[i])
		if (maxDep[b[i]]>maxDep[deepest])
			third=second, second=deepest, deepest=b[i];
		else if (maxDep[b[i]]>maxDep[second])
			third=second, second=b[i];
		else if (maxDep[b[i]]>maxDep[third])
			third=b[i];
	if (!mona[root]) ans1=M, ans2=1;
	for (int i=a[root];i;i=c[i])
		Dfs2(b[i],b[i]);
	printf("%d %d\n",ans1,ans2);
	return 0;
}

