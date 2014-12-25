#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline void READ(int &x)
{
	char c;
	x=0;
	do c=getchar(); while (c<'0' || c>'9');
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
}

typedef pair<int,int> PI;
#define fi first
#define se second

const int maxn=100005;

int N, L, W, stamp, m, a[maxn], b[maxn<<1], c[maxn<<1], d[maxn<<1], size[maxn], f[maxn], g[maxn];
bool forb[maxn];
PI post[maxn];

void findSize(int x, int father)
{
	size[x]=1;
	for (int i=a[x];i;i=c[i]) if (b[i]!=father && !forb[b[i]])
	{
		findSize(b[i],x);
		size[x]+=size[b[i]];
	}
}

int findRoot(int x, int father, int overall)
{
	int ret=(size[x]*2>=overall?x:0);
	for (int i=a[x];i;i=c[i]) if (b[i]!=father && !forb[b[i]])
	{
		int got=findRoot(b[i],x,overall);
		if (got) return got;
		if (size[b[i]]*2>overall) ret=0;
	}
	return ret;
}

void Dfs(int x, int father, int v1, int v2, int &n)
{
	if (v1<=L && v2<=W) post[n++]=PI(v2,v1);
	for (int i=a[x];i;i=c[i]) if (b[i]!=father && !forb[b[i]])
		Dfs(b[i],x,v1+1,v2+d[i],n);
}

void Ins(int x, int v)
{
	for (x++;x<=L;x+=x&-x)
	{
		if (g[x]!=stamp) g[x]=stamp, f[x]=0;
		f[x]+=v;
	}
}

int Find(int x)
{
	int ret(0);
	for (x++;x;x-=x&-x)
		if (g[x]==stamp) ret+=f[x];
	return ret;
}

long long Stat(int begin, int end)
{
	long long ret(0);
	sort(post+begin,post+end);
	stamp++;
	for (int i=end-1,j=begin;i>=begin;i--)
	{
		while (j<i && post[j].fi+post[i].fi<=W) Ins(post[j++].se,1);
		if (j>i) Ins(post[--j].se,-1);
		ret+=Find(L-post[i].se);
	}
	return ret;
}

int main()
{
	freopen("vertices.in","r",stdin);
	freopen("vertices.out","w",stdout);
	READ(N), READ(L), READ(W);
	for (int i=1;i<N;i++)
	{
		int x, y, z;
		x=i+1, READ(y), READ(z);
		m++, b[m]=y, c[m]=a[x], a[x]=m, d[m]=z;
		m++, b[m]=x, c[m]=a[y], a[y]=m, d[m]=z;
	}
	static int list[maxn];
	int st, en;
	long long ans=0;
	list[st=en=1]=1;
	for (;st<=en;st++)
	{
		int ori=list[st];
		findSize(ori,0);
		int x=findRoot(ori,0,size[ori]), n=0;
		forb[x]=true;
		for (int i=a[x];i;i=c[i]) if (!forb[b[i]])
		{
			int _n(n);
			Dfs(b[i],x,1,d[i],n);
			ans-=Stat(_n,n);
			list[++en]=b[i];
		}
		post[n++]=PI(0,0);
		ans+=Stat(0,n);
	}
	printf("%I64d\n",ans);
	return 0;
}

