#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn=1005, mo=1e9+7;

int N, K, fact[maxn], C[maxn][maxn], f[maxn][maxn][2][2], g[maxn];

int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d%d",&N,&K);
	fact[0]=1;
	for (int i=1;i<=N;i++)
		fact[i]=(ll)fact[i-1]*i%mo;
	for (int i=0;i<=N;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	}
	f[0][0][1][0]=1;
	for (int i=1;i<=N;i++)
		for (int j=0;j<=i;j++)
		{
			f[i][j][0][0]=
				((ll)f[i-1][j][0][0]+f[i-1][j][1][0]+
				 (j?f[i-1][j-1][0][0]:0))%mo;
			f[i][j][0][1]=
				(j?(f[i-1][j-1][0][0]+f[i-1][j-1][1][0])%mo:0);
			f[i][j][1][0]=
				((ll)f[i-1][j][0][1]+f[i-1][j][1][1]+
				 (j?f[i-1][j-1][0][1]:0))%mo;
			f[i][j][1][1]=
				(j?(f[i-1][j-1][0][1]+f[i-1][j-1][1][1])%mo:0);
		}
	for (int i=N;i>=K;i--)
	{
		g[i]=((ll)f[N][i][0][0]+f[N][i][1][0])%mo*fact[N-i]%mo;
		for (int j=i+1;j<=N;j++)
			g[i]-=(ll)g[j]*C[j][i]%mo, g[i]=(g[i]+mo)%mo;
	}
	printf("%d\n",g[K]);
	return 0;
}

