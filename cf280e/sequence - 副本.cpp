#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=300005;
const long double eps=1e-9;

int N, Q, A, B;
long double MID[maxn], ans[maxn];

struct NODE
{
	long double xl, xr, a, b, c, dx, da, db, dc;
	NODE *l, *r, *f;
	
	NODE(long double _xl, long double _xr, long double _a=0, long double _b=0, long double _c=0, NODE *_l=0, NODE *_r=0)
		: xl(_xl), xr(_xr), a(_a), b(_b), c(_c), dx(0), da(0), db(0), dc(0), l(_l), r(_r), f(0)
	{
		if (l) l->f=this;
		if (r) r->f=this;
	}
	
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
} *root;

inline void RR(NODE *x)
{
	NODE *t(x->l);
	t->f=x->f;
	if (x->f) (x==x->f->l?x->f->l:x->f->r)=t;
	x->f=t;
	x->l=t->r;
	if (x->l) x->l->f=x;
	t->r=x;
}

inline void LR(NODE *x)
{
	NODE *t(x->r);
	t->f=x->f;
	if (x->f) (x==x->f->l?x->f->l:x->f->r)=t;
	x->f=t;
	x->r=t->l;
	if (x->r) x->r->f=x;
	t->l=x;
}

pair<NODE*,long double> findMin(NODE *x)
{
	long double mid=min<long double>(-x->b/(2*x->a),Q);
	x->pushDown();
	if (mid<x->xl-eps) return x->l?findMin(x->l):make_pair(x,x->xl);
	if (mid>x->xr+eps) return x->r?findMin(x->r):make_pair(x,x->xr);
	return make_pair(x,mid);
}

void Splay(NODE *x)
{
	while (x->f)
	{
		if (!x->f->f)
		{
			x->f->pushDown(), x->pushDown();
			if (x==x->f->l) RR(x->f); else LR(x->f);
		} else
		{
			x->f->f->pushDown(), x->f->pushDown(), x->pushDown();
			if (x==x->f->l && x->f==x->f->f->l)
				RR(x->f->f), RR(x->f);
			else
			if (x==x->f->r && x->f==x->f->f->l)
				LR(x->f), RR(x->f);
			else
			if (x==x->f->l && x->f==x->f->f->r)
				RR(x->f), LR(x->f);
			else
				LR(x->f->f), LR(x->f);
		}
	}
	x->pushDown();
}

int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d%d%d",&N,&Q,&A,&B);
	root=new NODE(1,Q);
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
				Splay(p);
				NODE *q0, *q1(p->l), *q2(p->r);
				if (mid-p->xl>eps)
					q1=new NODE(p->xl,mid,p->a,p->b,p->c,p->l,0);
				if (p->xr-mid>eps)
					q2=new NODE(mid,p->xr,p->a,p->b,p->c,0,p->r);
				if (q1) q1->adjx(A);
				if (q2) q2->adjx(B);
				q0=new NODE(mid+A,mid+B,0,0,p->inter(mid),q1,q2);
				root=q0;
				delete p;
			} else
				root->adjx(A);
		double x;
		scanf("%lf",&x);
		root->adjy(1,-2*x,x*x);
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

