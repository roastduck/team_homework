#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e4+5, mo=1e9+7;

int N, dotx, doty, fob[maxn], f[maxn][8][2];

int main()
{
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	scanf("%d",&N);
	for (int i=0;i<3;i++)
		for (int j=1;j<=N;j++)
		{
			char c;
			scanf(" %c",&c);
			if (c=='O') dotx=i, doty=j;
			if (c!='.') fob[j]|=(1<<i);
		}
	fob[N+1]=7;
	f[0][0][0]=1;
	for (int i=1;i<=N;i++)
		for (int j=0;j<8;j++) if (!(j&(fob[i-1]|fob[i])))
			for (int k=0;k<8;k++) if (!(k&(fob[i]|fob[i+1])) && !(j&k))
			{
				int v(7^k^fob[i]^j);
				if (v!=0 && v!=3 && v!=6) continue;
				bool move(false);
				if (doty==i && v) move=true;
				if (doty==i-1 && (k&(1<<dotx))) move=true;
				if (doty==i+1 && ((7^fob[i]^k^v)&(1<<dotx))) move=true;
				if (move)
					f[i][k][1]+=(f[i-1][j][0]+f[i-1][j][1])%mo, f[i][k][1]%=mo;
				else
				{
					f[i][k][0]+=f[i-1][j][0], f[i][k][0]%=mo;
					f[i][k][1]+=f[i-1][j][1], f[i][k][1]%=mo;
				}
			}
	int ans(0);
	for (int i=0;i<8;i++)
		ans+=f[N][i][1], ans%=mo;
	printf("%d\n",ans);
	return 0;
}

