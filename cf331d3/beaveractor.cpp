#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<functional>
using namespace std;

typedef long long ll;

const int maxn=2e5+5;
const int walk[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
const ll inf=1e17;

#define fi first
#define se second

struct ARROW
{
	int x0, y0, x1, y1;
	ARROW *to[55];
	ll dis[55];
	int dir() { return x0<x1? 0: y0<y1? 1: x0>x1? 2: 3; }
};

inline bool xl(ARROW *a, ARROW *b) { return max(a->x0,a->x1)<max(b->x0,b->x1); }
inline bool xg(ARROW *a, ARROW *b) { return min(a->x0,a->x1)>min(b->x0,b->x1); }
inline bool yl(ARROW *a, ARROW *b) { return max(a->y0,a->y1)<max(b->y0,b->y1); }
inline bool yg(ARROW *a, ARROW *b) { return min(a->y0,a->y1)>min(b->y0,b->y1); }

int N, B, Q;
ll T[maxn];
ARROW A[maxn], *S[maxn];

void Init(bool (*cmp)(ARROW*,ARROW*), int dir, int ARROW::*y0, int ARROW::*y1)
{
	for (int i=1;i<=N+Q;i++) S[i]=A+N+Q-i+1;
	stable_sort(S+1,S+N+Q+1,cmp);
	multimap<int,ARROW*> F;
	typedef multimap<int,ARROW*>::iterator it;
	for (int i=1;i<=N+Q;i++)
	{
		if (S[i]-A<=N)
		{
			it lo=F.lower_bound(min(S[i]->*y0,S[i]->*y1));
			it hi=F.upper_bound(max(S[i]->*y0,S[i]->*y1));
			for (it j=lo;j!=hi;j++)
			{
				j->se->to[0]=S[i];
				j->se->dis[0]=abs(j->se->x1-S[i]->x1)+abs(j->se->y1-S[i]->y1);
			}
			F.erase(lo,hi);
		}
		if (S[i]->dir()==dir)
			F.insert(make_pair(S[i]->*y0,S[i]));
	}
}

int main()
{
	freopen("beaveractor.in","r",stdin);
	freopen("beaveractor.out","w",stdout);
	scanf("%d%d",&N,&B);
	for (int i=1;i<=N;i++)
		scanf("%d%d%d%d",&A[i].x0,&A[i].y0,&A[i].x1,&A[i].y1);
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		char dir;
		scanf("%d%d %c%lld",&A[i+N].x0,&A[i+N].y0,&dir,&T[i]);
		A[i+N].x1=A[i+N].x0, A[i+N].y1=A[i+N].y0;
		switch (dir)
		{
			case 'R': A[i+N].x0--; break;
			case 'L': A[i+N].x0++; break;
			case 'U': A[i+N].y0--; break;
			case 'D': A[i+N].y0++;
		}
	}
	Init(xl,0,&ARROW::y0,&ARROW::y1);
	Init(xg,2,&ARROW::y0,&ARROW::y1);
	Init(yl,1,&ARROW::x0,&ARROW::x1);
	Init(yg,3,&ARROW::x0,&ARROW::x1);
	for (int k=1;k<50;k++)
		for (ARROW *i=A+1;i<=A+N+Q;i++) if (i->to[k-1] && i->to[k-1]->to[k-1] && i->dis[k-1]+i->to[k-1]->dis[k-1]<inf)
		{
			i->to[k]=i->to[k-1]->to[k-1];
			i->dis[k]=i->dis[k-1]+i->to[k-1]->dis[k-1];
		}
	for (int i=1;i<=Q;i++)
	{
		ARROW *now=A+i+N;
		ll t=T[i];
		for (int k=(t?63-__builtin_clzll(t):-1);k>=0;k--)
			if (now->to[k] && now->dis[k]<=t)
				t-=now->dis[k], now=now->to[k];
		int x=now->x1, y=now->y1, dir=now->dir();
		if (now->to[0])
		{
			int half;
			if (now->x0==now->x1)
			{
				half=max(0,min((now->to[0]->y0-now->y1)/walk[dir][1],(now->to[0]->y1-now->y1)/walk[dir][1]));
				if (half<=t)
					t-=half, y+=walk[dir][1]*half, dir=now->to[0]->dir();
			}
			else
			{
				half=max(0,min((now->to[0]->x0-now->x1)/walk[dir][0],(now->to[0]->x1-now->x1)/walk[dir][0]));
				if (half<=t)
					t-=half, x+=walk[dir][0]*half, dir=now->to[0]->dir();
			}
		}
		x=min<ll>(B,max(0ll,x+walk[dir][0]*t));
		y=min<ll>(B,max(0ll,y+walk[dir][1]*t));
		printf("%d %d\n",x,y);
	}
	return 0;
}

