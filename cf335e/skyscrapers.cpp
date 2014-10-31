#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, H;
char s[10];

int main()
{
	freopen("skyscrapers.in","r",stdin);
	freopen("skyscrapers.out","w",stdout);
	scanf("%s%d%d",s,&N,&H);
	if (s[0]=='B')
		printf("%d\n",N);
	else
	{
		double ans(N), _2i(2);
		for (int i=1;i<=H;i++,_2i*=2)
		{
			double tmp(1);
			for (int j=1;j<=N;j++,tmp*=1-1/_2i)
				ans+=(N-j)*1/(_2i*_2i)*tmp*(_2i-_2i/2*(1+(j-1)/(_2i-1)));
		}
		printf("%.11f\n",ans);
	}
	return 0;
}

