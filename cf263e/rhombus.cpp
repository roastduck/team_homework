#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

template <class T>
inline void READ(T &x)
{
	char c;
	x=0;
	do c=getchar(); while (c<'0' || c>'9');
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
}

const int maxn=1005;
typedef long long ll;
typedef ll arr[maxn][maxn];

int N, M, K;
arr A, B, C, D, fA, fB, fC, fD;

#define epk(i,j,k) (uk[i][j]-(u[i][j]-u[(i)-(k)][j])*((i)-(k))-uk[(i)-(k)][j])

void Init(int N, int M, int K, arr A, arr f)
{
	if (K<=0) return;
	static arr u, uk, ur;
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			u[i][j]=u[i-1][j]+A[i][j];
			uk[i][j]=uk[i-1][j]+A[i][j]*i;
			ur[i][i+j]=ur[i-1][i+j]+A[i][j];
		}
	for (int i=K;i<=N-K+1;i++)
	{
		ll nw=0, nwk=0;
		for (int j=K;j;j--)
		{
			nw+=u[i][j]-u[i-j][j];
			nwk+=epk(i,j,j);
		}
		f[i][K]=nwk;
		for (int j=K+1;j<=M-K+1;j++)
		{
			nwk+=epk(i,j,K)-nw;
			nw+=u[i][j]-u[i-K][j]-ur[i][i+j-K]+ur[i-K][i+j-K];
			f[i][j]=nwk;
		}
	}
}

int main()
{
	freopen("rhombus.in","r",stdin);
	freopen("rhombus.out","w",stdout);
	READ(N), READ(M), READ(K);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			int x;
			READ(x);
			A[i][j]=B[M-j+1][i]=C[N-i+1][M-j+1]=D[j][N-i+1]=x;
		}
	Init(N,M,K,A,fA);
	Init(M,N,K-1,B,fB);
	Init(N,M,K-2,C,fC);
	Init(M,N,K-1,D,fD);
	int x, y;
	ll MAX=-1;
	for (int i=K;i<=N-K+1;i++)
		for (int j=K;j<=M-K+1;j++)
		{
			ll cur=fA[i][j]+fB[M-j][i]+fC[N-i][M-j]+fD[j][N-i];
			if (cur>MAX)
				MAX=cur, x=i, y=j;
		}
	printf("%d %d\n",x,y);
	return 0;
}

