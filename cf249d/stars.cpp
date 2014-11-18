#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#include<cmath>
using namespace std;

const int maxn=100005;

typedef pair<double,double> PIDD;
typedef pair<double,int> PIDI;
#define fi first
#define se second

double cross(double x1, double y1, double x2, double y2)
{
	return x1*y2-x2*y1;
}

double dist(double x, double y)
{
	return sqrt(x*x+y*y);
}

bool yup(const PIDD &a, const PIDD &b)
{
	return a.se<b.se;
}

bool cmp2(const PIDI &a, const PIDI &b)
{
	if (abs(a.fi-b.fi)<1e-9) return a.se>b.se;
	return a.fi<b.fi;
}

int N, n, ycnt, f[maxn], ans;
PIDD a[maxn];
PIDI b[maxn];

void Ins(int x, int y)
{
	while (x<=ycnt)
	{
		f[x]=max(f[x],y);
		x+=(x & (-x));
	}
}

int Find(int x)
{
	int ret(0);
	while (x)
	{
		ret=max(ret,f[x]);
		x-=(x & (-x));
	}
	return ret;
}

int main()
{
	scanf("%d",&N);
	int x1, y1, x2, y2;
	scanf("%d/%d%d/%d",&y1,&x1,&y2,&x2);
	double tmp1(1/dist(x1,y1)), tmp2(1/dist(x2,y2));
	for (int i=1;i<=N;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		a[++n]=make_pair(cross(x,y,x2,y2)*tmp2,cross(x1,y1,x,y)*tmp1);
		if (a[n].fi<1e-9 || a[n].se<1e-9) n--; 
	}
	sort(a+1,a+n+1,yup);
	for (int i=1;i<=n;i++)
	{
		if (i==1 || a[i].se-a[i-1].se>1e-9) ycnt++;
		b[i]=make_pair(a[i].fi,ycnt);
	}
	sort(b+1,b+n+1,cmp2);
	memset(f,128,sizeof f);
	f[0]=0;
	for (int i=1;i<=n;i++)
	{
		int tmp(Find(b[i].se-1));
		ans=max(ans,tmp+1);
		Ins(b[i].se,tmp+1);
	}
	printf("%d\n",ans);
	return 0;
}

