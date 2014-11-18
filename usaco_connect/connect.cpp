#include<cassert>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

inline void READ(int &x)
{
	char c;
	x=0;
	do c=getchar(); while (c<'0' || c>'9');
	do x=x*10+c-48, c=getchar(); while (c>='0' && c<='9');
}

const int maxc=15005, maxq=50005;
const int walk[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

int Q, K, R, C, n, R1[maxq], C1[maxq], R2[maxq], C2[maxq], A[maxq][2];
bool cur[maxq], ans[50][maxq], vert[maxc], up[maxc], down[maxc];
char T[maxq];

void Dfs(int t, int Xr, int preans)
{
	if (t>Q)
	{
		memcpy(ans[++n],cur,sizeof cur);
		return;
	}
	Xr=((Xr+A[t][preans])&1048575);
	int r1(R1[t]^Xr), c1(C1[t]^Xr), r2(R2[t]^Xr), c2(C2[t]^Xr);
	if (!r1 || r1>R || !c1 || c1>C || !r2 || r2>R || !c2 || c2>C) return;
	if (T[t]=='T')
	{
		cur[t]=false, Dfs(t+1,Xr,0);
		cur[t]=true, Dfs(t+1,Xr,1);
	} else
		Dfs(t+1,Xr,preans);
}

void upd(int r1, int c1, int r2, int c2, bool v)
{
	if (c1==c2)
	{
		vert[c1]=v;
		return;
	}
	if (c1>c2) swap(r1,r2), swap(c1,c2);
	(r1==1?up[c1]:down[c1])=v;
}

bool Check(int r1, int c1, int r2, int c2)
{
	if (c1>c2) swap(r1,r2), swap(c1,c2);
	bool UP(false), DOWN(false);
	(r1==1?UP:DOWN)=true;
	for (;c1<c2;c1++)
	{
		if (!UP && !DOWN) return false;
		if (vert[c1]) UP=DOWN=true;
		UP&=up[c1], DOWN&=down[c1];
	}
	return vert[c1]||(r2==1?UP:DOWN);
}

int main()
{
	freopen("connect.in","r",stdin);
	freopen("connect.out","w",stdout);
	READ(K), READ(R), READ(C);
	for (int i=1;i<=K;i++)
	{
		int r1, c1, r2, c2;
		READ(r1), READ(c1), READ(r2), READ(c2);
		upd(r1,c1,r2,c2,true);
	}
	for (Q=1;;Q++)
	{
		scanf(" %c",&T[Q]);
		if (T[Q]=='E') break;
		READ(R1[Q]), READ(C1[Q]), READ(R2[Q]), READ(C2[Q]), READ(A[Q][0]), READ(A[Q][1]);
	}
	Q--;
	Dfs(1,0,0);
	int Xr(0), preans(0);
	for (int i=1;i<=Q;i++)
	{
		Xr=((Xr+A[i][preans])&1048575);
		R1[i]^=Xr, C1[i]^=Xr, R2[i]^=Xr, C2[i]^=Xr;
		if (T[i]=='T')
		{
			bool check(false);
			for (int j=2;j<=n&&!check;j++) check=(ans[j][i]!=ans[1][i]);
			if (!check)
			{
				preans=ans[1][i];
				continue;
			}
			preans=Check(R1[i],C1[i],R2[i],C2[i]);
			for (int j=1;j<=n;j++) if (ans[j][i]!=preans)
				swap(ans[j][i],ans[n--][i]);
		} else
			upd(R1[i],C1[i],R2[i],C2[i],T[i]=='O');
	}
	assert(n==1);
	for (int i=1;i<=Q;i++) if (T[i]=='T')
		puts(ans[1][i]?"Y":"N");
	return 0;
}

