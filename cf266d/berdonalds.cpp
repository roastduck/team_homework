#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int,int> PI;
#define fi first
#define se second

const int maxn=205, maxm=40005;

int N, M, A[maxn][maxn], X[maxm], Y[maxm], Z[maxm];
PI f[maxn];

int main()
{
	freopen("berdonalds.in","r",stdin);
	freopen("berdonalds.out","w",stdout);
	scanf("%d%d",&N,&M);
	memset(A,63,sizeof A);
	for (int i=1;i<=M;i++)
	{
		int &x=X[i], &y=Y[i], &z=Z[i];
		scanf("%d%d%d",&x,&y,&z);
		A[x][y]=A[y][x]=z;
	}
	for (int k=1;k<=N;k++)
		for (int i=1;i<N;i++)
			for (int j=i+1;j<=N;j++) if (A[i][k]+A[k][j]<A[i][j])
				A[i][j]=A[j][i]=A[i][k]+A[k][j];
	for (int i=1;i<=N;i++) A[i][i]=0;
	double ans=1.0/0;
	for (int i=1;i<=M;i++)
	{
		int x=X[i], y=Y[i], z=A[x][y];
		for (int j=1;j<=N;j++) f[j]=PI(A[x][j],A[y][j]);
		sort(f+1,f+N+1);
		f[N+1]=PI(1e9,-z);
		f[0]=PI(-z,1e9);
		for (int j=N,k=N+1;j>=0;j--) if (f[j].se>f[k].se)
		{
			double x=(f[k].se+z-f[j].fi)*0.5;
			ans=min(ans,min(f[j].se+z-x,x+f[j].fi)+max(0.0,max(-x,x-z)));
			k=j;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}

