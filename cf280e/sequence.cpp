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

const int maxn=300005;
const long double eps=1e-9;

int N, Q, A, B;
long double MID[maxn], ans[maxn];

struct NODE
{
	long double xl, xr, a, b, c, dx, da, db, dc;
	NODE *l, *r;
	
	NODE() {}
	NODE(long double _xl, long double _xr, long double _a=0, long double _b=0, long double _c=0, NODE *_l=0, NODE *_r=0)
		: xl(_xl), xr(_xr), a(_a), b(_b), c(_c), dx(0), da(0), db(0), dc(0), l(_l), r(_r) {}
	
	void adjx(long double _dx)
	{
		c +=(a *-_dx+b )*-_dx, b +=2*a *-_dx;
		dc+=(da*-_dx+db)*-_dx, db+=2*da*-_dx;
		xl+=_dx, xr+=_dx;
		dx+=_dx;
	}
	
	void adjy(long double _da, long double _db, long double _dc)
	{
		a +=_da, b +=_db, c +=_dc;
		da+=_da, db+=_db, dc+=_dc;
	}
	
	void pushDown()
	{
		if (!dx && !da && !db && !dc) return;
		if (l) l->adjx(dx), l->adjy(da,db,dc);
		if (r) r->adjx(dx), r->adjy(da,db,dc);
		dx=da=db=dc=0;
	}
	
	long double inter(long double x)
	{
		return (a*x+b)*x+c;
	}
} *root, pool[maxn*3];
int pn;

inline void RR(NODE *&x)
{
	NODE *t(x->l);
	x->l=t->r;
	t->r=x;
	x=t;
}

inline void LR(NODE *&x)
{
	NODE *t(x->r);
	x->r=t->l;
	t->l=x;
	x=t;
}

pair<NODE*,long double> findMin(NODE *&x)
{
	pair<NODE*,long double> ret(x,min<long double>(-x->b/(2*x->a),Q));
	x->pushDown();
	if (ret.second<x->xl-eps) ret=(x->l?findMin(x->l):make_pair(x,x->xl)); else
	if (ret.second>x->xr+eps) ret=(x->r?findMin(x->r):make_pair(x,x->xr));
	NODE *p=ret.first;
	if (x->l && x->l->l==p) RR(x), RR(x); else
	if (x->l && x->l->r==p) LR(x->l), RR(x); else
	if (x->r && x->r->l==p) RR(x->r), LR(x); else
	if (x->r && x->r->r==p) LR(x), LR(x); else
	if (x==root && x->l==p) RR(x); else
	if (x==root && x->r==p) LR(x);
	return ret;
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	READ(N), READ(Q), READ(A), READ(B);
	root=&pool[pn++], *root=NODE(1,Q);
	pair<NODE*,long double> MIN;
	NODE *p;
	for (int i=1;i<=N;i++)
	{
		if (i>1)
			if (A<B)
			{
				MIN=findMin(root);
				p=MIN.first;
				long double &mid=MID[i];
				mid=MIN.second;
				NODE *q0, *q1(p->l), *q2(p->r);
				if (mid-p->xl>eps)
					q1=&pool[pn++], *q1=NODE(p->xl,mid,p->a,p->b,p->c,p->l,0);
				if (p->xr-mid>eps)
					q2=&pool[pn++], *q2=NODE(mid,p->xr,p->a,p->b,p->c,0,p->r);
				if (q1) q1->adjx(A);
				if (q2) q2->adjx(B);
				q0=&pool[pn++], *q0=NODE(mid+A,mid+B,0,0,p->inter(mid),q1,q2);
				root=q0;
			} else
				root->adjx(A);
		int x;
		READ(x);
		root->adjy(1,-2*x,(double)x*x);
	}
	MIN=findMin(root);
	p=MIN.first;
	long double x=MIN.second, y=p->inter(x);
	for (int i=N;i;i--)
	{
		ans[i]=x;
		if (x>MID[i]+B) x-=B; else
		if (x<MID[i]+A) x-=A; else
			x=MID[i];
	}
	for (int i=1;i<N;i++) printf("%.8f ",(double)ans[i]);
	printf("%.8f\n%.8f\n",(double)ans[N],(double)y);
	return 0;
}

