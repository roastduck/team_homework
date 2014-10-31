#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=30;

int N, C[maxn], order[maxn];
bool flag[33554440];

void Dfs(int x, int used, int started)
{
	if (x==N)
	{
		puts("YES");
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++) putchar(C[order[j]]&(1<<i)?'1':'0');
			putchar('\n');
		}
		exit(0);
	}
	if (flag[used]) return;
	flag[used]=true;
	int able(0);
	for (int i=0;i<N;i++) if (!(used&(1<<i)))
		able|=C[i];
	for (int i=0;i<N;i++) if (!(used&(1<<i)) && !(started&(able^C[i])))
	{
		order[x]=i;
		Dfs(x+1,used|(1<<i),started|C[i]);
	}
}

int main()
{
	//freopen("matrix.in","r",stdin);
	//freopen("matrix.out","w",stdout);
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			char c;
			scanf(" %c",&c);
			if (c=='1') C[j]^=(1<<i);
		}
	Dfs(0,0,0);
	puts("NO");
	return 0;
}

