#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1e5+5, maxans=314000000, inf=0x7f7f7f7f;

typedef pair<int,int> PI;
#define fi first
#define se second

int N, M, who[maxn], ready[maxn], dia[maxn], ans1[maxn], ans2[maxn];
bool flag[maxn];
vector<int> ch[maxn], ori[maxn], tar[maxn];

void Dij()
{
	priority_queue < PI,vector<PI>,greater<PI> > heap;
	for (int i=1;i<=N;i++) if (ans1[i]<inf)
		heap.push(PI(ans1[i],i));
	while (!heap.empty())
	{
		while (!heap.empty() && ans1[heap.top().se]!=heap.top().fi) heap.pop();
		if (heap.empty()) break;
		int x(heap.top().se);
		heap.pop();
		for (int i=0;i<ori[x].size();i++)
			if (++ready[ori[x][i]]==ch[ori[x][i]].size())
			{
				int id=ori[x][i], sum=0;
				for (int j=0;j<ch[id].size();j++)
					sum=min(maxans,sum+ans1[ch[id][j]]);
				sum=min(maxans,sum+dia[id]);
				if (sum<ans1[who[id]])
					heap.push(PI(ans1[who[id]]=sum,who[id]));
			}
	}
	for (int i=1;i<=N;i++)
		if (ans1[i]==inf) ans1[i]=-1;
}

int Dfs(int x)
{
	if (ans2[x]) return ans2[x];
	flag[x]=true;
	for (int i=0;i<tar[x].size();i++)
	{
		int id(tar[x][i]), sum(0);
		for (int j=0;j<ch[id].size();j++)
		{
			int got;
			if (flag[ch[id][j]])
				got=-2;
			else
				got=Dfs(ch[id][j]);
			if (got==-2)
				return flag[x]=false, ans2[x]=-2;
			sum=min(maxans,sum+got);
		}
		sum=min(maxans,sum+dia[id]);
		ans2[x]=max(ans2[x],sum);
	}
	flag[x]=false;
	return ans2[x];
}

int main()
{
	freopen("diamonds.in","r",stdin);
	freopen("diamonds.out","w",stdout);
	scanf("%d%d",&M,&N);
	memset(ans1,127,sizeof ans1);
	for (int i=1;i<=M;i++)
	{
		int k;
		scanf("%d%d",&who[i],&k);
		while (k--)
		{
			int x;
			scanf("%d",&x);
			if (~x)
				ch[i].push_back(x), ori[x].push_back(i);
			else
				dia[i]++;
		}
		if (ch[i].empty())
			ans1[who[i]]=min(ans1[who[i]],dia[i]);
	}
	Dij();
	for (int i=1;i<=M;i++)
	{
		bool bad(false);
		for (int j=0; j<ch[i].size() && !bad; j++)
			bad=!~ans1[ch[i][j]];
		if (!bad)
			tar[who[i]].push_back(i);
	}
	for (int i=1;i<=N;i++) if (!ans2[i])
		if (!~ans1[i])
			ans2[i]=-1;
		else
			Dfs(i);
	for (int i=1;i<=N;i++)
		printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}

