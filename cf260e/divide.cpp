#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef pair<int,int> PI;
#define fi first
#define se second

struct QUE
{
	int x, u, d, id;
	QUE() {}
	QUE(int _x, int _u, int _d, int _id) : x(_x), u(_u), d(_d), id(_id) {}
};

const int maxn=1e5+5, maxp=362885;

int N, A[9], perm[9], Y[maxn], pn, qn, ans[maxp][4], f[maxn<<1];
bool fail[maxp];
PI P[maxn], *X[maxn];
QUE query[maxp*3];

inline bool cmpx(PI *a, PI *b) { return a->fi<b->fi; }
inline bool operator<(const QUE &a, const QUE &b) { return a.x<b.x; }

#define pos(l,r) (((l)+(r))|((l)!=(r)))

void Ins(int l, int r, int q)
{
	int now(pos(l,r)), mid((l+r)>>1);
	f[now]++;
	if (l==r) return;
	if (q<=mid) Ins(l,mid,q); else Ins(mid+1,r,q);
}

int Find(int l, int r, int ql, int qr)
{
	int now(pos(l,r)), mid((l+r)>>1);
	if (l==ql && r==qr) return f[now];
	if (qr<=mid) return Find(l,mid,ql,qr);
	if (ql>mid) return Find(mid+1,r,ql,qr);
	return Find(l,mid,ql,mid)+Find(mid+1,r,mid+1,qr);
}

int Bottom(int l, int r, int q)
{
	int mid((l+r)>>1);
	if (l==r) return l;
	if (f[pos(l,mid)]>=q) return Bottom(l,mid,q);
	return Bottom(mid+1,r,q-f[pos(l,mid)]);
}

int Top(int l, int r, int q)
{
	int mid((l+r)>>1);
	if (l==r) return l;
	if (f[pos(mid+1,r)]>=q) return Top(mid+1,r,q);
	return Top(l,mid,q-f[pos(mid+1,r)]);
}

int main()
{
	freopen("divide.in","r",stdin);
	freopen("divide.out","w",stdout);
	scanf("%d",&N);
	for (int i=0;i<N;i++)
	{
		scanf("%d%d",&P[i].fi,&P[i].se);
		X[i]=P+i, Y[i]=P[i].se;
	}
	sort(X,X+N,cmpx);
	sort(Y,Y+N);
	for (int i=0;i<9;i++)
	{
		scanf("%d",&A[i]);
		perm[i]=i;
	}
	do
	{
		int B[9];
		for (int i=0;i<9;i++) B[i]=A[perm[i]];
		query[qn++]=QUE(B[0]+B[3]+B[6],B[0],B[6],pn);
		query[qn++]=QUE(N-B[2]-B[5]-B[8],B[0]+B[1],B[6]+B[7],pn);
		query[qn++]=QUE(N,B[0]+B[1]+B[2],B[6]+B[7]+B[8],pn);
		ans[pn][0]=ans[pn][1]=-1, ans[pn][2]=0x80000000, ans[pn][3]=0x7fffffff;
		pn++;
	} while (next_permutation(perm,perm+9));
	sort(query,query+qn);
	for (int i=0,j=0;i<qn;i++)
	{
		for (;j<query[i].x;j++)
			Ins(0,N-1,lower_bound(Y,Y+N,X[j]->se)-Y);
		int id=query[i].id;
		if (j<N && X[j]->fi==X[j-1]->fi)
		{
			fail[id]=true;
			continue;
		}
		if (!~ans[id][0]) ans[id][0]=j-1; else
		if (!~ans[id][1]) ans[id][1]=j-1;
		ans[id][2]=max(ans[id][2],Y[Bottom(0,N-1,query[i].d)]);
		ans[id][3]=min(ans[id][3],Y[Top(0,N-1,query[i].u)]);
	}
	memset(f,0,sizeof f);
	for (int i=0,j=0;i<qn;i++)
	{
		for (;j<query[i].x;j++)
			Ins(0,N-1,lower_bound(Y,Y+N,X[j]->se)-Y);
		int id=query[i].id;
		if (!fail[id] && Find(0,N-1,0,lower_bound(Y,Y+N,ans[id][2])-Y)!=query[i].d)
			fail[id]=true;
		if (!fail[id] && Find(0,N-1,lower_bound(Y,Y+N,ans[id][3])-Y,N-1)!=query[i].u)
			fail[id]=true;
	}
	for (int i=0;i<pn;i++) if (!fail[i])
	{
		printf("%.3f %.3f\n%.3f %.3f\n",
				X[ans[i][0]]->fi+0.3,X[ans[i][1]]->fi+0.6,ans[i][2]+0.3,ans[i][3]-0.3
			 );
		return 0;
	}
	puts("-1");
	return 0;
}

