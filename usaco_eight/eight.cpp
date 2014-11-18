#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=305;
int N, Left[maxn][maxn], f[maxn][maxn][maxn], g[2][maxn][maxn];
long long ans(-1);
char map[maxn][maxn];

int main()
{
	scanf("%d",&N);
	memset(f,128,sizeof f);
	memset(g,128,sizeof g);
	for (int i=1;i<=N;i++) scanf("%s",map[i]+1);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++)
			if (map[i][j]=='.' && map[i][j-1]=='.') Left[i][j]=Left[i][j-1]; else Left[i][j]=j;
	for (int i=3;i<=N;i++)
		for (int len=2;len<N;len++)
			for (int l=1,r=len+1;r<=N;l++,r++) if (map[i][l]=='.' && map[i][r]=='.')
			{
				if (Left[i-2][r]<=l && map[i-1][l]=='.' && map[i-1][r]=='.')
					f[i][l][r]=r-l-1;
				else
					f[i][l][r]=-0x7f7f7f7f;
				f[i][l][r]=max(f[i][l][r],f[i-1][l][r]+r-l-1);
			} else f[i][l][r]=-0x7f7f7f7f;
	for (int i=3;i<=N;i++)
		for (int len=2;len<N;len++)
			for (int l=1,r=len+1;r<=N;l++,r++)
				f[i][l][r]=max(f[i][l][r],max(f[i][l+1][r],f[i][l][r-1]));
	for (int i=N-2;i;i--)
		for (int l=1;l+2<=N;l++)
			for (int r=l+2;r<=N;r++) if (map[i][l]=='.' && map[i][r]=='.')
			{
				if (Left[i+2][r]<=l && map[i+1][l]=='.' && map[i+1][r]=='.')
					g[i&1][l][r]=r-l-1;
				else
					g[i&1][l][r]=-0x7f7f7f7f;
				g[i&1][l][r]=max(g[i&1][l][r],g[(i-1)&1][l][r]+r-l-1);
				if (Left[i][r]<=l && f[i][l][r]>0 && g[i&1][l][r]>0) 
					ans=max(ans,(long long)(f[i][l][r])*g[i&1][l][r]);
			} else g[i&1][l][r]=-0x7f7f7f7f;
	printf("%lld\n",ans);
	return 0;
}

