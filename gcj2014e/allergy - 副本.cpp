#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const ll inf=(1ll<<60);

ll N, A, B;

inline ll gcd(ll a, ll b)
{
	ll c;
	if (a<b) swap(a,b);
	while (b) c=a%b, a=b, b=c;
	return a;
}

inline ll C(ll n, int m)
{
	if (m>n) return 0;
	ll ret(1);
	static int num[65];
	for (int i=1;i<=m;i++) num[i]=i;
	for (ll i=n-m+1;i<=n;i++)
	{
		ll t(i);
		for (int j=1;j<=m;j++)
		{
			ll g(gcd(t,num[j]));
			num[j]/=g, t/=g;
		}
		if (ret>inf/t) return inf;
		ret*=t;
	}
	return ret;
}

bool Food(ll D)
{
	ll sum(0);
	for (int i=0;i<=60 && i<=D/B;i++)
	{
		ll low=floor((long double)(D-i*B-B)/A)+1, high=floor((long double)(D-i*B)/A);
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

