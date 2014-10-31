#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5+5, mo=1e9+7;

typedef long long ll;

const int C[7][7]=
{
	{1,	0,	0,	0,	0,	0,	0},
	{1,	1,	0,	0,	0,	0,	0},
	{1,	2,	1,	0,	0,	0,	0},
	{1,	3,	3,	1,	0,	0,	0},
	{1,	4,	6,	4,	1,	0,	0},
	{1,	5,	10,	10,	5,	1,	0},
	{1,	6,	15,	20,	15,	6,	1}
};

const int rev[7]=
{
	0, 1, 500000004, 333333336, 250000002, 400000003, 166666668
};

struct NODE
{
	int val[6], pas;
	NODE() : pas(-1) { memset(val,0,sizeof val); }
};

int N, M, coe[maxn][6];
NODE f[maxn<<1];

#define pos(l,r) (((l)+(r))|((l)!=(r)))

void Ins(int l, int r, int ql, int qr, int x)
{
	int mid((l+r)>>1), now(pos(l,r)), son1(pos(l,mid)), son2(pos(mid+1,r));
	if (l==ql && r==qr)
	{
		for (int i=0;i<=5;i++)
			f[now].val[i]=((ll)coe[r][i]-coe[l-1][i]+mo)%mo*x%mo;
		f[now].pas=x;
		return;
	}
	if (~f[now].pas)
	{
		Ins(l,mid,l,mid,f[now].pas);
		Ins(mid+1,r,mid+1,r,f[now].pas);
		f[now].pas=-1;
	}
	if (qr<=mid) Ins(l,mid,ql,qr,x); else
	if (ql>mid) Ins(mid+1,r,ql,qr,x); else
		Ins(l,mid,ql,mid,x), Ins(mid+1,r,mid+1,qr,x);
	for (int i=0;i<=5;i++)
		f[now].val[i]=(f[son1].val[i]+f[son2].val[i])%mo;
}

int Find(int l, int r, int ql, int qr, int L, int x)
{
	int mid((l+r)>>1), now(pos(l,r));
	if (l==ql && r==qr)
	{
		ll ret(0), p(1);
		for (int i=x,k=1;i>=0;i--,k=-k,p=p*L%mo)
			ret+=(ll)k*C[x][i]*f[now].val[i]%mo*p%mo;
		return (ret%mo+mo)%mo;
	}
	if (~f[now].pas)
	{
		Ins(l,mid,l,mid,f[now].pas);
		Ins(mid+1,r,mid+1,r,f[now].pas);
		f[now].pas=-1;
	}
	if (qr<=mid) return Find(l,mid,ql,qr,L,x);
	if (ql>mid) return Find(mid+1,r,ql,qr,L,x);
	return (Find(l,mid,ql,mid,L,x)+Find(mid+1,r,mid+1,qr,L,x))%mo;
}

int main()
{
	//freopen("query.in","r",stdin);
	//freopen("query.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		ll k(1);
		for (int j=0;j<=5;j++,k=k*i%mo)
			coe[i][j]=(coe[i-1][j]+k)%mo;
	}
	for (int i=1;i<=N;i++)
	{
		int x;
		scanf("%d",&x);
		Ins(1,N,i,i,x);
	}
	for (int i=1;i<=M;i++)
	{
		char type;
		int l, r, x;
		scanf(" %c%d%d%d",&type,&l,&r,&x);
		if (type=='=')
			Ins(1,N,l,r,x);
		else
			printf("%d\n",Find(1,N,l,r,l-1,x));
	}
	return 0;
}

