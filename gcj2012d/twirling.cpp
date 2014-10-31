#include<cmath>
#include<cstdio>
#include<cstring>
#include<complex>
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

const int maxn=5005;

typedef complex<int> CP;

int N, M, n[4];
CP A[4][maxn], C[4][maxn];

inline complex<double> CDB(const CP &z) { return complex<double>(z.real(),z.imag()); }

struct ACW
{
	CP O;
	ACW(const CP &_O) : O(_O) {}
	bool operator()(CP A, CP B)
	{
		A-=O, B-=O;
		long long tmp((long long)A.real()*B.imag()-B.real()*A.imag());
		if (tmp>0) return true;
		if (tmp<0) return false;
		return abs(A.real())+abs(A.imag())<abs(B.real())+abs(B.imag());
	}
};

void Convex(CP A[], CP C[], int &n)
{
	int L(1);
	for (int i=2;i<=N;i++)
		if (A[i].real()<A[L].real() || A[i].real()==A[L].real() && A[i].imag()<A[L].imag()) L=i;
	swap(A[1],A[L]);
	sort(A+2,A+N+1,ACW(A[1]));
	n=0;
	for (int i=1;i<=N;i++)
	{
		while (n>1 && ACW(C[n-2])(A[i],C[n-1])) n--;
		C[n++]=A[i];
	}
}

double Tour()
{
	int it[4];
	long double ret(0);
	memset(it,0,sizeof it);
	for (int i=1;i<=n[0]+n[1]+n[2]+n[3];i++)
	{
		for (int m=max(1,M-3);m<=M;m++)
		{
			long long sumx(0), sumy(0);
			for (int k=0;k<4;k++)
				sumx+=(long long)(m-k+3)/4*C[k][it[k]].real(), sumy+=(long long)(m-k+3)/4*C[k][it[k]].imag();
			ret=max(ret,(long double)sumx*sumx+(long double)sumy*sumy);
		}
		int d(0);
		for (int k=1;k<4;k++)
			if ((CDB(C[k][(it[k]+1)%n[k]]-C[k][it[k]])/CDB(C[d][(it[d]+1)%n[d]]-C[d][it[d]])).imag()<0)
				d=k;
		it[d]=(it[d]+1)%n[d];
	}
	return sqrt(ret);
}

int main()
{
	freopen("twirling.in","r",stdin);
	freopen("twirling.out","w",stdout);
	int T;
	READ(T);
	for (int t=1;t<=T;t++)
	{
		READ(N), READ(M);
		for (int i=1;i<=N;i++)
		{
			int x, y;
			READ(x), READ(y);
			CP k(1,-1);
			for (int j=0;j<4;j++,k*=CP(0,-1))
				A[j][i]=k*CP(x,y);
		}
		for (int i=0;i<4;i++)
			Convex(A[i],C[i],n[i]);
		printf("Case #%d: %.8f\n",t,Tour());
	}
	return 0;
}

