#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

ll N, A, B;

inline ld C(ll n, int m)
{
	if (m>n) return 0;
	ld ret(1);
	for (ll i=1,j=n;i<=m;i++,j--)
		ret*=(ld)j/i;
	return ret;
}

bool Food(ll D)
{
	ld sum(0);
	for (int i=0;i<=60 && i<=D/B;i++)
	{
		ll low=floor((ld)(D-i*B-B)/A)+1, high=floor((ld)(D-i*B)/A);
		sum += C(high+i+1,i+1)-C(low+i,i+1);
		if (sum>=N) return true;
	}
	return false;
}

ll Day()
{
	ll l(0), r(1e15), ret(r);
	while (l<=r)
	{
		ll mid((l+r)>>1);
		if (Food(mid))
			r=mid-1, ret=mid;
		else
			l=mid+1;
	}
	return ret;
}

int main()
{
	freopen("allergy.in","r",stdin);
	freopen("allergy.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		scanf("%I64d%I64d%I64d",&N,&A,&B);
		printf("Case #%d: %I64d\n",t,Day());
	}
	return 0;
}

