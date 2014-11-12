#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, K, H, f[2][780];
bool S[100005][780];

int main()
{
	freopen("pyramid.in","r",stdin);
	freopen("pyramid.out","w",stdout);
	scanf("%d%d",&N,&K);
	H=sqrt(6*K)+1;
	for (int i=1;i<=K;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		S[N-x+y][min(H,N-x+1)]=true;
	}
	for (int i=1;i<=N;i++)
	{
		int tot(0), HH(min(H,i));
		f[i&1][0]=0x7fffffff;
		for (int j=HH;j;j--)
		{
			tot+=S[i][j+1];
			f[i&1][0]=min(f[i&1][0],f[i&1^1][j-1]+j*(j+1)/2+2+tot*3);
			f[i&1][j]=f[i&1^1][j-1]+tot*3;
		}
		tot+=S[i][1];
		f[i&1][0]=min(f[i&1][0],f[i&1^1][0]+tot*3);
		for (int j=1;j<=HH;j++)
			f[i&1][j]=min(f[i&1][j],f[i&1][j-1]);
	}
	printf("%d\n",f[N&1][0]);
	return 0;
}

