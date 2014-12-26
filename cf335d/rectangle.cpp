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

const int maxn=1e5+5, maxm=3005;

int N, X1[maxn], Y1[maxn], X2[maxn], Y2[maxn], A[maxm][maxm], B[maxm][maxm], C[maxm][maxm];

int main()
{
	freopen("rectangle.in","r",stdin);
	freopen("rectangle.out","w",stdout);
	READ(N);
	int l(3000), r(0), d(3000), u(0);
	for (int i=1;i<=N;i++)
	{
		int &x1=X1[i], &y1=Y1[i], &x2=X2[i], &y2=Y2[i];
		READ(x1), READ(y1), READ(x2), READ(y2);
		l=min(l,x1), r=max(r,x2);
		d=min(d,y1), u=max(u,y2);
		for (int i=x1+1;i<=x2;i++)
			A[i][y1]=A[i][y2]=1;
		for (int i=y1+1;i<=y2;i++)
			B[x1][i]=B[x2][i]=1;
		for (int i=x1+1;i<=x2;i++)
			for (int j=y1+1;j<=y2;j++)
				C[i][j]=1;
	}
	for (int i=l;i<=r;i++)
		for (int j=d;j<=u;j++)
		{
			A[i][j]+=i?A[i-1][j]:0;
			B[i][j]+=j?B[i][j-1]:0;
			C[i][j]+=(i?C[i-1][j]:0)+(j?C[i][j-1]:0)-(i&&j?C[i-1][j-1]:0);
		}
	bool YES(false);
	int a1, b1, a2, b2;
	for (int i=1; i<=N && !YES; i++)
	{
		int &x1=X1[i], &y1=Y1[i], &x2=X2[i], &y2=Y2[i];
		for (int j=max(x2-x1,y2-y1); !YES && x1+j<=r && y1+j<=u; j++)
		{
			if (A[x1+j][y1]-A[x1][y1]<j) break;
			if (B[x1][y1+j]-B[x1][y1]<j) break;
			if (A[x1+j][y1+j]-A[x1][y1+j]<j) continue;
			if (B[x1+j][y1+j]-B[x1+j][y1]<j) continue;
			if (C[x1+j][y1+j]-C[x1][y1+j]-C[x1+j][y1]+C[x1][y1]==j*j)
			{
				YES=true;
				a1=x1, b1=y1, a2=x1+j, b2=y1+j;
			}
		}
	}
	if (!YES) return puts("NO"), 0;
	int k(0);
	static int ans[maxn];
	for (int i=1;i<=N;i++)
		if (X1[i]>=a1 && X2[i]<=a2 && Y1[i]>=b1 && Y2[i]<=b2)
			ans[++k]=i;
	printf("YES %d\n",k);
	for (int i=1;i<k;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[k]);
	return 0;
}

