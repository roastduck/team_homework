#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=155, mo=1000000007;
typedef long long ll;
int N, M;
ll g[maxn][maxn][maxn][2][2], ans; // 0=in 1=out

int main()
{
	//freopen("273d.in","r",stdin);
	//freopen("273d.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<N;i++)
	{
		for (int len=0;len<M;len++)
			for (int l=1,r=l+len;r<=M;l++,r++)
				g[i][l][r][0][0]=((g[i][l][r-1][0][0]+g[i][l+1][r][0][0]-g[i][l+1][r-1][0][0]+g[i-1][l][r][0][0]+1)%mo+mo)%mo;
		for (int l=1;l<=M;l++)
			for (int r=l;r<=M;r++)
				g[i][l][r][1][0]=((g[i][l][r-1][1][0]+g[i][l-1][r][1][0]-g[i][l-1][r-1][1][0]+g[i-1][l][r][1][0]+g[i-1][l+1][r][0][0]+1)%mo+mo)%mo;
		for (int r=M;r;r--)
			for (int l=r;l;l--)
				g[i][l][r][0][1]=((g[i][l][r+1][0][1]+g[i][l+1][r][0][1]-g[i][l+1][r+1][0][1]+g[i-1][l][r][0][1]+g[i-1][l][r-1][0][0]+1)%mo+mo)%mo;
		for (int len=M-1;len>=0;len--)
			for (int l=1,r=l+len;r<=M;l++,r++)
				g[i][l][r][1][1]=((g[i][l][r+1][1][1]+g[i][l-1][r][1][1]-g[i][l-1][r+1][1][1]+g[i-1][l][r][1][1]+g[i-1][l+1][r-1][0][0]+g[i-1][l+1][r][0][1]+g[i-1][l][r-1][1][0]+1)%mo+mo)%mo;
	}
	for (int i=1;i<=N;i++)
		for (int l=1;l<=M;l++)
			for (int r=l;r<=M;r++)
				ans+=g[i-1][l][r][1][1]+g[i-1][l+1][r-1][0][0]+g[i-1][l+1][r][0][1]+g[i-1][l][r-1][1][0]+1, ans%=mo;
	printf("%I64d\n",ans);
	return 0;
}