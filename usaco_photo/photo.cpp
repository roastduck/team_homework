#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=200005, maxm=100000*2+200000*2+5;
int N, M, m, a[maxn], b[maxm], c[maxm], d[maxm], f[maxn], list[maxn], cnt[maxn];
bool flag[maxn];

inline void spfa()
{
	int st, en, TIMER(0);
	list[st=en=0]=0;
	memset(f,127,sizeof f);
	f[0]=0;
	memset(flag,0,sizeof flag);
	flag[0]=true;
	cnt[0]=1;
	while (true)
	{
		int now(list[st]);
		for (int i=a[now];i;i=c[i]) if (f[now]+d[i]<f[b[i]])
		{
			f[b[i]]=f[now]+d[i];
			if (!flag[b[i]])
			{
				if (++cnt[b[i]]>N+1 || f[b[i]]<0 || ++TIMER>5000000)
				{
					f[N]=-1;
					return;
				}
				flag[b[i]]=true;
				en=(en+1)%(N+1);
				list[en]=b[i];
				if (f[list[en]]<f[list[st+1]]) swap(list[en],list[st+1]);
			}
		}
		flag[now]=false;
		if (st==en) return;
		st=(st+1)%(N+1);
	}
}

inline void Ins(int x, int y, int z)
{
	m++;
	b[m]=y;
	c[m]=a[x];
	d[m]=z;
	a[x]=m;
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		Ins(x-1,y,1);
		Ins(y,x-1,-1);
	}
	for (int i=1;i<=N;i++)
	{
		Ins(i-1,i,1);
		Ins(i,i-1,0);
	}
	spfa();
	printf("%d\n",f[N]);
	return 0;
}

