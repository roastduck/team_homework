#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int N=256, K=256, mo=777777777;

int f[N+5][N+5][K+5], C[N+5][N+5];

int main()
{
	freopen("lier_list.out","w",stdout);
	for (int i=0;i<=N;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=N;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	}
	f[0][0][0]=1;
	for (int i=1;i<=N;i++)
	{
		f[i][0][0]=1;
		for (int j=1;j<=N;j++)
			for (int k=0;k<=j;k++)
			{
				for (int p=0;p<=k;p++) if (p!=i)
					f[i][j][k]+=(ll)f[i-1][j-p][k-p]*C[j][p]%mo, f[i][j][k]%=mo;
				if (i<=j)
					f[i][j][k]+=(ll)f[i-1][j-i][k]*C[j][i]%mo, f[i][j][k]%=mo;
			}
	}
	for (int i=1;i<=N;i<<=1)
	{
		putchar('{');
		for (int j=0;j<=K;j++)
		{
			printf("%d",f[i][i][j]);
			putchar(j<K?',':'}');
		}
		putchar(',');
		putchar('\n');
	}
	return 0;
}

