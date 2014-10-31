#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

typedef long long ll;
typedef pair<int,int> PI;
typedef pair<PI,ll> PIL;

#define mkp(x,y) make_pair(x,y)
#define fi first
#define se second

const ll inf=0x7f7f7f7f7f7f7f7fll;
const int walk[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int H, W;
ll M, ans, bed[25][25], surface[25][25], drop[25][25];

void Rain()
{
	static PIL heap[405];
	int top(1);
	memset(surface,127,sizeof surface);
	heap[0]=mkp(mkp(0,0),surface[0][0]=bed[0][0]);
	while (top)
	{
		while (top && surface[heap[0].fi.fi][heap[0].fi.se]>heap[0].se)
			pop_heap(heap,heap+top--,greater<PIL>());
		if (!top) break;
		int x(heap[0].fi.fi), y(heap[0].fi.se);
		pop_heap(heap,heap+top--,greater<PIL>());
		for (int k=0;k<4;k++)
		{
			int _x(x+walk[k][0]), _y(y+walk[k][1]);
			if (_x>=0 && _y>=0 && _x<=H+1 && _y<=W+1 && surface[_x][_y]>max(surface[x][y],bed[_x][_y]))
			{
				heap[top++]=mkp(mkp(_x,_y),surface[_x][_y]=max(surface[x][y],bed[_x][_y]));
				push_heap(heap,heap+top,greater<PIL>());
			}
		}
	}
}

bool Erode()
{
	ll step(inf), h1(0), h2(inf);
	memset(drop,0,sizeof drop);
	for (int i=1;i<=H;i++)
		for (int j=1;j<=W;j++) if (surface[i][j]==bed[i][j])
		{
			for (int k=0;k<4;k++)
				drop[i][j]=max(drop[i][j],surface[i][j]-surface[i+walk[k][0]][j+walk[k][1]]);
			drop[i][j]=min(drop[i][j],M);
			if (drop[i][j]<M) step=1;
			h1=max(h1,bed[i][j]);
		} else
			h2=min(h2,surface[i][j]-bed[i][j]);
	if (!h1) return false;
	step=min(step,min(h1,h2)/M+bool(min(h1,h2)%M));
	ans+=step;
	for (int i=1;i<=H;i++)
		for (int j=1;j<=W;j++)
			bed[i][j]-=step*drop[i][j];
	return true;
}

int main()
{
	//freopen("rain.in","r",stdin);
	//freopen("rain.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		memset(bed,128,sizeof bed);
		scanf("%d%d%I64d",&H,&W,&M);
		for (int i=1;i<=H;i++)
			for (int j=1;j<=W;j++)
				scanf("%I64d",&bed[i][j]);
		ans=0;
		do Rain(); while (Erode());
		printf("Case #%d: %I64d\n",t,ans);
	}
	return 0;
}

