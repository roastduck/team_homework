#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline void READ(int &x)
{
	char c;
	x=0;
	bool minus(false);
	do c=getchar(); while ((c<'0' || c>'9') && c!='-');
	if (c=='-') c=getchar(), minus=true;
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
	if (minus) x=-x;
}

const int maxn=36;

int N, X, ans(0x80000000), A[maxn][maxn];

int main()
{
	freopen("flipboard.in","r",stdin);
	freopen("flipboard.out","w",stdout);
	READ(N);
	X=N/2;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			READ(A[i][j]);
	for (long long mid=0;mid<(1<<X<<1);mid++)
	{
		int tot(0);
		bool C(mid&(1<<X));
		long long MID=(C? mid+(~mid<<X<<1): mid+(mid<<X<<1));
		for (int i=0;i<N;i++)
			tot+=(MID&(1ll<<i)?-1:1)*A[X][i];
		for (int i=0;i<X;i++)
		{
			int now1(A[i][X]+(C?-1:1)*A[i+X+1][X]), now2(-now1);
			for (int j=0;j<X;j++)
			{
				bool L(MID&(1ll<<j)), R(L^C);
				now1+=abs(A[i][j]+A[i][j+X+1]+(L?-1:1)*A[i+X+1][j]+(R?-1:1)*A[i+X+1][j+X+1]);
				now2+=abs(A[i][j]-A[i][j+X+1]+(L?-1:1)*A[i+X+1][j]-(R?-1:1)*A[i+X+1][j+X+1]);
			}
			tot+=max(now1,now2);
		}
		ans=max(ans,tot);
	}
	printf("%d\n",ans);
	return 0;
}

