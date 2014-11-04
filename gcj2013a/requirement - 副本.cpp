#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn=1005;

int C;
ll N, X, ans, S[maxn], E[maxn], T[maxn], R[maxn];

inline void upd(double p, ll offset, ll t, ll &up, ll &dn)
{
	p+=offset;
	ll b=floor(p)+1, a=ceil(p)-1;
	if (p>=T[i] && p<=R[i])
	{
		up=min(up,max(0,a-t+offset));
		dn=max(dn,max(0,b-t-offset));
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
		ll a, b, c, d, k1, k2;
		long double p, q;
		p=(long double)(x+t-S[i]+T[i])/2;
		q=(long double)(x+t-S[i]+T[i]+N)/2;
		b=floor(p)+1, a=ceil(p)-1;
		d=floor(q)+1, c=ceil(q)-1;
		k1=ceil((T[i]-p)/N), k2=floor((R[i]-p)/N);
		for (ll k=k1;k<=k2;k++) upd(p,k*N,t,up,dn);
		k1=ceil((T[i]-q)/N), k2=floor((R[i]-q)/N);
		for (ll k=k1;k<=k2;k++) upd(q,k*N,t,up,dn);
		/*if (fmodl(fmodl(p-t,N)+N,N)+t>=T[i] && fmodl(fmodl(p-t,N)+N,N)+t<=R[i])
			up=min(up,((a-t)%N+N)%N);
		if (fmodl(fmodl(p-t,N)-N,N)+t>=T[i] && fmodl(fmodl(p-t,N)-N,N)+t<=R[i])
			dn=max(dn,((b-t)%N-N)%N);
		if (fmodl(fmodl(q-t,N)+N,N)+t>=T[i] && fmodl(fmodl(q-t,N)+N,N)+t<=R[i])
			up=min(up,((c-t)%N+N)%N);
		if (fmodl(fmodl(q-t,N)-N,N)+t>=T[i] && fmodl(fmodl(q-t,N)-N,N)+t<=R[i])
			dn=max(dn,((d-t)%N-N)%N);*/
	}
	ans=max(ans,up-dn);
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

