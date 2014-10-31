#include<stdio.h>

int N, M;
long long ans;

int main()
{
	freopen("net.in","r",stdin);
	freopen("net.out","w",stdout);
	scanf("%d%d",&N,&M);
	register int z, y, x;
	for (x=M+1;2*x<=N+1;x++)
	{
		int st=(N-M-2*x)*(N+1-x)/(M-N-x);
		if (st<=M) st=M+1;
		ans+=(st-M-1)*(N-M-M);
		for (z=st,y=N-M; z<=N-M && y>M; z++)
		{
			while (y>M && (x-N-1)*(x+x-y)+(x+y)*z>=0) y--;
			ans+=(y-M)*((2*x<N+1)+1);
		}
	}
	printf("%I64d\n",ans*3);
	return 0;
}

