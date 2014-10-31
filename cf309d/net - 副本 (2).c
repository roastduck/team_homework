#include<stdio.h>

int N, M;
long long ans;

int main()
{
	freopen("net.in","r",stdin);
	freopen("net.out","w",stdout);
	scanf("%d%d",&N,&M);
	register int x, z, y;
	for (x=M+1;2*x<=N+1;x++)
	{
		int st=(long long)(N-M-2*x)*(N+1-x)/(M-N-x);
		if (st<=M) st=M+1;
		ans+=(st-M-1)*(N-M-M);
		register int a=N+1-x+st-1;
		register long long b=(long long)x*(2*(N+1-x)-st+1)-1;
		y=M+1;
		if (2*x<N+1)
			for (z=N-2*M;z && y>M;z--)
				ans+=((y=(b-=x)/++a)-M)*2;
		else
			for (z=N-2*M;z && y>M;z--)
				ans+=((y=(b-=x)/++a)-M);
	}
	printf("%I64d\n",ans*3);
	return 0;
}

