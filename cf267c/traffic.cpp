#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=105, maxm=5005;
const double eps=1e-9;

int N, M, m, X[maxm], Y[maxm], Z[maxm];
double f[maxn][maxn], p[maxn];

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		if (X[i]>1 && X[i]<N) f[X[i]][X[i]]++, f[X[i]][Y[i]]--;
		if (Y[i]>1 && Y[i]<N) f[Y[i]][Y[i]]++, f[Y[i]][X[i]]--;
	}
	f[1][N+1]=1, f[1][1]=1;
	f[N][N+1]=0, f[N][N]=1;
	for (int i=1;i<=N;i++)
	{
		if (abs(f[i][i])<eps)
			for (int j=i+1;j<=N;j++) if (abs(f[j][i])>eps)
			{
				for (int k=i;k<=N+1;k++)
					f[i][k]+=f[j][k];
				break;
			}
		for (int j=i+1;j<=N;j++) if (abs(f[j][i])>eps)
		{
			double r(f[j][i]/f[i][i]);
			for (int k=i;k<=N+1;k++)
				f[j][k]-=f[i][k]*r;
		}
	}
	for (int i=N;i;i--) if (abs(f[i][i])>eps)
	{
		p[i]=f[i][N+1];
		for (int j=i+1;j<=N;j++) p[i]-=f[i][j]*p[j];
		p[i]/=f[i][i];
	}
	double rate(1.0/0), ans(0);
	for (int i=1;i<=M;i++)
		rate=min(rate,Z[i]/abs(p[X[i]]-p[Y[i]]));
	for (int i=1;i<=M;i++)
	{
		if (X[i]==1) ans+=p[1]-p[Y[i]];
		if (Y[i]==1) ans+=p[1]-p[X[i]];
	}
	printf("%.7f\n",isfinite(rate)?ans*rate:0);
	for (int i=1;i<=M;i++)
		printf("%.7f\n",isfinite(rate)?(p[X[i]]-p[Y[i]])*rate:0);
	return 0;
}

