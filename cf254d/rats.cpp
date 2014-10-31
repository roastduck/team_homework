#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PI;
#define fi first
#define se second

const int maxn=1005;
const int walk[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int N, M, D, all;
char map[maxn][maxn];
vector<PI> V1, V2, V3, V4, V5;
set<PI> R;

void Bfs(int xx, int yy, vector<PI> &V, bool all)
{
	static int T, lx[256], ly[256], lt[256], flag[maxn][maxn];
	int st(0), en(0);
	flag[xx][yy]=++T;
	lx[0]=xx, ly[0]=yy, lt[0]=0;
	V.clear();
	for (;st<=en;st++)
	{
		int x(lx[st]), y(ly[st]);
		if (all || map[x][y]=='R')
			V.push_back(PI(x,y));
		if (lt[st]==D) continue;
		for (int k=0;k<4;k++)
		{
			int _x(x+walk[k][0]), _y(y+walk[k][1]);
			if (map[_x][_y]!='X' && flag[_x][_y]!=T)
			{
				en++, lx[en]=_x, ly[en]=_y, lt[en]=lt[st]+1;
				flag[_x][_y]=T;
			}
		}
	}
}

int main()
{
	freopen("rats.in","r",stdin);
	freopen("rats.out","w",stdout);
	scanf("%d%d%d",&N,&M,&D);
	for (int i=1;i<=N;i++) scanf("%s",map[i]+1);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++) if (map[i][j]=='R')
			R.insert(PI(i,j)), all++;
	Bfs(R.begin()->fi,R.begin()->se,V1,false);
	Bfs(V1.front().fi,V1.front().se,V2,true);
	for (vector<PI>::iterator i=V2.begin(); i!=V2.end(); i++)
	{
		Bfs(i->fi,i->se,V3,false);
		for (vector<PI>::iterator j=V3.begin(); j!=V3.end(); j++)
			R.erase(*j), map[j->fi][j->se]='C';
		if (R.empty())
		{
			for (int p=1;p<=N;p++)
				for (int q=1;q<=M;q++) if (map[p][q]!='X')
					return printf("%d %d %d %d\n",i->fi,i->se,p,q), 0;
			return puts("-1"), 0;
		}
		Bfs(R.begin()->fi,R.begin()->se,V4,true);
		for (vector<PI>::iterator j=V4.begin(); j!=V4.end(); j++)
		{
			Bfs(j->fi,j->se,V5,false);
			if (V5.size()+V3.size()==all)
				return printf("%d %d %d %d\n",i->fi,i->se,j->fi,j->se), 0;
		}
		for (vector<PI>::iterator j=V3.begin(); j!=V3.end(); j++)
			R.insert(*j), map[j->fi][j->se]='R';
	}
	puts("-1");
	return 0;
}

