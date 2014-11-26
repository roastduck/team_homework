#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int mo=1e9+9;

int N, W, B;

ll POW(ll base, int exp)
{
	if (!exp) return 1;
	if (exp&1) return POW(base,exp-1)*base%mo;
	ll tmp(POW(base,exp>>1));
	return tmp*tmp%mo;
}

ll f(int x)
{
	ll ret(1);
	for (int i=2;i<=x;i++) ret*=i, ret%=mo;
	return ret;
}

ll C(int n, int m)
{
	return f(n)*POW(f(m)*f(n-m)%mo,mo-2)%mo;
}

int main()
{
	freopen("wbw.in","r",stdin);
	freopen("wbw.out","w",stdout);
	scanf("%d%d%d",&N,&W,&B);
	printf("%I64d\n",f(W)*f(B)%mo*(W-1)%mo*C(W+B-3,N-3)%mo);
	return 0;
}

