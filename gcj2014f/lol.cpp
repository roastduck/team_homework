#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1005, maxs=405;

int N, R, G;
double K, P[maxn], f[maxs];

void Calc()
{
	double sum(0);
	for (int i=1;i<=N;i++)
		sum+=(P[i]-K)/N;
	for (int i=0;i<G;i++)
		f[i]=sum;
	for (int i=G;i<=R*G;i++)
	{
		f[i]=-1e100;
		double a(0), b(0);
		for (int j=1;j<=G;j++)
			a+=f[i-j];
		for (int j=N-1;j>=0;j--)
		{
			b+=P[j+1]-K;
			f[i]=max(f[i],(a*j+b)/(i<R*G?N-j:N));
		}
	}
}

int main()
{
	freopen("lol.in","r",stdin);
	freopen("lol.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		scanf("%d%d%d",&N,&R,&G);
		for (int i=1;i<=N;i++)
			scanf("%lf",&P[i]);
		sort(P+1,P+N+1);
		double l(0), r(1);
		while (r-l>1e-12)
		{
			K=(l+r)*0.5;
			Calc();
			(f[R*G]>0?l:r)=K;
		}
		printf("Case #%d: %.12f\n",t,l);
	}
	return 0;
}

