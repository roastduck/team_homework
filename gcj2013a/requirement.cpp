#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn=1005;

int C;
ll N, X, ans, S[maxn], E[maxn], T[maxn], R[maxn];

inline void upd(double p, ll t, ll T, ll R, ll &up, ll &dn)
{
	ll b=floor(p)+1, a=ceil(p)-1;
	if (p>=T && p<=R)
	{
		if (a-t>=0) up=min(up,a-t);
		if (b-t<=0) dn=max(dn,b-t);
	}
}

void test(ll x, ll t)
{
	if (t<0 || t>X) return;
	x=(x%N+N)%N;
	ll up(X-t), dn(-t);
	for (int i=1;i<=C;i++)
	{
		if ((x-S[i]-t+T[i])%N==0 && t>=T[i] && t<=R[i]) return;
		ll k1, k2;
		long double p, q;
		p=(long double)(x+t-S[i]+T[i])/2;
		q=(long double)(x+t-S[i]+T[i]+N)/2;
		k1=ceil((T[i]-p)/N), k2=floor((R[i]-p)/N);
		for (ll k=k1;k<=k2;k++)
			upd(p+k*N,t,T[i],R[i],up,dn);
		k1=ceil((T[i]-q)/N), k2=floor((R[i]-q)/N);
		for (ll k=k1;k<=k2;k++)
			upd(q+k*N,t,T[i],R[i],up,dn);
		if (up-dn<=ans) return;
	}
	ans=/*max(ans,*/up-dn/*)*/;
}

int main()
{
	freopen("requirement.in","r",stdin);
	freopen("requirement.out","w",stdout);
	int _T;
	scanf("%d",&_T);
	for (int _t=1;_t<=_T;_t++)
	{
		scanf("%d%I64d%I64d",&C,&X,&N);
		for (int i=1;i<=C;i++)
		{
			scanf("%I64d%I64d%I64d",&S[i],&E[i],&T[i]);
			S[i]%=N, E[i]%=N;
			R[i]=T[i]+((E[i]-S[i])%N+N)%N;
		}
		ans=0;
		if (!C) ans=X;
		for (int i=1;i<=C;i++)
		{
			test(S[i]-1,T[i]);
			test(S[i],T[i]-1);
			test(S[i]-1,T[i]-1);
			test(E[i]+1,R[i]);
			test(E[i],R[i]+1);
			test(E[i]+1,R[i]+1);
		}
		printf("Case #%d: %I64d\n",_t,ans);
	}
	return 0;
}

