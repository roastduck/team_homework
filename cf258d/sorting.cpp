#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1005;

int N, M, A[maxn];
double P[maxn][maxn];

int main()
{
	freopen("sorting.in","r",stdin);
	freopen("sorting.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++) scanf("%d",&A[i]);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			P[i][j]=A[i]>A[j];
	while (M--)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		P[x][y]=P[y][x]=0.5;
		for (int i=1;i<=N;i++) if (i!=x && i!=y)
		{
			P[i][x]=P[i][y]=(P[i][x]+P[i][y])*0.5;
			P[x][i]=P[y][i]=(P[x][i]+P[y][i])*0.5;
		}
	}
	double ans(0);
	for (int i=1;i<N;i++)
		for (int j=i+1;j<=N;j++)
			ans+=P[i][j];
	printf("%.8f\n",ans);
	return 0;
}

