#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

int N, M, father[maxn], next[maxn];

int get(int x)
{
	return father[x]==x? x: father[x]=get(father[x]);
}

int main()
{
	freopen("button.in","r",stdin);
	freopen("button.out","w",stdout);
	scanf("%d",&N);
	if (N&1) return puts("-1"), 0;
	M=N/2;
	memset(next,255,sizeof next);
	for (int i=0;i<N;i++) if (!~next[i])
		for (int j=i;!~next[j];j=next[j])
		{
			next[j]=(~next[(j+M)%N]? next[(j+M)%N]^1: j*2%N);
			father[j]=i;
		}
	for (int i=0;i<N;i++) if (get(i)!=get((i+M)%N))
	{
		father[father[i]]=father[(i+M)%N];
		swap(next[i],next[(i+M)%N]);
	}
	int x(0);
	do printf("%d ",x); while (x=next[x]);
	puts("0");
	return 0;
}

