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

struct BLOCK
{
	int _y, x, y;
	BLOCK(int __y=0, int _x=0, int _y=0) : _y(__y), x(_x), y(_y) {}
};

inline bool operator<(const BLOCK &a, const BLOCK &b)
{
	return a._y < b._y;
}

const int maxn=1005;

int N, u, v, n, m, X[maxn][maxn], Y[maxn][maxn], H[maxn][maxn], YY[maxn*maxn], f[maxn*maxn*2];
long long ans;
BLOCK A[maxn*maxn];

#define pos(x,y) (((x)+(y))|((x)!=(y)))

void Ins(int l, int r, int ql, int qr, int v)
{
	int now(pos(l,r));
	if (f[now]>=v) return;
	if (l==ql && r==qr)
	{
		f[now]=v;
		return;
	}
	int mid((l+r)>>1), son1(pos(l,mid)), son2(pos(mid+1,r));
	if (qr<=mid) Ins(l,mid,ql,qr,v); else
	if (ql>mid) Ins(mid+1,r,ql,qr,v); else
		Ins(l,mid,ql,mid,v), Ins(mid+1,r,mid+1,qr,v);
	f[now]=max(f[now],min(f[son1],f[son2]));
}

int Find(int l, int r, int ql, int qr)
{
	int now(pos(l,r));
	if (l==ql && r==qr) return f[now];
	int mid((l+r)>>1);
	if (qr<=mid) return max(f[now],Find(l,mid,ql,qr));
	if (ql>mid) return max(f[now],Find(mid+1,r,ql,qr));
	return max(f[now],min(Find(l,mid,ql,mid),Find(mid+1,r,mid+1,qr)));
}

int main()
{
	freopen("cubes.in","r",stdin);
	freopen("cubes.out","w",stdout);
	scanf("%d%d%d",&N,&u,&v);
	for (int i=0;i<=N;i++)
		for (int j=0;j<=N;j++)
		{
			X[i][j]=i*u+j*v;
			Y[i][j]=j*u-i*v;
			YY[n++]=Y[i][j];
		}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			READ(H[i][j]);
			A[m++]=BLOCK(X[i][j],i,j);
		}
	sort(A,A+m);
	sort(YY,YY+n);
	n=unique(YY,YY+n)-YY;
	for (int i=0;i<m;i++)
	{
		int l, r, x(A[i].x), y(A[i].y);
		l=min(min(Y[x][y],Y[x][y+1]),min(Y[x+1][y],Y[x+1][y+1]));
		r=max(max(Y[x][y],Y[x][y+1]),max(Y[x+1][y],Y[x+1][y+1]));
		l=lower_bound(YY,YY+n,l)-YY;
		r=lower_bound(YY,YY+n,r)-YY;
		ans+=max(0,H[x][y]-Find(0,n-2,l,r-1));
		Ins(0,n-2,l,r-1,H[x][y]);
	}
	printf("%I64d\n",ans);
	return 0;
}

