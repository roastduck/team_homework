#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

const int maxn=1e5+5, inf=0x7fffffff;

typedef long long ll;

struct CITY { int x, y, id; } A[maxn];

inline bool cmpx(const CITY &X, const CITY &Y)
{
	return X.x<Y.x;
}

inline bool cmpy(const CITY &X, const CITY &Y)
{
	return X.y<Y.y;	
}

int N, pos[maxn], X[maxn], Y[maxn];
ll sx0, sx1, sy0, sy1;

struct QUA
{
	int cx, cy;
	const int &(*xx)(const int&,const int&), &(*yy)(const int&,const int&);
	QUA(bool x, bool y) : 
		cx(x?inf:-inf), cy(y?inf:-inf),
		xx(x?min<int>:max<int>), yy(y?min<int>:max<int>)
		{}
	void upd(int id)
	{
		cx=xx(X[id],cx), cy=yy(Y[id],cy);
	}
};

const int UP=1, DN=2, RI=4, LE=8;

int main()
{
	freopen("evil.in","r",stdin);
	freopen("evil.out","w",stdout);
	scanf("%d",&N);
	for (int i=0;i<N;i++)
	{
		scanf("%d%d",&X[i],&Y[i]);
		A[i].x=X[i], A[i].y=Y[i], A[i].id=i;
	}
	int mx, my;
	nth_element(A,A+N/2,A+N,cmpx);
	mx=A[N/2].id;
	for (int i=0;i*2<N-1;i++) pos[A[i].id]|=LE;
	for (int i=N-1;i*2>N-1;i--) pos[A[i].id]|=RI;
	nth_element(A,A+N/2,A+N,cmpy);
	my=A[N/2].id;
	for (int i=0;i*2<N-1;i++) pos[A[i].id]|=DN;
	for (int i=N-1;i*2>N-1;i--) pos[A[i].id]|=UP;
	QUA I(1,1), II(0,1), III(0,0), IV(1,0);
	for (int i=0;i<N;i++)
	{
		if ((pos[i]&UP) && (pos[i]&RI)) I.upd(i);
		if ((pos[i]&UP) && (pos[i]&LE)) II.upd(i);
		if ((pos[i]&DN) && (pos[i]&LE)) III.upd(i);
		if ((pos[i]&DN) && (pos[i]&RI)) IV.upd(i);
		if (pos[i]&LE) sx0+=X[i];
		if (pos[i]&RI) sx1+=X[i];
		if (pos[i]&DN) sy0+=Y[i];
		if (pos[i]&UP) sy1+=Y[i];
	}
	ll base=2*(sx1-sx0+sy1-sy0);
	if (I.cy==inf || II.cy==inf || N%2 && mx!=my)
		return printf("%I64d\n",base), 0;
	if (N%2==0)
		return printf("%I64d\n",base+2ll*max(
					max(II.cx,III.cx)-min(I.cx,IV.cx),
					max(III.cy,IV.cy)-min(I.cy,II.cy)
					)), 0;
	printf("%I64d\n",base+2ll*max(
				max(max(-I.cx,-IV.cx)+X[mx],max(II.cx,III.cx)-X[mx]),
				max(max(-I.cy,-II.cy)+Y[my],max(III.cy,IV.cy)-Y[my])
				));
	return 0;
}

