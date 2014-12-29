#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

struct VTX
{
	int x, y;
	double d;
	VTX() {}
	VTX(double _d) : d(_d) {}
};

inline bool operator<(const VTX &a, const VTX &b) { return a.d<b.d; }

const int maxn=1e5+5;
const double pi=acos(-1);

int N;
ll ans;
VTX V[maxn];

int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d",&V[i].x,&V[i].y);
		V[i].d=atan2(V[i].y,V[i].x);
	}
	sort(V+1,V+N+1);
	for (int i=1;i<=N;i++)
	{
		double d=V[i].d+pi;
		if (d>pi) d-=2*pi;
		int n=(upper_bound(V+1,V+N+1,d)-V-i-1+N)%N;
		ans+=(ll)n*(n-1)/2;
	}
	printf("%I64d\n",(ll)N*(N-1)*(N-2)/6-ans);
	return 0;
}

