#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<complex>
using namespace std;

const int maxn=1000005;
const double eps=0.5, pi=acos(-1);

typedef complex<double> comp;

int N, M, ansnum, ans[maxn], rev[2100000];
bool ori[maxn];
comp a[2100000], b[2100000];

void initRev(int n)
{
	int now(0);
	for (int i=0;i<n;i++)
	{
		rev[i]=now;
		int k(20);
		while (now&(1<<k)) now^=(1<<(k--));
		now^=(1<<k);
	}
}

void FFT(int n, comp a[], comp A[], int k)
{
	for (int i=0;i<n;i++) A[rev[i]]=a[i];
	for (int m=1;m<n;m<<=1)
	{
		comp omega_m(cos(2*pi*k/(m<<1)),sin(2*pi*k/(m<<1)));
		for (int i=0;i<n;i+=m+m)
		{
			comp omega(1);
			for (int j=0;j<m;j++)
			{
				comp s(A[i+j]), t(A[i+j+m]);
				A[i+j]=s+omega*t;
				A[i+j+m]=s-omega*t;
				omega*=omega_m;
			}
		}
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		int x;
		scanf("%d",&x);
		ori[x]=true;
		a[x]=1;
	}
	int n(1<<21);
	initRev(n);
	FFT(n,a,b,1);
	for (int i=0;i<n;i++) b[i]*=b[i];
	FFT(n,b,a,-1);
	for (int i=1;i<=M;i++)
	{
		if (a[i].real()>eps*n && !ori[i])
		{
			printf("NO\n");
			return 0;
		}
		if (a[i].real()<eps*n && ori[i])
			ans[++ansnum]=i;
	}
	printf("YES\n%d\n",ansnum);
	for (int i=1;i<ansnum;i++) printf("%d ",ans[i]);
	printf("%d\n",ans[ansnum]);
	return 0;
}

