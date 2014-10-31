#include<cstdio>
#include<cstring>
#include<set>
#include<deque>
#include<algorithm>
using namespace std;

typedef deque<int> VEC;
typedef set<VEC> SET;

const int maxn=55, mo=1e9+7;

int N, M, f[maxn*2][maxn][maxn], tmp[maxn*2][maxn][maxn], g[maxn*2][maxn];
bool conn[maxn][maxn];
VEC E[maxn][maxn], NOW, NEW;
SET BEG, EXP, PRE;

inline void add(int &a, int b) { a+=b, a%=mo; }

void Expand(SET &S, bool pre, bool exp)
{
	while (true)
	{
		NOW=NEW;
		NEW.clear();
		for (int i=0;i<NOW.size()-1;i++)
		{
			if (!conn[NOW[i]][NOW[i+1]]) return;
			for (VEC::iterator j=E[NOW[i]][NOW[i+1]].begin(); j!=E[NOW[i]][NOW[i+1]].end(); j++)
				NEW.push_back(*j);
		}
		if (pre) NEW.push_front(NOW.front());
		if (exp) NEW.push_back(NOW.back());
		if (NEW.size()<=1 || NEW.size()>2*N) return;
		if (NEW.size()==NOW.size() && NOW==NEW)
		{
			S.insert(NOW);
			return;
		}
	}
}

int main()
{
	freopen("dejavu.in","r",stdin);
	freopen("dejavu.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		int x, y, k;
		scanf("%d%d%d",&x,&y,&k);
		//E[x][y].reserve(k);
		conn[x][y]=true;
		while (k--)
		{
			int p;
			scanf("%d",&p);
			E[x][y].push_back(p);
		}
	}
	//NOW.reserve(2*N);
	//NEW.reserve(2*N);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=N;j++) if (conn[i][j] && !E[i][j].empty())
		{
			NEW.clear(), NEW.push_back(i), NEW.push_back(j);
			Expand(BEG,0,0);
			if (E[i][j].front()==j)
			{
				NEW.clear(), NEW.push_back(i), NEW.push_back(j);
				Expand(EXP,1,0);
			}
			if (E[i][j].back()==i)
			{
				NEW.clear(), NEW.push_back(i), NEW.push_back(j);
				Expand(PRE,0,1);
			}
		}
	for (SET::iterator i=BEG.begin(); i!=BEG.end(); i++)
		f[i->size()-1][i->front()][i->back()]++;
	for (int i=0;i<2*N;i++)
		for (SET::iterator j=EXP.begin(); j!=EXP.end(); j++)
			if (i+j->size()-1<=2*N)
				for (int p=1;p<=N;p++)
					add(f[i+j->size()-1][p][j->back()],f[i][p][j->front()]);
	for (int i=0;i<2*N;i++)
		for (SET::iterator j=PRE.begin(); j!=PRE.end(); j++)
			if (i+j->size()-1<=2*N)
				for (int p=1;p<=N;p++)
					add(f[i+j->size()-1][j->front()][p],f[i][j->back()][p]);
	for (int l=1;l<2*N;l++)
		for (int p=1;p<=N;p++)
			for (int i=1;i<=N;i++) if (conn[p][i] && E[p][i].empty())
				for (int j=1;j<=N;j++)
					add(tmp[l+1][p][j],f[l][i][j]);
	for (int l=1;l<=2*N;l++)
		for (int i=1;i<=N;i++)
			for (int j=1;j<=N;j++)
				add(g[l][j],f[l][i][j]);
	for (int l=1;l<2*N;l++)
		for (int l2=1;l+l2<=2*N;l2++)
			for (int i=1;i<=N;i++)
				for (int j=1;j<=N;j++)
					add(g[l+l2][j],(long long)g[l][i]*tmp[l2][i][j]%mo);
	for (int i=1;i<=2*N;i++)
	{
		int sum(0);
		for (int j=1;j<=N;j++)
			add(sum,g[i][j]);
		printf("%d\n",sum);
	}
	return 0;
}

