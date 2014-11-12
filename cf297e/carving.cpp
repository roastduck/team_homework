#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn=2e5+5;

int N, A[maxn], f[maxn], in[maxn], crs[maxn];
ll ans, tmp;

void Ins(int x)
{
	for (;x<=2*N;x+=x&-x) f[x]++;
}

int Find(int x)
{
	int ret(0);
	for (;x;x-=x&-x) ret+=f[x];
	return ret;
}

int main()
{
	freopen("carving.in","r",stdin);
	freopen("carving.out","w",stdout);
	scanf("%d",&N);
	ans=(ll)N*(N-1)*(N-2)/6;
	for (int i=1;i<=N;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		A[x]=y, A[y]=x;
	}
	for (int i=1;i<=2*N;i++)
		if (A[i]>i)
		{
			Ins(A[i]);
			int v=Find(A[i]-1)-Find(i);
			in[i]-=v, crs[i]+=v;
			crs[i]-=Find(2*N)-Find(A[i]);
		} else
		{
			in[A[i]]+=Find(i-1)-Find(A[i]);
			crs[A[i]]+=Find(2*N)-Find(i);
			ans-=(ll)in[A[i]]*(N-1-crs[A[i]]-in[A[i]]);
			tmp-=(ll)crs[A[i]]*(N-1-crs[A[i]]);
		}
	printf("%I64d\n",ans+tmp/2);
	return 0;
}

