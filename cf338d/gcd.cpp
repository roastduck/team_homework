#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

int K;
ll N, M, lcm(1), m(1), y(0), none, A[10005];

ll gcd(ll a, ll b, ll &p)
{
	ll c, q(1), p0(1), pn;
	if (a<b) swap(a,b), p=0; else p=1;
	while (b)
	{
		pn=(p0-p*q)%lcm, p0=p, p=pn;
		q=a/b, c=a%b;
		a=b, b=c;
	}
	return a;
}

int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%I64d%I64d%d",&N,&M,&K);
	for (int i=0;i<K;i++)
	{
		scanf("%I64d",&A[i]);
		lcm=lcm*A[i]/gcd(A[i],lcm,none);
		if (lcm>N) return puts("NO"), 0;
	}
	for (int i=0;i<K;i++)
	{
		ll a=A[i], g, p;
		g=gcd(a,m,p);
		p*=(-i-y)/g, p%=lcm;
		p=-i-p*a, p=(p%lcm+lcm)%lcm;
		m=m*a/g, y=p;
	}
	if (!y) y=lcm;
	if (y+K-1>M) return puts("NO"), 0;
	for (int i=0;i<K;i++)
		if (gcd(lcm,y+i,none)!=A[i]) return puts("NO"), 0;
	puts("YES");
	return 0;
}

