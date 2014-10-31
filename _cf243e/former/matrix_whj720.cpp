#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#define M 510
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
struct ww {
	int ty,flag;
	vector<int> a;
	bitset<M> b;
} a[M*M];
//0 leaf 1 luan 2 you shunxu
int i,j,k,n,m,t,s,F;
int b[M];
bitset<M> c;
char p[M][M];
inline void fail() {
	printf("NO\n");
	if (n==50) printf("%d %d\n",F,i);
	exit(0);
}
void Swap(int x) {
	if (a[x].ty<2) return;
	int i;
	vector<int> b;
	for (i=a[x].a.size()-1;i>=0;i--) {
		int A=a[x].a[i];
		Swap(A);
		b.push_back(A);
	}
	a[x].a=b;
}
void dfs(int x,bitset<M> y,int z) {
	if (a[x].b==y) return;
	if (a[x].ty==1) {
		int i;
		vector<int> Vec,Ans,la;
		for (i=0;i<a[x].a.size();i++) {
			int A=a[x].a[i];
			bitset<M> B=a[A].b&y;
			if (B.count()) {
				if (B!=a[A].b) la.push_back(A);
				else Vec.push_back(A);
			} else Ans.push_back(A);
		}
		if (la.size()>2) F=1,fail();
		if (la.size()==2&&z) F=2,fail();
		for (i=0;i<la.size();i++) {
			int A=la[i];
			bitset<M> B=a[A].b&y;
			if (!Vec.size()&&la.size()==1&&!z) dfs(A,B,0);
			else {
				if (la.size()==1&&z) dfs(A,B,z);
				else dfs(A,B,i+1);
			}
		}
		int id=0,Id=0;
		if (Vec.size()==1) id=Vec[0];
		if (Vec.size()>1) {
			a[++t].ty=1;
			a[t].a=Vec;
			for (i=0;i<Vec.size();i++) a[t].b|=a[Vec[i]].b;
			id=t;
		}
		if (z) {
			if (Ans.size()==1) Id=Ans[0];
			if (Ans.size()>1) {
				a[++t].ty=1;
				a[t].a=Ans;
				for (i=0;i<Ans.size();i++) a[t].b|=a[Ans[i]].b;
				Id=t;
			}
		}
		if (!la.size()) Ans.push_back(id);
		if (la.size()==1) {
			if (!id) id=la[0];
			else {
				a[++t].ty=2; a[t].flag=!z;
				a[t].b=a[la[0]].b|a[id].b;
				if (z<2) a[t].a.push_back(la[0]);
				a[t].a.push_back(id);
				if (z==2) a[t].a.push_back(la[0]);
				id=t;
			}
			Ans.push_back(id);
		}
		if (la.size()==2) {
			a[++t].ty=2; a[t].flag=1;
			a[t].b=a[la[0]].b|a[id].b|a[la[1]].b;
			a[t].a.push_back(la[0]);
			if (id) a[t].a.push_back(id);
			a[t].a.push_back(la[1]);
			id=t;
			Ans.push_back(id);
		}
		if (!z) {
			if (Ans.size()==1) a[x]=a[Ans[0]];
			else a[x].a=Ans;
		} else {
			if (!Id) a[x]=a[id];
			else {
				a[++t].ty=2;
				a[t].b=a[Id].b|a[id].b;
				if (z==1) a[t].a.push_back(Id);
				a[t].a.push_back(id);
				if (z==2) a[t].a.push_back(Id);
				a[x]=a[t];
			}
		}
	} else {
		int i,j;
		for (i=0;i<a[x].a.size();i++) {
			int A=a[x].a[i];
			bitset<M> B=a[A].b&y;
			if (B.count()) break;
		}
		for (j=i;j<a[x].a.size();j++) {
			int A=a[x].a[j];
			bitset<M> B=a[A].b&y;
			if (!B.count()) break;
		}
		int l=i,r=j-1;
		for (i=j+1;i<a[x].a.size();i++) {
			int A=a[x].a[i];
			bitset<M> B=a[A].b&y;
			if (B.count()) F=3,fail();
		}
		for (i=l+1;i<r;i++) {
			int A=a[x].a[i];
			bitset<M> B=a[A].b&y;
			if (B!=a[A].b) F=4,fail();
		}
		int f1,f2;
		{
			int A=a[x].a[l];
			bitset<M> B=a[A].b&y;
			f1=B==a[A].b;
			
			A=a[x].a[r];
			B=a[A].b&y;
			f2=B==a[A].b;
		}
		if (z==1&&(r!=a[x].a.size()-1||l<r&&!f2)) {
			if (a[x].flag&&!(l!=0||l<r&&!f1)) {
				Swap(x),dfs(x,y,z); return;
			} else F=5,fail();
		}
		if (z==2&&(l!=0||l<r&&!f1)) {
			if (a[x].flag&&!(r!=a[x].a.size()-1||l<r&&!f2)) {
				Swap(x),dfs(x,y,z); return;
			} else F=6,fail();
		}
		if (l==r) {
			int A=a[x].a[l];
			dfs(A,a[A].b&y,z);
		} else {
			int A=a[x].a[l];
			dfs(A,a[A].b&y,1);
			A=a[x].a[r];
			dfs(A,a[A].b&y,2);
		}
		if (z) a[x].flag=0;
	}
}
void Dfs(int x) {
	if (!a[x].ty) b[++s]=x;
	int i;
	for (i=0;i<a[x].a.size();i++) Dfs(a[x].a[i]);
}
int main() {
	//freopen("243e.in","r",stdin);
	//freopen("243e.out","w",stdout);
	scanf("%d",&n);
	a[t=n+1].ty=1;
	For(i,1,n) a[i].b[i]=1,a[t].a.push_back(i),a[t].b[i]=1;
	For(i,1,n) {
		scanf("%s",p[i]+1);
		c.reset();
		int s=0;
		For(j,1,n) if (p[i][j]=='1') c[j]=1,s++;
		if (s<=1) continue;
		dfs(n+1,c,0);
	}
	Dfs(n+1);
	printf("YES\n");
	For(i,1,n) {
		For(j,1,n) printf("%c",p[i][b[j]]);
		printf("\n");
	}
	return 0;
}

