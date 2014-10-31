#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1005;
const int walk[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int N, M, D, X, Y, T, tot, flag[maxn][maxn];
char map[maxn][maxn];

void Bfs(int, int, void(*)(int,int));

inline void adp1(int x, int y)
{
	flag[x][y]=T;
}

inline void adp0(int x, int y)
{
	T++;
	Bfs(x,y,adp1);
	
}

void Bfs(int xx, int yy, void(*adp)(int,int))
{
	int st(0), en(0), lx[256], ly[256];
	lx[0]=xx, ly[0]=yy;
	for (;st<=en;st++)
	{
		int x(lx[st]), y(ly[st]);
		adp(x,y);
		for (int k=0;k<4;k++)
		{
			int _x(x+walk[k][0]), _y(y+walk[k][1]);
			if (map[_x][_y]!='X')
				en++, lx[en]=_x, ly[en]=_y;
		}
	}
	return ret;
}

int main()
{
	freopen("rats.in","r",stdin);
	freopen("rats.out","w",stdout);
	scanf("%d%d%d",&N,&M,&D);
	for (int i=1;i<=N;i++) scanf("%s",map[i]+1);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++) if (map[i][j]=='R')
			Bfs(i,j,adp0);
	return 0;
}

