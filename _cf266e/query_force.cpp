#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int maxn=1e5+5, mo=1e9+7;

int N, M, A[maxn];

inline ll POW(ll base, int exp)
{
	ll ret(1);
	while (exp--) ret*=base, ret%=mo;
	return ret;
}

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.ans","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	while (M--)
	{
		char type;
		int l, r, x;
		scanf(" %c%d%d%d",&type,&l,&r,&x);
		if (type=='=')
			for (int i=l;i<=r;i++)
				A[i]=x;
		else
		{
			ll ret(0);
			for (int i=l;i<=r;i++)
				ret+=A[i]*POW(i-l+1,x), ret%=mo;
			printf("%I64d\n",ret);
		}
	}
	return 0;
}

