#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int mo=1000000007;

int N, M, K, A[15][15], f[15][15];

int Dfs(int x, int y, int tank)
{
	if (y>M) x++, y=1;
	if (x>N) return 1;
	int t(f[x-1][y]|f[x][y-1]), mem=-1, ret=0;
	if (A[x][y])
	{
		if (!(t&(1<<A[x][y]>>1)))
		{
			f[x][y]=(t|(1<<A[x][y]>>1));
			if (!(tank&(1<<A[x][y]>>1)))
			{
				if (!~mem) mem=Dfs(x,y+1,tank|(1<<A[x][y]>>1));
				ret+=mem, ret%=mo;
			} else
				ret+=Dfs(x,y+1,tank), ret%=mo;
		}
	}
	else
	{
		int p(~t);
		for (int k=p&-p;k<(1<<K);p^=k,k=(p&-p))
		{
			f[x][y]=(t|k);
			if (!(tank&k))
			{
				if (!~mem) mem=Dfs(x,y+1,tank|k);
				ret+=mem, ret%=mo;
			} else
				ret+=Dfs(x,y+1,tank), ret%=mo;
		}
	}
	return ret;
}

int main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	if (N+M-1>K) return puts("0"), 0;
	int al=0;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			scanf("%d",&A[i][j]);
			if (A[i][j]) al|=(1<<A[i][j]>>1);
		}
	printf("%d\n",Dfs(1,1,al));
	return 0;
}

