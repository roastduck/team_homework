#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
inline void READ(int &x)
{
	char c;
	x=0;
	bool minus(false);
	do c=getchar(); while ((c<'0' || c>'9') && c!='-');
	if (c=='-') minus=true, c=getchar();
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
	if (minus) x=-x;
}
const int maxn=1e5+5;
int N, M, T[maxn], X[maxn], Y[maxn], P[maxn<<1], rn, no[maxn], father[maxn], lb[maxn], rb[maxn];
vector<int> f[maxn<<2];
int get(int x)
{
	return x==father[x]?x:father[x]=get(father[x]);
}
#define pos(l,r) (((l)+(r))|((l)!=(r)))
void Replace(int l, int r, int q, int v)
{
	int now(pos(l,r));
	if (!f[now].empty())
	{
		for (int i=0;i<f[now].size();i++)
		{
			lb[v]=min(lb[v],lb[get(f[now][i])]);
			rb[v]=max(rb[v],rb[get(f[now][i])]);
			father[get(f[now][i])]=v;
		}
		f[now].clear();
		f[now].push_back(v);
	}
	if (l==r) return;
	int mid((l+r)>>1);
	if (q<=mid) Replace(l,mid,q,v);
	else Replace(mid+1,r,q,v);
}
void Cover(int l, int r, int ql, int qr, int v)
{
	if (l==ql && r==qr)
	{
		f[pos(l,r)].push_back(v);
		return;
	}
	int mid((l+r)>>1);
	if (qr<=mid) Cover(l,mid,ql,qr,v); else
	if (ql>mid) Cover(mid+1,r,ql,qr,v); else
		Cover(l,mid,ql,mid,v), Cover(mid+1,r,mid+1,qr,v);
}
int main()
{
	freopen("pingpong.in","r",stdin);
	freopen("pingpong.out","w",stdout);
	READ(N);
	for (int i=1;i<=N;i++)
	{
		READ(T[i]), READ(X[i]), READ(Y[i]);
		if (T[i]==1) P[M++]=X[i], P[M++]=Y[i];
	}
	sort(P,P+M);
	M=unique(P,P+M)-P;
	for (int i=1;i<=N;i++)
		if (T[i]==1)
		{
			X[i]=lower_bound(P,P+M,X[i])-P;
			Y[i]=lower_bound(P,P+M,Y[i])-P;
			no[++rn]=i, father[rn]=rn;
			lb[rn]=X[i], rb[rn]=Y[i];
			Replace(0,M-1,X[i],rn);
			Replace(0,M-1,Y[i],rn);
			if (Y[i]-X[i]>1)
				Cover(0,M-1,X[i]+1,Y[i]-1,rn);
		} else
		{
			int a=no[X[i]], b=get(Y[i]);
			bool ok=get(X[i])==b || lb[b]<Y[a] && rb[b]>Y[a] || rb[b]>X[a] && lb[b]<X[a];
			puts(ok?"YES":"NO");
		}
		return 0;
}

