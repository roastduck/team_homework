#include<cmath>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=110;
const double eps=1e-9;

struct Four
{
	double a, b, c, d, _;
	Four() {}
	Four(double _a, double _b, double _c, double _d) : a(_a), b(_b), c(_c), d(_d), _(atan2(d,c)) {}
};

typedef pair<double,double> PI;
#define fi first
#define se second

inline bool operator<(const Four &a, const Four &b)
{
	return a._<b._;
}

inline double cross(double x1, double y1, double x2, double y2)
{
	return x1*y2-x2*y1;
}

inline PI xing(const Four &u, const Four &v)
{
	double A1=-u.c, A2=v.c, A3=u.a-v.a;
	double B1=-u.d, B2=v.d, B3=u.b-v.b;
	double k=(A3*B2-A2*B3)/(A1*B2-A2*B1);
	return PI(u.a+k*u.c,u.b+k*u.d);
}

inline bool TTL(const PI &X, const Four &A)
{
	return cross(A.c,A.d,X.fi-A.a,X.se-A.b)>-eps;
}

inline bool in180(const Four &A, const Four &B)
{
	return cross(A.c,A.d,B.c,B.d)>eps;
}

inline double sqr(double x) { return x*x; }

typedef map< PI,vector<Four> > MAP;

int N, n, X[maxn], Y[maxn];
Four E[maxn], *L[maxn];
MAP V;

int main()
{
	freopen("hole.in","r",stdin);
	freopen("hole.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d%d",&X[i],&Y[i]);
	double ans(0);
	for (int p=1;p<=N;p++)
	{
		n=0;
		for (int j=1;j<=N;j++) if (p!=j)
			E[++n]=Four((X[p]+X[j])*0.5,(Y[p]+Y[j])*0.5,Y[p]-Y[j],X[j]-X[p]);
		E[++n]=Four(1e5,0,0,1);
		E[++n]=Four(0,1e5,-1,0);
		E[++n]=Four(-1e5,0,0,-1);
		E[++n]=Four(0,-1e5,1,0);
		sort(E+1,E+n+1);
		int st(1), en(0);
		for (int i=1,j=1;i<=n;i=j)
		{
			Four *X=E+i;
			for (j++; j<=n && cross(X->c,X->d,E[j].c,E[j].d)<eps; j++)
				if (TTL(PI(E[j].a,E[j].b),*X))
					X=E+j;
			while (en>st && in180(*L[en-1],*X) && TTL(xing(*L[en-1],*X),*L[en])) en--;
			while (en>st && in180(*X,*L[st+1]) && TTL(xing(*L[st+1],*X),*L[st])) st++;
			if (en<=st || !in180(*L[en],*L[st]) || !TTL(xing(*L[en],*L[st]),*X))
				L[++en]=X;
		}
		for (int i=st;i<=en;i++)
		{
			int j(i<en?i+1:st);
			if (abs(L[i]->a)<5e4 && abs(L[i]->b)<5e4 && abs(L[j]->a)<5e4 && abs(L[j]->b)<5e4)
			{
				PI XX=xing(*L[i],*L[j]);
				XX.fi=round(XX.fi*1e9)*1e-9, XX.se=round(XX.se*1e9)*1e-9;
				V[XX].push_back(Four(XX.fi,XX.se,X[p]-XX.fi,Y[p]-XX.se));
			}
		}
	}
	for (MAP::iterator i=V.begin(); i!=V.end(); i++)
	{
		sort(i->se.begin(),i->se.end());
		bool ok(true);
		for (vector<Four>::iterator j=i->se.begin(); j<i->se.end() && ok; j++)
		{
			vector<Four>::iterator k(j<i->se.end()-1?j+1:i->se.begin());
			if (!in180(*j,*k)) ok=false;
		}
		if (ok)
			ans=max(ans,sqrt(sqr(i->se.front().c)+sqr(i->se.front().d)));
	}
	if (!ans)
		puts("-1");
	else
		printf("%.6f\n",ans);
	return 0;
}

