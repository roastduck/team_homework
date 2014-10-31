#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn=1e5+5;

typedef pair<int,int> PI;
typedef pair<PI,PI> PII;
#define fi first
#define se second

#define EDGE(c) ((c)=='T'? 0: (c)=='R'? 1: (c)=='B'? 2: 3)

int N, M, numUD, numLR, numCorner, flag[4][maxn], ans[2][maxn], back[maxn<<1];
PI conn[4][maxn];
bool ULexist;
vector<PII> temp;
vector< vector<PII> > cycle, cycle2;

inline PI _conn(int x, int y) { return conn[x][y]; }

inline int dir(const PII &a)
{
	if (a.fi.fi==0 && a.se.fi==1 || a.fi.fi==1 && a.se.fi==0) return 0;
	if (a.fi.fi==1 && a.se.fi==2 || a.fi.fi==2 && a.se.fi==1) return 1;
	if (a.fi.fi==2 && a.se.fi==3 || a.fi.fi==3 && a.se.fi==2) return 2;
	if (a.fi.fi==3 && a.se.fi==0 || a.fi.fi==0 && a.se.fi==3) return 3;
	if (a.fi.fi==0 && a.se.fi==2 || a.fi.fi==2 && a.se.fi==0) return 4;
	return 5;
}

PI _virtual(int x, int y)
{
	if (x==0 && y<=numCorner) return PI(3,y);
	if (x==0 && y>M-numCorner) return PI(1,M-y+1);
	if (x==1 && y<=numCorner) return PI(0,M-y+1);
	if (x==1 && y>N-numCorner) return PI(2,y+M-N);
	if (x==2 && y<=numCorner) return PI(3,N-y+1);
	if (x==2 && y>M-numCorner) return PI(1,y+N-M);
	if (x==3 && y<=numCorner) return PI(0,y);
	if (x==3 && y>N-numCorner) return PI(2,N-y+1);
	if (N<M)
		if (ULexist)
		{
			if (x==0 && y<=M-numCorner-numUD) return PI(3,y);
			if (x==0 && y>M-numCorner-numUD) return PI(2,y-(M-2*numCorner-numUD));
			if (x==2 && y<=numCorner+numUD) return PI(0,y+(M-2*numCorner-numUD));
			if (x==2 && y>numCorner+numUD) return PI(1,y+N-M);
			if (x==1) return PI(2,y+M-N);
			if (x==3) return PI(0,y);
		} else
		{
			if (x==2 && y<=M-numCorner-numUD) return PI(3,N-y+1);
			if (x==2 && y>M-numCorner-numUD) return PI(0,y-(M-2*numCorner-numUD));
			if (x==0 && y<=numCorner+numUD) return PI(2,y+(M-2*numCorner-numUD));
			if (x==0 && y>numCorner+numUD) return PI(1,M-y+1);
			if (x==1) return PI(0,M-y+1);
			if (x==3) return PI(2,N-y+1);
		}
	else
		if (ULexist)
		{
			if (x==3 && y<=N-numCorner-numLR) return PI(0,y);
			if (x==3 && y>N-numCorner-numLR) return PI(1,y-(N-2*numCorner-numLR));
			if (x==1 && y<=numCorner+numLR) return PI(3,y+(N-2*numCorner-numLR));
			if (x==1 && y>numCorner+numLR) return PI(2,y+M-N);
			if (x==0) return PI(3,y);
			if (x==2) return PI(1,y+N-M);
		} else
		{
			if (x==1 && y<=N-numCorner-numLR) return PI(0,M-y+1);
			if (x==1 && y>N-numCorner-numLR) return PI(3,y-(N-2*numCorner-numLR));
			if (x==3 && y<=numCorner+numLR) return PI(1,y+(N-2*numCorner-numLR));
			if (x==3 && y>numCorner+numLR) return PI(2,N-y+1);
			if (x==0) return PI(1,M-y+1);
			if (x==2) return PI(3,N-y+1);
		}
}

void Travel(PI pos, vector<PII> &cycle, PI(*conn)(int,int))
{
	static int DFN(0);
	DFN++;
	while (flag[pos.fi][pos.se]!=DFN)
	{
		flag[pos.fi][pos.se]=DFN;
		cycle.push_back(PII(pos,conn(pos.fi,pos.se)));
		pos=conn(pos.fi,pos.se);
		flag[pos.fi][pos.se]=DFN;
		pos.fi=(pos.fi+2)%4;
	}
}

void initKMP(vector<PII> &s)
{
	back[0]=-1;
	for (int i=1,j=-1;i<s.size();i++)
	{
		while (~j && s[j+1]!=s[i]) j=back[j];
		if (s[j+1]==s[i]) j++;
		back[i]=j;
	}
}

template <class iter>
bool Check(iter s, int len, vector<PII> &t)
{
	if (t.size()!=len) return false;
	int match(-1);
	for (int i=0,j=-1;i<len*2;i++)
	{
		while (~j && dir(t[j+1])!=dir(s[i%len])) j=back[j];
		if (dir(t[j+1])==dir(s[i%len])) j++;
		if (j==t.size()-1)
		{
			match=i;
			break;
		}
	}
	if (!~match) return false;
	for (int i=match-t.size()+1,j=0;j<t.size();j++,i++)
	{
		ans[t[j].fi.fi&1][t[j].fi.se]=(t[j].fi.fi==s[i%len].fi.fi?s[i%len].fi.se:s[i%len].se.se);
		ans[t[j].se.fi&1][t[j].se.se]=(t[j].se.fi==s[i%len].fi.fi?s[i%len].fi.se:s[i%len].se.se);
	}
	return true;
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N+M;i++)
	{
		int x, y;
		char p, q;
		scanf(" %c %c%d%d",&p,&q,&x,&y);
		conn[EDGE(p)][x]=PI(EDGE(q),y);
		conn[EDGE(q)][y]=PI(EDGE(p),x);
		if (p=='T' && q=='B' || p=='B' && q=='T') numUD++;
		if (p=='L' && q=='R' || p=='R' && q=='L') numLR++;
	}
	if (numUD && numLR) return puts("No solution"), 0;
	for (int i=0;i<4;i++)
		for (int j=1;j<=(i&1?N:M);j++) if (!flag[i][j])
		{
			cycle.push_back(vector<PII>());
			Travel(PI(i,j),cycle.back(),_conn);
		}
	for (int i=0;i<cycle.size();i++) 
	{
		temp.clear();
		numCorner++;
		if (cycle[i].size()==4)
			Travel(PI(0,numCorner),temp,_virtual), initKMP(temp);
		if (!Check(cycle[i].begin(),cycle[i].size(),temp) && !Check(cycle[i].rbegin(),cycle[i].size(),temp))
		{
			numCorner--;
			for (int j=0;!ULexist && j<cycle[i].size();j++)
				ULexist|=(dir(cycle[i][j])==3);
			cycle2.push_back(cycle[i]);
		}
	}
	int pos(numCorner);
	for (int i=0;i<cycle2.size();i++)
	{
		temp.clear();
		Travel(PI(N>M,++pos),temp,_virtual);
		initKMP(temp);
		if (!Check(cycle2[i].begin(),cycle2[i].size(),temp) && !Check(cycle2[i].rbegin(),cycle2[i].size(),temp))
			return puts("No solution"), 0;
	}
	for (int i=1;i<=N;i++)
	{
		printf("%d",ans[1][i]);
		putchar(i<N?' ':'\n');
	}
	for (int i=1;i<=M;i++)
	{
		printf("%d",ans[0][i]);
		putchar(i<M?' ':'\n');
	}
	return 0;
}

