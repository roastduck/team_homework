#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline void READ(int &x)
{
	char c;
	x=0;
	do c=getchar(); while (c<'0' || c>'9');
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
}

const int maxn=3005, maxk=300005;
const int walk[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int N, M, K, cnt, father[maxk<<1], id[maxn][maxn<<1], tag[maxk<<1];

inline int get(int x)
{
	return x==father[x]?x:father[x]=get(father[x]);
}

int main()
{
	freopen("reclamation.in","r",stdin);
	freopen("reclamation.out","w",stdout);
	READ(N), READ(M), READ(K);
	if (M==1) return puts("0"), 0;
	for (;K;K--)
	{
		int x, y;
		READ(x), READ(y);
		bool ok(true);
		for (int k=0;k<8;k++)
		{
			int _x(x+walk[k][0]), _y((y+walk[k][1]+2*M-1)%(2*M)+1);
			if (_x<=0 || _x>N || !id[_x][_y]) continue;
			tag[get(id[_x][_y])]=K;
		}
		for (int k=0;k<8;k++)
		{
			int _x(x+walk[k][0]), _y((y+walk[k][1]+M-1)%(2*M)+1);
			if (_x<=0 || _x>N || !id[_x][_y]) continue;
			if (tag[get(id[_x][_y])]==K) { ok=false; break; }
		}
		if (!ok) continue;
		id[x][y]=++cnt, father[cnt]=cnt;
		id[x][y+M]=++cnt, father[cnt]=cnt;
		for (int k=0;k<8;k++)
		{
			int _x(x+walk[k][0]), _y;
			_y=(y+walk[k][1]+2*M-1)%(2*M)+1;
			if (_x && _x<=N && id[_x][_y]) father[father[id[_x][_y]]]=id[x][y];
			_y=(y+walk[k][1]+M-1)%(2*M)+1;
			if (_x && _x<=N && id[_x][_y]) father[father[id[_x][_y]]]=id[x][y+M];
		}
	}
	printf("%d\n",cnt>>1);
	return 0;
}

