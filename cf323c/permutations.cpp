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

struct NODE
{
	int v;
	NODE *l, *r;
	NODE() : v(0), l(0), r(0) {}
};

const int maxn=1000005;

int N, M, pos[maxn];
NODE *root[maxn];

void Ins(const NODE *old, NODE *&x, int l, int r, int q)
{
	x=new NODE();
	if (l==r)
	{
		x->v++;
		return;
	}
	int mid((l+r)>>1);
	if (q<=mid)
		Ins(old?old->l:0,x->l,l,mid,q), x->r=(old?old->r:0);
	else
		Ins(old?old->r:0,x->r,mid+1,r,q), x->l=(old?old->l:0);
	x->v=(x->l?x->l->v:0)+(x->r?x->r->v:0);
}

int Find(const NODE *x, int l, int r, int ql, int qr)
{
	if (!x) return 0;
	if (l==ql && r==qr) return x->v;
	int mid((l+r)>>1);
	if (qr<=mid) return Find(x->l,l,mid,ql,qr);
	if (ql>mid) return Find(x->r,mid+1,r,ql,qr);
	return Find(x->l,l,mid,ql,mid)+Find(x->r,mid+1,r,mid+1,qr);
}

#define f(z) (((z+ans)%N)+1)

int main()
{
	freopen("permutations.in","r",stdin);
	freopen("permutations.out","w",stdout);
	READ(N);
	for (int i=1;i<=N;i++)
	{
		int x;
		READ(x);
		pos[x]=i;
	}
	for (int i=1;i<=N;i++)
	{
		int x;
		READ(x);
		Ins(root[i-1],root[i],1,N,pos[x]);
	}
	READ(M);
	int ans=-1;
	for (int i=1;i<=M;i++)
	{
		int a, b, c, d, l1, r1, l2, r2;
		READ(a), READ(b), READ(c), READ(d);
		l1=min(f(a),f(b)), r1=max(f(a),f(b)), l2=min(f(c),f(d)), r2=max(f(c),f(d));
		ans=Find(root[r2],1,N,l1,r1)-Find(root[l2-1],1,N,l1,r1);
		printf("%d\n",ans);
	}
	return 0;
}

