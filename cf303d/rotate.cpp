#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, X;

int POW(int base, int exp)
{
	if (!exp) return 1;
	if (exp&1) return (long long)POW(base,exp-1)*base%(N+1);
	long long tmp(POW(base,exp>>1));
	return tmp*tmp%(N+1);
}

int main()
{
	freopen("rotate.in","r",stdin);
	freopen("rotate.out","w",stdout);
	scanf("%d%d",&N,&X);
	if (N==1)
		return printf("%d\n",X-1>1? X-1: -1), 0;
	for (int i=2; i*i<=N+1; i++)
		if ((N+1)%i==0)
			return puts("-1"), 0;
	for (X--; X>1; X--) if (X%(N+1))
	{
		bool ok(true);
		for (int i=2; i*i<=N && ok; i++)
			if (N%i==0 && POW(X,N/i)==1)
				ok=false;
		if (ok)
			return printf("%d\n",X), 0;
	}
	puts("-1");
	return 0;
}

