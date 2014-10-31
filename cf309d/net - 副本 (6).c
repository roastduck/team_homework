#include<stdio.h>

int N, M;
long long ans;

int main()
{
	freopen("net.in","r",stdin);
	freopen("net.out","w",stdout);
	scanf("%d%d", &N, &M);
	register int x, y, z;
	for (x=M+1; x+x-1<=N; x++)
		for (z=M+1, y=N-M; z+M<=N && y>M; z++)
		{
			for (; y>M && 2*x*(N+1)<=2*x*x+(N+1-x)*z+(x+z)*y; y--);
			ans+=(y-M)*(1+(x+x<=N));
		}
	printf("%I64d\n",ans*3);
	return 0;
}

