#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

inline void READ(int &x)
{
	char c;
	x=0;
	do c=getchar(); while (c<'0' || c>'9');
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
}

const int maxn=100005, maxm=400005;

struct NODE
{
	int x, f, d;
	NODE *l, *r;
	NODE(int _x, int _f) : x(_x), f(_f), d(0), l(0), r(0) {}
};

int N, M, m, a[maxn], b[maxm], c[maxm], d[maxm], f[maxn], dfn[maxn], ans[maxn];
NODE *h[maxn];

NODE *Merge(NODE *a, NODE *b)
{
	if (!a) return b;
	if (!b) return a;
	if (a->f>b->f) swap(a,b);
	a->r=Merge(a->r,b);
	if (!a->l || a->r && a->r->d>a->l->d) swap(a->l,a->r);
	a->d=a->r?a->r->d+1:0;
	return a;
}

inline void Push(NODE *&root, int x, int f)
{
	root=Merge(root,new NODE(x,f));
}

inline void Pop(NODE *&root)
{
	NODE *ret=Merge(root->l,root->r);
	delete root;
	root=ret;
}

void Dij()
{
	memset(f,127,sizeof f);
	f[1]=0;
	typedef pair<int,int> PI;
	priority_queue< PI,vector<PI>,greater<PI> > heap;
	heap.push(PI(0,1));
	while (!heap.empty())
	{
		while (!heap.empty() && heap.top().first>f[heap.top().second]) heap.pop();
		if (heap.empty()) return;
		int x=heap.top().second;
		heap.pop();
		for (int i=a[x];i;i=c[i]) if (f[x]+d[i]<f[b[i]])
		{
			f[b[i]]=f[x]+d[i];
			heap.push(PI(f[b[i]],b[i]));
		}
	}
}

void Dfs(int x, int father=0)
{
	static int DFN;
	dfn[x]=++DFN;
	for (int i=a[x];i;i=c[i]) if (b[i]!=father)
		if (f[x]+d[i]==f[b[i]])
		{
			Dfs(b[i],x);
			h[x]=Merge(h[x],h[b[i]]);
		}
		else
			Push(h[x],b[i],f[b[i]]+d[i]+f[x]);
	while (h[x] && dfn[h[x]->x]>=dfn[x]) Pop(h[x]);
	if (!h[x]) return;
	ans[x]=h[x]->f-f[x];
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	READ(N), READ(M);
	for (int i=1;i<=M;i++)
	{
		int x, y, z;
		READ(x), READ(y), READ(z);
		m++, b[m]=y, c[m]=a[x], a[x]=m, d[m]=z;
		m++, b[m]=x, c[m]=a[y], a[y]=m, d[m]=z;
	}
	Dij();
	memset(ans,255,sizeof ans);
	Dfs(1);
	for (int i=2;i<=N;i++) printf("%d\n",ans[i]);
	return 0;
}

