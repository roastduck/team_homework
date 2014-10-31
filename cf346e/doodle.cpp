#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

int MAX(int a, int n, int p, bool first=true)
{
	if ((ll)a*n<p) return first?a:max(a,p-a*n);
	return MAX(min(p%a,a-p%a),(ll)a*n/p-((ll)a*n%p<p/a*a-a),a,false);
}

int main()
{
	freopen("doodle.in","r",stdin);
	freopen("doodle.out","w",stdout);
	int T;
	for (scanf("%d",&T);T;T--)
	{
		int a, n, p, h;
		scanf("%d%d%d%d",&a,&n,&p,&h);
		puts(MAX(a%p,n,p)<=h?"YES":"NO");
	}
	return 0;
}

