#include<stdio.h>

int N, M;
long long ans;

int main()
{
	freopen("net.in","r",stdin);
	freopen("net.out","w",stdout);
	scanf("%d%d",&N,&M);
	int x, z;
	register int y, v;
	for (x=M+1;2*x<=N+1;x++)
	{
		int st=(N-M-2*x)*(N+1-x)/(M-N-x);
		if (st<=M) st=M+1;
		ans+=(st-M-1)*(N-M-M);
		y=N-M;
		for (z=st, y=N-M, v=(x-N-1)*(x+x-y)+(x+y)*z; z<=N-M && y>M; z++, v+=x+y)
		{
			while (y>M && v>=0) y--, v+=x-N-1-z;
			ans+=(y-M)*((2*x<N+1)+1);
		}
	}
	printf("%I64d\n",ans*3);
	return 0;
}

