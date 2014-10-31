#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=105;

int N, A, ans[maxn];
char P[maxn][maxn];
bool flag[maxn], mark[maxn];

void dfs(int x)
{
	mark[x]=true;
	for (int i=0;i<N;i++) if (P[x][i]=='Y' && !mark[i])
		dfs(i);
}

bool valid(int n)
{
	int B(ans[0]);
	for (int i=1;i<=n;i++)
		if (P[B][ans[i]]=='N') B=ans[i];
	if (flag[A] && A!=B) return false;
	memcpy(mark,flag,sizeof flag);
	if (!flag[A]) dfs(A);
	for (int i=0;i<N;i++)
		if (P[B][i]=='Y') mark[i]=true;
	int cnt(0);
	for (int i=0;i<N;i++) cnt+=mark[i];
	return cnt==N;
}

int main()
{
	freopen("paradox.in","r",stdin);
	freopen("paradox.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		memset(flag,0,sizeof flag);
		memset(ans,255,sizeof ans);
		scanf("%d%d",&N,&A);
		for (int i=0;i<N;i++) scanf("%s",P[i]);
		printf("Case #%d:",t);
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++) if (!flag[j])
			{
				flag[j]=true, ans[i]=j;
				if (valid(i)) break; else ans[i]=-1;
				flag[j]=false;
			}
			if (!~ans[i]) break;
		}
		if (!~ans[N-1])
			printf(" IMPOSSIBLE");
		else
			for (int i=0;i<N;i++)
				printf(" %d",ans[i]);
		putchar('\n');
	}
	return 0;
}

