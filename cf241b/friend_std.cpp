// STD !!

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;
const int MaxN = 50010;

int n,m;
int a[MaxN];

int main()
{
	freopen("friend.in","r",stdin), freopen("friend.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int bound=0;
	for(int i=29;i>=0;i--){
		map<int,int> cnt;int sum=0;
		for(int j=1;j<=n;j++) cnt[a[j]>>i]++;bound<<=1;
		for(map<int,int> :: iterator p=cnt.begin();p!=cnt.end();p++){
			int u=p->first,v=u^(bound+1);
			if(u<v) sum+=p->second*cnt[v];
		}
		if(sum>=m) bound++;
		else m-=sum;
	}
	LL res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int v=a[i]^a[j];
			if (v>bound) res+=v;
		}
	}
	(res+=1LL*m*bound)%=MOD;
    printf("%I64d\n",res);
    return 0;
}

// STD !!
