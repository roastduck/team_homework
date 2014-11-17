#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn=50005;

struct TASK
{
	int t, s, p, id;
};

inline bool operator<(const TASK &a, const TASK &b)
{
	return a.t<b.t;
}

typedef long long ll;
typedef pair<int,int> PI;
#define fi first
#define se second

int N, n, pos, P[maxn], C[maxn];
ll T, res[maxn], ans[maxn];
TASK A[maxn];

void Try()
{
	static int remain[maxn];
	for (int i=1;i<=N;i++)
		remain[i]=A[i].s;
	priority_queue<PI> heap;
	ll t(0);
	int next(1);
	while (next<=N || !heap.empty())
	{
		ll tt(~(1ll<<63));
		if (!heap.empty())
			tt=min(tt,t+remain[heap.top().se]);
		if (next<=N)
			tt=min(tt,(ll)A[next].t);
		if (!heap.empty() && !(remain[heap.top().se]-=tt-t))
			res[heap.top().se]=tt, heap.pop();
		if (next<=N && tt==A[next].t)
			heap.push(PI(A[next].p,next)), next++;
		t=tt;
	}
}

int main()
{
	freopen("printer.in","r",stdin);
	freopen("printer.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d%d",&A[i].t,&A[i].s,&A[i].p);
		A[i].id=i;
		P[i]=A[i].p;
	}
	scanf("%I64d",&T);
	sort(A+1,A+N+1);
	sort(P+1,P+N+1);
	for (int i=1;i<=N&&!pos;i++) if (!~A[i].p)
		pos=i;
	P[1]=0, P[N+1]=0x7fffffff;
	for (int i=1;i<=N;i++) if (P[i]+1<P[i+1])
		C[++n]=P[i]+1;
	for (int l=1,r=n;l<=r;)
	{
		int mid((l+r)>>1);
		A[pos].p=C[mid];
		Try();
		if (res[pos]>T) l=mid+1; else
		if (res[pos]<T) r=mid-1; else
		{
			printf("%d\n",C[mid]);
			break;
		}
	}
	for (int i=1;i<=N;i++) ans[A[i].id]=res[i];
	for (int i=1;i<=N;i++)
	{
		printf("%I64d",ans[i]);
		putchar(i<N?' ':'\n');
	}
	return 0;
}

