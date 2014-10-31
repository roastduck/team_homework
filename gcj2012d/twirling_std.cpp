/*
	Time : 1326Z 20140928
	Task : Codejam 2012 WF D
	Tags : Geometry
	Stat : Accepted
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>

#define fi first
#define se second
#define fo(i,a,b) for (int i = a; i <= b; i ++)
#define fd(i,a,b) for (int i = a; i >= b; i --)
#define fe(i,x,y) for (int i = x, y = lnk[i]; i; i = nxt[i], y = lnk[i])
#define mkp make_pair
#define pb push_back
#define Fill(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
#define Bit(x,y) ((((x) >> (y)) & 1))
#define mit map<int,SI>::iterator
#define sit SI::iterator

using namespace std;
 
typedef long long LL;
typedef long double DB;
typedef pair <DB, DB> PD;
typedef pair <LL, LL> PLI;
typedef pair <PD, int> PDI;
typedef pair <int, int> PI;
typedef pair <int, PI> PII;
typedef pair <PI, PI> PIII;
typedef set <PI> SI;
typedef vector <int> VI;
 
int Read()
{
    char c; while (c = getchar(), (c != '-') && (c < '0' || c > '9'));
    bool neg = (c == '-'); int ret = (neg ? 0 : c - 48);
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + c - 48;
    return neg ? -ret : ret;
}

const double pi = acos(-1);
const int MAXN = 5005;

struct Event
{
	DB ang;
	int tp;
	PI pt;
} b[MAXN * 20];
PI a[MAXN], rot[4][MAXN], ch[MAXN], p[MAXN], stk[MAXN], h[4][MAXN], cur[4];
int N, M, cnt, hs[4];
DB ans;

PI operator + (PI x, PI y) { return mkp(x.fi + y.fi, x.se + y.se); }
PI operator - (PI x, PI y) { return mkp(x.fi - y.fi, x.se - y.se); }

int Cross(PI x, PI y) { return x.fi * y.se - x.se * y.fi; }

int Dis(PI x) { return x.fi * x.fi + x.se * x.se; }

bool cmp(PI x, PI y)
{
	return Cross(x - p[1], y - p[1]) > 0 || (Cross(x - p[1], y - p[1]) == 0 && Dis(x - p[1]) < Dis(y - p[1]));
}

void Graham(int tp)
{
	if (N == 1) { hs[tp] = 1; h[tp][1] = rot[tp][1]; return; }
	fo (i, 1, N) p[i] = rot[tp][i];
	fo (i, 2, N) if (mkp(p[i].se, p[i].fi) < mkp(p[1].se, p[1].fi)) swap(p[1], p[i]);
	sort(p + 2, p + N + 1, cmp);
	int top = 2; stk[1] = p[1], stk[2] = p[2];
	fo (i, 3, N)
	{
		while (top > 1 && Cross(p[i] - stk[top-1], stk[top] - stk[top-1]) >= 0) -- top;
		stk[++ top] = p[i];
	}
	hs[tp] = top; fo (i, 1, top) h[tp][i] = stk[i];
}

bool cmp2(Event x, Event y) { return x.ang < y.ang; }

void init()
{
	scanf("%d%d", &N, &M);
	fo (i, 1, N)
	{
		int u = Read(), v = Read(), x = u - v, y = u + v; a[i] = mkp(u, v);
		fo (j, 0, 3)
		{
			rot[j][i] = mkp(x, y);
			swap(x, y), y = -y;
		}
	}
	
	fo (i, 0, 3)
		Graham(i);
}

void work()
{
	cnt = 0;
	fo (i, 0, 3)
		fo (j, 1, hs[i])
		{
			int k = (j > 1 ? j - 1 : hs[i]);
			Event ne;
			ne.ang = (j == k ? 0 : atan2l(h[i][j].se - h[i][k].se, h[i][j].fi - h[i][k].fi));
			ne.pt  = h[i][j], ne.tp = i;
			fo (k, -2, 2)
			{
				Event pe = ne; pe.ang += k * 2.0 * pi;
				b[++ cnt] = pe;
			}
		}
	sort(b + 1, b + cnt + 1, cmp2);
	fo (i, 0, 3) cur[i] = mkp(10001, 10001);
	ans = 0;
	
	fo (i, 1, cnt)
	{
		cur[b[i].tp] = b[i].pt;
		fo (k, max(1, M - 3), M)
		{
			LL sx = 0, sy = 0; bool full = 1;
			fo (j, 0, 3)
			{
				int occ = k / 4 + (int) (k % 4 > j);
				if (occ && cur[j].fi > 10000) { full = 0; break; }
				sx += (LL) cur[j].fi * occ, sy += (LL) cur[j].se * occ;
			}
			if (full) ans = max(ans, sqrtl((DB) sx * sx + (DB) sy * sy));
		}
	}
	printf("%.8f\n", (double) ans);
}

int main()
{
	freopen("twirling.in", "r", stdin), freopen("twirling.ans", "w", stdout);
	int cases = Read();
	fo (ca, 1, cases)
	{
		init();
		printf("Case #%d: ", ca);
		work();
	}
	return 0;
}
