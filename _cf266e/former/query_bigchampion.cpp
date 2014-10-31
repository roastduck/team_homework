#include <cstdio>
using namespace std;
typedef long long ll;
const int N=100004,M=400004,P=1000000007;
int n,m,a[N],c[6][6],base[N][6],set[M],sum[M][6],ql,qr,qv,qk;
int calc(int o,int k,int x)
{
	ll ret=sum[o][k],t=1;
	for (int i=1;i<=k;i++)
	{
		t=t*x%P;
		ret=(ret+t*sum[o][k-i]%P*(ll)c[k][i])%P;
	}
	return (int)ret;
}
void build(int o,int l,int r)
{
	set[o]=-1;
	if (l==r)
	{
		for (int i=0;i<6;i++) sum[o][i]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(o*2,l,m); build(o*2+1,m+1,r);
	for (int i=0;i<6;i++) sum[o][i]=(sum[o*2][i]+calc(o*2+1,i,m-l+1))%P;
}
void setv(int o,int l,int r,int v)
{
	set[o]=v;
	for (int i=0;i<6;i++) sum[o][i]=(ll)base[r-l+1][i]*v%P;
}
void down(int o,int l,int r)
{
	if (set[o]<0) return;
	int m=(l+r)/2;
	setv(o*2,l,m,set[o]);
	setv(o*2+1,m+1,r,set[o]);
	set[o]=-1;
}
void Set(int o,int l,int r)
{
	if ((ql<=l)&&(r<=qr)) {setv(o,l,r,qv); return;}
	int m=(l+r)/2; down(o,l,r);
	if (ql<=m) Set(o*2,l,m);
	if (m<qr) Set(o*2+1,m+1,r);
	for (int i=0;i<6;i++) sum[o][i]=(sum[o*2][i]+calc(o*2+1,i,m-l+1))%P;
}
int query(int o,int l,int r)
{
	if ((ql<=l)&&(r<=qr)) return calc(o,qk,l-ql);
	int m=(l+r)/2,ret=0; down(o,l,r);
	if (ql<=m) ret+=query(o*2,l,m);
	if (m<qr) ret+=query(o*2+1,m+1,r);
	return ret%P;
}
int main()
{
	int i,j; scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	c[1][0]=c[1][1]=1;
	for (i=2;i<6;i++)
	{
		c[i][0]=c[i][i]=1;
		for (j=1;j<i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	build(1,1,n);
	for (i=1;i<=n;i++)
	    for (j=0;j<6;j++)
	    {
	    	base[i][j]=1;
	    	for (int k=1;k<=j;k++) base[i][j]=(ll)base[i][j]*i%P;
	    	if (i>1) base[i][j]=(base[i][j]+base[i-1][j])%P;
	    }
	for (i=1;i<=m;i++)
	{
		char op[2];
		scanf("%s%d%d",op,&ql,&qr);
		if (op[0]=='?') scanf("%d",&qk),printf("%d\n",query(1,1,n));
		else scanf("%d",&qv),Set(1,1,n);
	}
	return 0;
}

