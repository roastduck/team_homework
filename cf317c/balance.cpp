#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=305, maxe=100005, maxa=180005;

int N, V, E, m, n, A[maxn], B[maxn], a[maxn], b[maxe], c[maxe], X[maxa], Y[maxa], Z[maxa], fa[maxn], flag[maxn];

inline void push(int x, int y, int z)
{
	A[x]-=z, A[y]+=z;
	n++, X[n]=x, Y[n]=y, Z[n]=z;
}

void f(int x, int y, int d)
{
	int pre(min(d,A[fa[y]]));
	if (pre>0) push(fa[y],y,pre);
	if (fa[y]!=x) f(x,fa[y],d);
	if (pre<d) push(fa[y],y,d-pre);
}

void Dfs(int x, int r, int t)
{
	flag[x]=t;
	int d(min(A[r]-B[r],B[x]-A[x]));
	if (d>0) f(r,x,d);
	for (int i=a[x];i;i=c[i]) if (flag[b[i]]!=t)
		fa[b[i]]=x, Dfs(b[i],r,t);
}

int main()
{
	freopen("balance.in","r",stdin);
	freopen("balance.out","w",stdout);
	scanf("%d%d%d",&N,&V,&E);
	for (int i=1;i<=N;i++) scanf("%d",&A[i]);
	for (int i=1;i<=N;i++) scanf("%d",&B[i]);
	for (int i=1;i<=E;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		m++, b[m]=y, c[m]=a[x], a[x]=m;
		m++, b[m]=x, c[m]=a[y], a[y]=m;
	}
	for (int i=1;i<=N;i++)
		for (int j=a[i];j;j=c[j])
			flag[i]=i, fa[b[j]]=i, Dfs(b[j],i,i);
	for (int i=1;i<=N;i++) if (A[i]!=B[i])
		return puts("NO"), 0;
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%d %d %d\n",X[i],Y[i],Z[i]);
	return 0;
}

