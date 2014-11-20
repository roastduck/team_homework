#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
struct EXAM { int t, p; };

inline bool operator<(const EXAM &a, const EXAM &b)
{
	return a.t*b.p<b.t*a.p;
}

inline ll cross(ll x1, ll y1, ll x2, ll y2)
{
	return x1*y2-x2*y1;
}

const int maxn=5e4+5;

int N, anscnt, St[maxn], Sp[maxn], ans[maxn];
EXAM A[maxn], L[maxn], MIN[maxn];

int main()
{
	freopen("school.in","r",stdin);
	freopen("school.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf("%d%d",&A[i].t,&A[i].p);
	sort(A+1,A+N+1);
	int st, en;
	st=1, en=0;
	for (int i=N;i>1;i--)
	{
		St[i]=St[i+1]+A[i].t, Sp[i]=Sp[i+1]+A[i].p;
		while (en>=st && L[en].p<=A[i].p) en--;
		while (en>st && cross(L[en-1].p-L[en].p,L[en-1].t-L[en].t,L[en].p-A[i].p,L[en].t-A[i].t)>=0) en--;
		L[++en]=A[i];
		while (en>st && cross(Sp[i],St[i],L[st].p-L[st+1].p,L[st].t-L[st+1].t)>=0) st++;
		MIN[i-1]=L[st];
	}
	st=1, en=0;
	for (int i=1;i<N;i++)
	{
		while (en>=st && L[en].p>=A[i].p) en--;
		while (en>st && cross(L[en].p-L[en-1].p,L[en].t-L[en-1].t,A[i].p-L[en].p,A[i].t-L[en].t)>=0) en--;
		L[++en]=A[i];
		while (en>st && cross(Sp[i+1],St[i+1],L[en].p-L[en-1].p,L[en].t-L[en-1].t)<=0) en--;
		if (cross(Sp[i+1],St[i+1],L[en].p,L[en].t)>cross(Sp[i+1],St[i+1],MIN[i].p,MIN[i].t))
			ans[++anscnt]=i;
	}
	printf("%d\n",anscnt);
	for (int i=1;i<=anscnt;i++)
		printf("%d\n",ans[i]);
	return 0;
}

