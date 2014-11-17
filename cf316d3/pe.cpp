#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int mo=1e9+7;

int N, n, m;
ll a(1), b(1), c;

int main()
{
	freopen("pe.in","r",stdin);
	freopen("pe.out","w",stdout);
	scanf("%d",&N);
	while (N--)
	{
		int x;
		scanf("%d",&x);
		(x==1?n:m)++;
	}
	for (int i=1;i<n;i++)
		c=(b+a*i)%mo, a=b, b=c;
	for (int i=n+1;i<=n+m;i++)
		b=(b*i)%mo;
	printf("%I64d\n",b);
	return 0;
}

