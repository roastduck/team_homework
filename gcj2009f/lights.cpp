#include<cmath>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=55;
const double pi=acos(-1), eps=1e-8, inf=1.0/0;

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
inline bool operator<(const DOT &A, const DOT &B) { return A.x<B.x-eps || A.x<B.x+eps && A.y<B.y; }

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
	k=(-b-sqrt(b*b-4*a*c+1e-9))/(2*a);
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
		double a1, b1, c1, d1, a2, b2, c2, d2, k1, k2, k11, k12, k21, k22, r1, r2;
		a1=sqr(O.x-C[i].x)-sqr(C[i].r);
		b1=2*(C[i].x-O.x)*(O.y-C[i].y);
		c1=sqr(O.y-C[i].y)-sqr(C[i].r);
		d1=sqrt(b1*b1-4*a1*c1+1e-9);
		k11=(-b1+d1)/(2*a1), k12=(-b1-d1)/(2*a1);
		a2=sqr(O.y-C[i].y)-sqr(C[i].r);
		b2=2*(C[i].y-O.y)*(O.x-C[i].x);
		c2=sqr(O.x-C[i].x)-sqr(C[i].r);
		d2=sqrt(b2*b2-4*a2*c2+1e-9);
		k21=(2*a2)/(-b2+d2), k22=(2*a2)/(-b2-d2);
		if (abs(-b1+d1)>eps && abs(-b1-d1)>eps) k1=k11, k2=k12; else
		if (abs(-b2+d2)>eps && abs(-b2-d2)>eps) k1=k21, k2=k22; else
		if (abs(-b1+d1)>eps && abs(-b2+d2)>eps) k1=k11, k2=k21; else
			k1=k12, k2=k22;
		r1=atan(k1), r2=atan(k2);
		dir.pb(r1), dir.pb(fmod(r1+2*pi,2*pi)-pi);
		dir.pb(r2), dir.pb(fmod(r2+2*pi,2*pi)-pi);
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

template <class ITER>
double S(ITER begin, ITER end)
{
	double ret(0);
	for (int p=1;p<=N;p++)
	{
		DOT A, B;
		int cnt(0);
		for (ITER i=begin;i<end;i++)
		{
			double d(dist(*i,DOT(C[p].x,C[p].y)));
			if (d<C[p].r+eps && d>C[p].r-eps)
				(cnt?B:A)=*i, cnt++;
		}
		if (cnt==2)
		{
			for (ITER i=begin,j=i+1;i<end;i++,j=(j+1<end?j+1:begin))
				if (dist(*i,DOT(C[p].x,C[p].y))>C[p].r+eps || dist(*j,DOT(C[p].x,C[p].y))>C[p].r+eps)
					ret+=0.5*abs(cross(*i-A,*j-A));
			A=A-DOT(C[p].x,C[p].y), B=B-DOT(C[p].x,C[p].y);
			return ret-0.5*acos(dot(A,B)/(dist(A)*dist(B)))*C[p].r*C[p].r+0.5*abs(cross(A,B));
		}
	}
	for (ITER i=begin+1,j=i+1;j<end;i++,j++)
		ret+=0.5*abs(cross(*i-*begin,*j-*begin));
	return ret;
}

inline bool IN(const DOT &O, const TRI &T)
{
	double a(cross(T.a-O,T.b-O)), b(cross(T.b-O,T.c-O)), c(cross(T.c-O,T.a-O));
	return a>-eps && b>-eps && c>-eps || a<eps && b<eps && c<eps;
}

inline void Inter(const DOT &A, const DOT &B, const DOT &P, const DOT &Q)
{
	if (abs((A.y-B.y)*(P.x-Q.x)-(A.x-B.x)*(P.y-Q.y))<eps) return;
	double a1, a2, a0, b1, b2, b0, d0, d1, d2, p, q;
	a1=B.x-A.x, a2=P.x-Q.x, a0=P.x-A.x;
	b1=B.y-A.y, b2=P.y-Q.y, b0=P.y-A.y;
	d0=a1*b2-a2*b1, d1=a0*b2-a2*b0, d2=a1*b0-a0*b1;
	p=d1/d0, q=d2/d0;
	if (p>-eps && p<1+eps && q>-eps && q<1+eps) throw(A+p*(B-A));
}

struct cmp
{
	DOT O;
	cmp(const DOT &_O) : O(_O) {}
	bool operator()(const DOT &A, const DOT &B)
	{
		double t=cross(A-O,B-O);
		return t<-eps || t<eps && dist(O,A)<dist(O,B);
	}
};

inline bool eq2(const DOT &A, const DOT &B)
{
	return abs(A.x-B.x)<eps && abs(A.y-B.y)<eps;
}

void Inter(TRI &A, TRI &B)
{
	vector<DOT> P;
	for (DOT *i=&A.a;i<=&A.c;i++) if (IN(*i,B)) P.pb(*i);
	for (DOT *i=&B.a;i<=&B.c;i++) if (IN(*i,A)) P.pb(*i);
	for (DOT *i=&A.a,*j=i+1;i<=&A.c;i++,j=(j==&A.c?&A.a:j+1))
		for (DOT *p=&B.a,*q=p+1;p<=&B.c;p++,q=(q==&B.c?&B.a:q+1))
			try { Inter(*i,*j,*p,*q); } catch (DOT X) { P.pb(X); }
	if (P.empty()) return;
	int MIN=0;
	for (int i=1;i<P.size();i++)
		if (P[i]<P[MIN]) MIN=i;
	swap(P[0],P[MIN]);
	sort(P.begin()+1,P.end(),cmp(P[0]));
	int n=unique(P.begin(),P.end(),eq2)-P.begin();
	while (P.size()>n) P.pop_back();
	double s=S(P.begin(),P.end());
	RED-=s, GRN-=s, YEL+=s;
}

int main()
{
	freopen("lights.in","r",stdin);
	freopen("lights.out","w",stdout);
	
	//int T;scanf("%d",&T);
	//for (int t=1;t<=T;t++){
	//Rt.clear(), Gt.clear(), CIR=RED=YEL=GRN=0;
	
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
		GRN+=S(&Gt[i].a,&Gt[i].c+1);
	for (int i=0;i<Rt.size();i++)
		for (int j=0;j<Gt.size();j++)
			Inter(Rt[i],Gt[j]);
	
	//printf("Case #%d:\n",t);
	
	printf("%.7f\n%.7f\n%.7f\n%.7f\n",10000-RED-GRN-YEL-CIR,RED,GRN,YEL);
	
	//}
	
	return 0;
}

