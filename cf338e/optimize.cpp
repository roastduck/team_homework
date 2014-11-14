#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=150005;

int N, M, H, B[maxn], I[maxn], f[maxn<<1], g[maxn<<1];

#define pos(l,r) (((l)+(r))|((l)!=(r)))

void Ins(int l, int r, int ql, int qr, int v)
{
	int now(pos(l,r));
	if (l==ql && r==qr)
	{
		g[now]+=v;
		return;
	}
	int mid((l+r)>>1), son1(pos(l,mid)), son2(pos(mid+1,r));
	if (qr<=mid) Ins(l,mid,ql,qr,v); else
	if (ql>mid) Ins(mid+1,r,ql,qr,v); else
		Ins(l,mid,ql,mid,v), Ins(mid+1,r,mid+1,qr,v);
	f[now]=min(f[son1]+g[son1],f[son2]+g[son2]);
}

int main()
{
	freopen("optimize.in","r",stdin);
	freopen("optimize.out","w",stdout);
	scanf("%d%d%d",&N,&M,&H);
	for (int i=0;i<M;i++)
	{
		scanf("%d",&B[i]);
		Ins(0,M-1,i,i,-i);
	}
	sort(B,B+M);
	int ans(0);
	for (int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		I[i]=lower_bound(B,B+M,H-x)-B;
		if (i>=M && I[i-M]<M) Ins(0,M-1,I[i-M],M-1,-1);
		if (I[i]<M) Ins(0,M-1,I[i],M-1,1);
		if (f[pos(0,M-1)]+g[pos(0,M-1)]>0) ans++;
	}
	printf("%d\n",ans);
	return 0;
}

