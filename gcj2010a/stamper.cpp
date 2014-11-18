#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=2005;
const int pos[6][3]={{0,1,2},{0,2,1},{1,0,2},{2,0,1},{1,2,0},{2,1,0}};
	

int f[maxn][6][maxn];
char s[maxn];

/*
 * 0: ABC
 * 1: ACB
 * 2: BAC
 * 3: BCA
 * 4: CAB
 * 5: CBA
 */

int main()
{
	freopen("stamper.in","r",stdin);
	freopen("stamper.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		memset(f,127,sizeof f);
		for (int i=0;i<6;i++) f[0][i][0]=0;
		scanf("%s",s+1);
		int i;
		for (i=1;s[i];i++)
		{
			for (int j=0;j<6;j++)
				for (int k=0,q=pos[j][s[i]-'A']+1,p=q-3;k<i;)
				{
					if (p>0) f[i][j][p]=min(f[i][j][p],f[i-1][j][k]+k-p+1);
					f[i][j][q]=min(f[i][j][q],f[i-1][j][k]+q-k+1);
					if (++k>q) p=q, q+=3;
				}
			f[i][0][1]=f[i][1][1]=min(f[i][0][1],f[i][1][1]);
			f[i][2][1]=f[i][3][1]=min(f[i][2][1],f[i][3][1]);
			f[i][4][1]=f[i][5][1]=min(f[i][4][1],f[i][5][1]);
		}
		int ans(0x7f7f7f7f);
		for (int j=0;j<6;j++)
			for (int k=0;k<i;k++)
				ans=min(ans,f[i-1][j][k]+k);
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}

