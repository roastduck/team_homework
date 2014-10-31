#include<cstdio>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;

const int walk[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
const char dir[4]={'L','U','R','D'};

int Vx, Vy, Sx, Sy, M, lastd_array[205][205];
bool tree_array[205][205];
list<int> dlist;
list<char> ans;

#define tree(x,y) ((x)<-100||(x)>100||(y)<-100||(y)>100?false:tree_array[(x)+102][(y)+102])
#define lastd(x,y) lastd_array[(x)+102][(y)+102]

void Bfs()
{
	static int fx[42000], fy[42000];
	int st(0), en(0);
	fx[0]=Vx, fy[0]=Vy;
	lastd(Vx,Vy)=4;
	for (;st<=en;st++)
	{
		int x(fx[st]), y(fy[st]);
		for (int k=0;k<4;k++)
		{
			int _x(x+walk[k][0]), _y(y+walk[k][1]);
			if (_x<-101 || _y<-101 || _x>101 || _y>101 || ~lastd(_x,_y) || tree(_x,_y)) continue;
			lastd(_x,_y)=k;
			en++, fx[en]=_x, fy[en]=_y;
		}
	}
}

inline void Move(int k, int n)
{
	while (n-->0)
	{
		ans.push_back(dir[k]);
		if (!tree(Sx+walk[k][0],Sy+walk[k][1])) Sx+=walk[k][0], Sy+=walk[k][1];
		Vx+=walk[k][0], Vy+=walk[k][1];
	}
}

int main()
{
	freopen("shadow.in","r",stdin);
	freopen("shadow.out","w",stdout);
	scanf("%d%d%d%d%d",&Vx,&Vy,&Sx,&Sy,&M);
	if (!M) return puts("-1"), 0;
	int Ux, Uy(-101), Rx(-101), Ry, Dx, Dy(101), Lx(101), Ly;
	for (int i=1;i<=M;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		if (x<Lx) Lx=x, Ly=y;
		if (x>Rx) Rx=x, Ry=y;
		if (y<Dy) Dx=x, Dy=y;
		if (y>Uy) Ux=x, Uy=y;
		tree_array[x+102][y+102]=true;
	}
	memset(lastd_array,255,sizeof lastd_array);
	Bfs();
	if (!~lastd(Sx,Sy)) return puts("-1"), 0;
	for (int x=Sx, y=Sy; x!=Vx || y!=Vy;)
	{
		int k(lastd(x,y));
		dlist.push_front(k);
		x-=walk[k][0], y-=walk[k][1];
	}
	while ((Vx!=Sx || Vy!=Sy) && (Vx>=Lx && Vx<=Rx && Vy>=Dy && Vy<=Uy || Sx>=Lx && Sx<=Rx && Sy>=Dy && Sy<=Uy))
	{
		int k(dlist.front());
		ans.push_back(dir[k]);
		dlist.pop_front();
		if (!tree(Sx+walk[k][0],Sy+walk[k][1]))
		{
			dlist.push_back(k);
			Sx+=walk[k][0], Sy+=walk[k][1];
		}
		Vx+=walk[k][0], Vy+=walk[k][1];
	}
	if (Vx<Sx)
	{
		if (Sx>Rx) Move(2,Rx-Vx+1), Move(1,Uy+1-min(Vy,Sy));
		Move(0,Sx-Lx+1);
		if (Sy>Ly) Move(3,Sy-Ly); else Move(1,Ly-Sy);
		Move(2,Lx-Vx-1);
	}
	if (Vx>Sx)
	{
		if (Sx<Lx) Move(0,Vx-Lx+1), Move(1,Uy+1-min(Vy,Sy));
		Move(2,Rx-Sx+1);
		if (Sy>Ry) Move(3,Sy-Ry); else Move(1,Ry-Sy);
		Move(0,Vx-Rx-1);
	}
	if (Vy<Sy)
	{
		if (Sy>Uy) Move(1,Ux-Vx+1), Move(2,Rx+1-min(Vx,Sx));
		Move(3,Sy-Dy+1);
		if (Sx>Dx) Move(0,Sx-Dx); else Move(2,Dx-Sx);
		Move(1,Dy-Vy-1);
	}
	if (Vy>Sy)
	{
		if (Sy<Dy) Move(3,Vx-Dx+1), Move(2,Rx+1-min(Vx,Sx));
		Move(1,Uy-Sy+1);
		if (Sx>Ux) Move(0,Sx-Ux); else Move(2,Ux-Sx);
		Move(3,Vy-Uy-1);
	}
	for (list<char>::iterator i=ans.begin(); i!=ans.end(); i++)
		putchar(*i);
	putchar('\n');
	return 0;
}

