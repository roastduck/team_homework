#include<cstdio>

int N;
unsigned f[200005];

int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d ",&N);
	f[N]=1;
	unsigned *t1=f+N;
	for (int i=N;i;i--)
	{
		char c=getchar();
		if (c=='?')
		{
			f[i]*=25;
			register unsigned *t2=f+i+i;
			if (t1<t2) t2=t1;
			for (register unsigned *j=f+i+1, *k=j-2; j<=t2; j++, k++)
				*k+=*j, *j*=25;
		}
	}
	printf("%u\n",*f);
	return 0;
}

