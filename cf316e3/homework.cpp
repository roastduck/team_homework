#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> PI;
#define fi first
#define se second

const int maxn=200005, mo=1e9;

inline PI operator+(const PI &a, const PI &b)
{
	return PI((a.fi+b.fi)%mo,(a.se+b.se)%mo);
}

int N, M, fib[maxn], sum[maxn], g[maxn<<1];
PI f[maxn<<1];

inline PI Move(const PI &a, int off)
{
	if (!off)
		return a;
	if (off==1)
		return PI(a.se,(a.fi+a.se)%mo);
	return PI(
			((ll)a.fi*fib[off-2]+(ll)a.se*fib[off-1])%mo,
			((ll)a.fi*fib[off-1]+(ll)a.se*fib[off])%mo
		    );
}

#define pos(l,r) (((l)+(r))|((l)!=(r)))

void Add(int l, int r, int ql, int qr, int d)
{
	PI &now=f[pos(l,r)];
	now.fi+=(ll)(sum[qr-l]-(ql>l?sum[ql-l-1]:0))*d%mo, now.fi%=mo;
	now.se+=(ll)(sum[qr-l+1]-sum[ql-l])*d%mo, now.se%=mo;
	if (l==ql && r==qr)
	{
		g[pos(l,r)]+=d, g[pos(l,r)]%=mo;
		return;
	}
	int mid((l+r)>>1);
	if (qr<=mid) Add(l,mid,ql,qr,d); else
	if (ql>mid) Add(mid+1,r,ql,qr,d); else
		Add(l,mid,ql,mid,d), Add(mid+1,r,mid+1,qr,d);
}

PI Find(int l, int r, int ql, int qr)
{
	PI &now=f[pos(l,r)];
	if (l==ql && r==qr) return now;
	int mid((l+r)>>1);
	if (g[pos(l,r)])
	{
		Add(l,mid,l,mid,g[pos(l,r)]);
		Add(mid+1,r,mid+1,r,g[pos(l,r)]);
		g[pos(l,r)]=0;
	}
	if (qr<=mid) return Find(l,mid,ql,qr);
	if (ql>mid) return Find(mid+1,r,ql,qr);
	return Find(l,mid,ql,mid)+Move(Find(mid+1,r,mid+1,qr),mid-ql+1);
}

int main()
{
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d%d",&N,&M);
	fib[0]=fib[1]=1;
	for (int i=2;i<=N;i++)
		fib[i]=(fib[i-2]+fib[i-1])%mo;
	sum[0]=1;
	for (int i=1;i<=N;i++)
		sum[i]=(sum[i-1]+fib[i])%mo;
	for (int i=1;i<=N;i++)
	{
		int x;
		scanf("%d",&x);
		Add(1,N,i,i,x);
	}
	for (int i=0;i<M;i++)
	{
		int type, l, r, x, v;
		scanf("%d",&type);
		switch (type)
		{
			case 1:
				scanf("%d%d",&x,&v);
				Add(1,N,x,x,v-Find(1,N,x,x).fi);
				break;
			case 2:
				scanf("%d%d",&l,&r);
				printf("%d\n",(Find(1,N,l,r).fi+mo)%mo);
				break;
			case 3:
				scanf("%d%d%d",&l,&r,&v);
				Add(1,N,l,r,v);
		}
	}
	return 0;
}

