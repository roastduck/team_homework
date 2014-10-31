#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=55;
const double pi=acos(-1), eps=1e-7, inf=1.0/0;

#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))

struct DOT { double x, y; DOT(){} DOT(double _x, double _y) : x(_x), y(_y) {}};
struct CYL { double x, y, r; };
struct TRI { DOT a, b, c; TRI(){} TRI(const DOT &_a, const DOT &_b, const DOT &_c) : a(_a), b(_b), c(_c) {}};

int N;
double CIR, RED, GRN, YEL;
DOT R, G;
CYL C[maxn];
vector<TRI> Rt, Gt;

inline DOT operator+(const DOT &A, const DOT &B) { return DOT(A.x+B.x,A.y+B.y); }
inline DOT operator-(const DOT &A, const DOT &B) { return DOT(A.x-B.x,A.y-B.y); }
inline DOT operator*(double k, const DOT &A) { return DOT(k*A.x,k*A.y); }

inline double cross(const DOT &A, const DOT &B) { return A.x*B.y-B.x*A.y; }
inline double dot(const DOT &A, const DOT &B) { return A.x*B.x+A.y*B.y; }
inline double dist(const DOT &A, const DOT &B=DOT(0,0)) { return sqrt(sqr(A.x-B.x)+sqr(A.y-B.y)); }

inline double nearFrame(const DOT &O, double x, double y)
{
	double k(inf);
	if ((100-O.x)/x>-eps) k=min(k,(100-O.x)/x);
	if ((100-O.y)/y>-eps) k=min(k,(100-O.y)/y);
	if (-O.x/x>-eps) k=min(k,-O.x/x);
	if (-O.y/y>-eps) k=min(k,-O.y/y);
	return k;
}

inline double Inter(const DOT &O, const DOT &D, const CYL &C)
{
	double x0(O.x), y0(O.y), xr(C.x), yr(C.y), r(C.r), x(D.x), y(D.y);
	double a, b, c, k;
	a=x*x+y*y;
	b=2*(x*x0-x*xr+y*y0-y*yr);
	c=-r*r+x0*x0-2*x0*xr+xr*xr+y0*y0-2*y0*yr+yr*yr;
	k=(-b-sqrt(b*b-4*a*c+1e-11))/(2*a);
	return k>-eps?k:NAN;
}

inline bool eq(double a, double b)
{
	return abs(a-b)<eps;
}

void genTri(const DOT &O, vector<TRI> &tris)
{
	vector<double> dir;
	dir.pb(atan2(-O.y,-O.x));
	dir.pb(atan2(100-O.y,-O.x));
	dir.pb(atan2(-O.y,100-O.x));
	dir.pb(atan2(100-O.y,100-O.x));
	for (int i=1;i<=N;i++)
	{
		double a, b, c, d, k1, k2, r1, r2;
		a=sqr(O.x-C[i].x)-sqr(C[i].r);
		b=2*(C[i].x-O.x)*(O.y-C[i].y);
		c=sqr(O.y-C[i].y)-sqr(C[i].r);
		d=sqrt(b*b-4*a*c+1e-11);
		k1=(-b+d)/(2*a), k2=(-b-d)/(2*a);
		r1=atan(k1), r2=atan(k2);
		dir.pb(r1), dir.pb(r1+pi);
		dir.pb(r2), dir.pb(r2+pi);
	}
	sort(dir.begin(),dir.end());
	int n=unique(dir.begin(),dir.end(),eq)-dir.begin();
	while (dir.size()>n) dir.pop_back();
	for (int i=0;i<n;i++)
	{
		double r1(dir[i]), r2(dir[(i+1)%n]), near1, near2;
		near1=nearFrame(O,cos(r1),sin(r1));
		near2=nearFrame(O,cos(r2),sin(r2));
		for (int j=1;j<=N;j++)
		{
			double t1, t2;
			t1=Inter(O,DOT(cos(r1),sin(r1)),C[j]);
			t2=Inter(O,DOT(cos(r2),sin(r2)),C[j]);
			if (isfinite(t1) && isfinite(t2))
				near1=min(near1,t1), near2=min(near2,t2);
		}
		tris.pb(TRI(O,O+near1*DOT(cos(r1),sin(r1)),O+near2*DOT(cos(r2),sin(r2))));
	}
}

inline bool IN(const DOT &O, const TRI &T)
{
	double a(cross(T.a-O,T.b-O)), b(cross(T.b-O,T.c-O)), c(cross(T.c-O,T.a-O));
	return a>-eps && b>-eps && c>-eps || a<eps && b<eps && c<eps;
}

int IN(TRI &A, TRI &B)
{
	if (!IN(A.a,B))
		if (IN(A.b,B)) swap(A.a,A.b); else
		if (IN(A.c,B)) swap(A.a,A.c);
	if (!IN(A.b,B) && IN(A.c,B))
		swap(A.b,A.c);
	return IN(A.a,B)+IN(A.b,B)+IN(A.c,B);
}

void Inter(const DOT &A, const DOT &B, const DOT &P, const DOT &Q)
{
	double a1, a2, a0, b1, b2, b0, d0, d1, d2, p, q;
	a1=B.x-A.x, a2=P.x-Q.x, a0=P.x-A.x;
	b1=B.y-A.y, b2=P.y-Q.y, b0=P.y-A.y;
	d0=a1*b2-a2*b1, d1=a0*b2-a2*b0, d2=a1*b0-a0*b1;
	p=d1/d0, q=d2/d0;
	if (p>-eps && p<1+eps && q>-eps && q<1+eps) throw(A+p*(B-A));
}

DOT Inter(const DOT &A, const DOT &B, const TRI &T)
{
	try
	{
		Inter(A,B,T.a,T.b), Inter(A,B,T.b,T.c), Inter(A,B,T.c,T.a);
	}
	catch (DOT X)
	{
		return X;
	}
	return DOT(NAN,NAN);
}

template <class ITER>
double S(ITER begin, ITER end)
{
	try
	{
		for (ITER i=begin;i<end;i++)
			for (int j=1;j<=N;j++) if (dist(*i,DOT(C[j].x,C[j].y))>C[j].r-eps)
				throw(i);
	}
	catch (ITER st)
	{
		double ret(0);
		for (ITER i(st+1<end?st+1:begin), j(i+1<end?i+1:begin); j!=st; i=j, j=(j+1<end?j+1:begin))
		{
			ret+=0.5*abs(cross(*i-*st,*j-*st));
			for (int k=1;k<=N;k++)
			{
				double t1, t2;
				t1=Inter(*st,*i-*st,C[k]);
				t2=Inter(*st,*j-*st,C[k]);
				if (t1<1+eps && t2<1+eps)
				{
					DOT A(*st+t1*(*i-*st)-DOT(C[k].x,C[k].y));
					DOT B(*st+t2*(*j-*st)-DOT(C[k].x,C[k].y));
					ret-=0.5*acos(dot(A,B)/(dist(A)*dist(B)))*C[k].r*C[k].r;
				}
			}
		}
		return ret;
	}
	return 0;
}

void Inter(TRI &A, TRI &B)
{
	int AinB(IN(A,B)), BinA(IN(B,A));
	if (AinB<BinA) swap(AinB,BinA), swap(A,B);
	double s(0);
	if (AinB==3)
		s=S(&A.a,&A.c+1);
	else
	if (AinB==2 && BinA==0)
	{
		DOT P[4]={A.a,A.b,Inter(A.b,A.c,B),Inter(A.a,A.c,B)};
		s=S(P,P+4);
	} else
	if (AinB==2 && BinA==1)
	{
		DOT P[5]={A.a,A.b,Inter(A.b,A.c,B),B.a,Inter(A.a,A.c,B)};
		s=S(P,P+5);
	} else
	if (AinB==1 && BinA==0)
	{
		DOT P[3]={A.a,Inter(A.a,A.b,B),Inter(A.a,A.c,B)};
		s=S(P,P+3);
	} else
	if (AinB==1 && BinA==1)
	{
		DOT P[4]={A.a,Inter(A.a,A.b,B),B.a,Inter(A.a,A.c,B)};
		s=S(P,P+4);
	}
	RED-=s, GRN-=s, YEL+=s;
}

int main()
{
	freopen("lights.in","r",stdin);
	freopen("lights.out","w",stdout);
	scanf("%lf%lf%lf%lf%d",&R.x,&R.y,&G.x,&G.y,&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%lf%lf%lf",&C[i].x,&C[i].y,&C[i].r);
		CIR+=pi*C[i].r*C[i].r;
	}
	genTri(R,Rt), genTri(G,Gt);
	for (int i=0;i<Rt.size();i++)
		RED+=S(&Rt[i].a,&Rt[i].c+1);
	for (int i=0;i<Gt.size();i++)
		GRN+=S(&Rt[i].a,&Rt[i].c+1);
	for (int i=0;i<Rt.size();i++)
		for (int j=0;j<Gt.size();j++)
			Inter(Rt[i],Gt[j]);
	printf("%.7f\n%.7f\n%.7f\n%.7f\n",10000-RED-GRN-YEL-CIR,RED,GRN,YEL);
	return 0;
}

