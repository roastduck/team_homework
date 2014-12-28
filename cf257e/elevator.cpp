#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=100005;

struct TASK { int t, s, f, id; };
inline bool operator<(const TASK &a, const TASK &b) { return a.t<b.t; }

#define it iterator

int N, M;
long long ans[maxn];
TASK task[maxn];
vector<int> wait[maxn], dest[maxn];
set<int> event;

int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
		scanf("%d%d%d",&task[i].t,&task[i].s,&task[i].f), task[i].id=i;
	sort(task+1,task+N+1);
	long long t=1;
	for (int i=1,pos=1,up=0,down=0; !event.empty() || i<=N;)
	{
		for (;i<=N && task[i].t==t;i++)
		{
			wait[task[i].s].push_back(i);
			event.insert(task[i].s);
			if (task[i].s>pos) up++;
			if (task[i].s<pos) down++;
		}
		for (vector<int>::it k=wait[pos].begin(); k!=wait[pos].end(); k++)
		{
			dest[task[*k].f].push_back(*k);
			event.insert(task[*k].f);
			(task[*k].f>pos?up:down)++;
		}
		for (vector<int>::it k=dest[pos].begin(); k!=dest[pos].end(); k++)
			ans[task[*k].id]=t;
		wait[pos].clear(), dest[pos].clear(), event.erase(pos);
		int step=i>N?1e9:task[i].t-t;
		if (!event.empty())
		{
			set<int>::it next=event.upper_bound(pos);
			if (up>=down)
			{
				step=min(step,*next-pos);
				pos+=step;
				if (pos==*next)
					up-=wait[*next].size()+dest[*next].size();
			}
			else
			{
				next--;
				step=min(step,pos-*next);
				pos-=step;
				if (pos==*next)
					down-=wait[*next].size()+dest[*next].size();
			}
		}
		t+=step;
	}
	for (int i=1;i<=N;i++) printf("%I64d\n",ans[i]);
	return 0;
}

