#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 3010
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
const int a1[8]={-1,-1,-1,0,0,1,1,1},a2[8]={1,-1,0,1,-1,1,-1,0};
struct ww {
	int x,y;
} g[3000000];
int i,j,k,n,m,x,y,r,an,K;
int id[N][N*2],f[N*N*2];
bool h[N][N*2];
int get(int x) {
	g[++r]=(ww){x,f[x]};
	return f[x]==x?x:f[x]=get(f[x]);
}
inline void Do(int x,int y) {
	int i;
	For(i,0,7) {
		int X=x+a1[i],Y=y+a2[i];
		if (Y<1) Y+=m*2;
		if (Y>m*2) Y-=m*2;
		if (X&&X<=n&&h[X][Y]) {
			int A=get(id[X][Y]),B=get(id[x][y]);
			g[++r]=(ww){B,f[B]};
			f[B]=A;
		}
	}
}
int main() {
	freopen("reclamation.in","r",stdin), freopen("reclamation.ans","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	For(i,1,n)For(j,1,m*2) id[i][j]=++k;
	For(i,1,k) f[i]=i;
	For(i,1,K) {
		scanf("%d%d",&x,&y);
		r=0;
		h[x][y]=h[x][y+m]=1;
		Do(x,y),Do(x,y+m);
		if (get(id[x][y])==get(id[x][y+m])) {
			h[x][y]=h[x][y+m]=0;
			for (;r;r--) {
				ww A=g[r];
				f[A.x]=A.y;
			}
		} else an++;
	}
	printf("%d\n",an);
	return 0;
}

