#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

inline void READ(int &x)
{
	char c;
	x=0;
	do c=getchar(); while (c<'0' || c>'9');
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
}

const int maxn=1e5+5;

int N, Q, next[maxn][2], from[maxn], cnt[10], tot[5000000][10];
char s[maxn];
vector<int> pass[maxn];

inline void Erase(int x)
{
	next[next[x][0]][1]=next[x][1];
	next[next[x][1]][0]=next[x][0];
}

bool Simulate()
{
	static int t(0);
	for (int i=next[0][0], k=0;; i=next[i][k])
	{
		for (int j=0;j<=9;j++) tot[t][j]+=cnt[j];
		if (pass[i].empty()) from[i]=next[i][1];
		pass[i].push_back(t++);
		if (!i) return false;
		if (i==N+1) return true;
		if (s[i]=='<' || s[i]=='>')
		{
			k=(s[i]=='>'?0:1);
			if (!next[i][k] || s[next[i][k]]=='<' || s[next[i][k]]=='>')
				Erase(i);
		} else
		{
			cnt[s[i]-'0']++;
			if (s[i]--=='0') Erase(i);
		}
	}
}

inline int Find(int x, int t)
{
	vector<int>::iterator i=lower_bound(pass[x].begin(),pass[x].end(),t);
	return (i==pass[x].end()?0x7fffffff:*i);
}

int main()
{
	freopen("tape.in","r",stdin);
	freopen("tape.out","w",stdout);
	scanf("%d%d%s",&N,&Q,s+1);
	for (int i=0;i<=N;i++)
		next[i][0]=i+1, next[i+1][1]=i;
	next[0][1]=0, next[N+1][0]=N+1;
	while (!Simulate());
	while (Q--)
	{
		int l, r, t1, t2;
		READ(l), READ(r);
		t1=pass[l][0];
		t2=min(Find(from[l],t1),Find(r+1,t1));
		for (int i=0;i<=9;i++)
		{
			printf("%d",tot[t2][i]-tot[t1][i]);
			putchar(i<9?' ':'\n');
		}
	}
	return 0;
}

