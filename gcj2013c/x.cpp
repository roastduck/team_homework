#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long double ld;

const int maxn=10005;
const ld pi=acosl(-1);

int N, X[maxn], Y[maxn];

struct res_t
{
	ld x0, y0, x1, y1;

	res_t() {}

	res_t(ld alpha, ld mxl, ld mxr, ld myl, ld myr)
	{
		ld _x0((mxl+mxr)*0.5), _y0((myl+myr)*0.5);
		ld _x1(_x0+1e8), _y1(_y0);
		x0=_x0*cosl(-alpha)-_y0*sinl(-alpha);
		y0=_y0*cosl(-alpha)+_x0*sinl(-alpha);
		x1=_x1*cosl(-alpha)-_y1*sinl(-alpha);
		y1=_y1*cosl(-alpha)+_x1*sinl(-alpha);
	}
} ans;

struct DOT
{
	ld x, y;
	DOT() {}
	DOT(ld _x, ld _y) : x(_x), y(_y) {}
};

inline bool cmpx(const DOT &a, const DOT &b)
{
	return a.x<b.x;
}

inline bool cmpy(const DOT &a, const DOT &b)
{
	return a.y<b.y;
}

int Calc(ld alpha)
{
	static DOT P[maxn];
	for (int i=1;i<=4*N;i++)
		P[i]=DOT(
				X[i]*cosl(alpha)-Y[i]*sinl(alpha),
				Y[i]*cosl(alpha)+X[i]*sinl(alpha)
			   );
	ld mxl, mxr, myl, myr;
	nth_element(P+1,P+2*N,P+4*N+1,cmpx), mxl=P[2*N].x;
	nth_element(P+1,P+2*N+1,P+4*N+1,cmpx), mxr=P[2*N+1].x;
	nth_element(P+1,P+2*N,P+4*N+1,cmpy), myl=P[2*N].y;
	nth_element(P+1,P+2*N+1,P+4*N+1,cmpy), myr=P[2*N+1].y;
	int cnt(0);
	for (int i=1;i<=2*N;i++) cnt+=(P[i].x<=mxl?1 : -1);
	ans=res_t(alpha,mxl,mxr,myl,myr);
	return cnt;
}

int main()
{
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		scanf("%d",&N);
		for (int i=1;i<=4*N;i++)
			scanf("%d%d",&X[i],&Y[i]);
		ld l(rand()), r(l+0.5*pi);
		if (Calc(l)>0)
			l+=0.5*pi, r+=0.5*pi;
		while (true)
		{
			ld mid((l+r)*0.5);
			int vdt=Calc(mid);
			if (!vdt) break;
			if (vdt>0) r=mid;
			if (vdt<0) l=mid;
		}
		printf("Case #%d: ",t);
		printf(
				"%.9f %.9f %.9f %.9f\n",
				(double) ans.x0, (double) ans.y0,
				(double) ans.x1, (double) ans.y1
			 );
	}
	return 0;
}

