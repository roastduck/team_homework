#include<cstdio>

int N, M;
long long ans;

int main()
{
    scanf("%d%d",&N,&M);
    for (register int x=M+1; x+x-1<=N; x++)
        for (register int z=M+1, y=N-M; z+M<=N && y>M; z++)
        {
            for (; y>M && 2*x*(N+1)<=2*x*x+(N+1-x)*z+(x+z)*y; y--);
            ans+=(y-M)*((x+x<=N)+1);
        }
    printf("%I64d\n",ans*3);
    return 0;
}

