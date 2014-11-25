// STD !!!

#include<cstdio>
#include<algorithm>
using namespace std;
const int q[2]={1,-1};
int n,x,a[35][35];
int main()
{
	freopen("flipboard.in","r",stdin);
	freopen("flipboard.ans","w",stdout);
	scanf("%d",&n);
	x=(n+1)>>1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	int ans=0;
	for(int k=0;k<(1<<x);++k)
	{
		int sum=0;
		for(int i=1;i<=x;++i)
			sum+=a[i][x]*q[k>>(i-1)&1]+a[i+x][x]*q[(k>>(i-1)&1)^(k>>(x-1)&1)];
		for(int i=1;i<x;++i)
		{
			int now=0;
			for(int p=0;p<2;++p)
			{
				int v=a[x][i]*q[p]+a[x][i+x]*q[p^(k>>(x-1)&1)];
				for(int j=1;j<x;++j)
					v+=abs(a[j][i]+a[j][i+x]*q[k>>(j-1)&1]+a[j+x][i]*q[p]+a[j+x][i+x]*q[(k>>(j-1)&1)^p^(k>>(x-1)&1)]);
				now=max(now,v);
			}
			sum+=now;
		}
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}


// STD !!!
