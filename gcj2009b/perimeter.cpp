#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100005;

typedef pair<int,int> PI;
#define fi first
#define se second

int N;
double ans;
PI A[maxn], B[maxn], *C[maxn], *D[maxn];

inline double dist(const PI &A, const PI &B)
{
	return sqrt((long long)(A.fi-B.fi)*(A.fi-B.fi)+(long long)(A.se-B.se)*(A.se-B.se));
}

void Work(int l, int r)
{
	if (l==r) return;
	int mid((l+r)>>1);
	double vmid(A[mid].fi), umid(A[mid+1].fi);
	// how about vmid<umid?
	Work(l,mid);
	Work(mid+1,r);
	int n(0), Cst(1), Cen(0), Dst(1), Den(0);
	for (int i=l, j=mid+1; i<=mid || j<=r;)
	{
		B[++n]=(j>r || i<=mid && A[i].se<A[j].se? A[i++]: A[j++]);
		while (Cst<=Cen && C[Cst]->se<B[n].se-ans*0.5) Cst++;
		while (Dst<=Den && D[Dst]->se<B[n].se-ans*0.5) Dst++;
		if (B[n].fi<=vmid)
			for (int p=Dst;p<Den;p++)
				for (int q=p+1;q<=Den;q++)
					ans=min(ans,dist(*D[p],*D[q])+dist(*D[p],B[n])+dist(*D[q],B[n]));
		else
			for (int p=Cst;p<Cen;p++)
				for (int q=p+1;q<=Cen;q++)
					ans=min(ans,dist(*C[p],*C[q])+dist(*C[p],B[n])+dist(*C[q],B[n]));
		for (int p=Cst;p<=Cen;p++)
			for (int q=Dst;q<=Den;q++) if (C[p]!=D[q])
				ans=min(ans,dist(*C[p],*D[q])+dist(*C[p],B[n])+dist(*D[q],B[n]));
		if (B[n].fi<=vmid && B[n].fi>vmid-ans*0.5) C[++Cen]=&B[n];
		if (B[n].fi>=umid && B[n].fi<umid+ans*0.5) D[++Den]=&B[n];
	}
	copy(B+1,B+n+1,A+l);
}

int main()
{
	freopen("perimeter.in","r",stdin);
	freopen("perimeter.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		ans=1.0/0;
		scanf("%d",&N);
		for (int i=1;i<=N;i++) scanf("%d%d",&A[i].fi,&A[i].se);
		sort(A+1,A+N+1);
		Work(1,N);
		printf("Case #%d: %.11f\n",tt,ans);
	}
	return 0;
}

