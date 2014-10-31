#include<cstdio>
#include<cstring>
#include<set>
#include<numeric>
#include<algorithm>
#include<functional>
using namespace std;

const int maxn=500005;

int N, A[maxn];
multiset< int,greater<int> > S;

int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d",&N);
	long long ans(0);
	for (int i=1;i<=N;i++)
		scanf("%d",&A[i]), ans+=A[i];
	sort(A+1,A+N+1,greater<int>());
	for (int i=1,j=1;i<=N;i=j)
	{
		while (j<=N && A[j]==A[i]) j++;
		int k1(i), k2(j), k3, v(A[i]), len(min((j-1)/2,i-1));
		while (k2-i>i-1) A[--k2]=0;
		k3=k2+((k2-1)&1);
		multiset<int>::iterator p(S.end()), q;
		for (int l=i/2+1;l>len-(k2-i)+1;l--) p--;
		q=p;
		for (; p!=S.end() && *p>v; p++)
		{
			A[k1++]=*p;
			k3--;
			if (k3<k2 && k3>=k1) A[k3]=max(0,A[k3]-*p+v);
		}
		S.erase(q,S.end());
		S.insert(A+i,A+i+len-S.size());
		while (S.size()<j/2) S.insert(0);
	}
	printf("%I64d\n",ans-accumulate(S.begin(),S.end(),0ll));
	return 0;
}

