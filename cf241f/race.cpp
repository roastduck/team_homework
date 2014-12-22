#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N, M, K, A[105][105], X[30], Y[30];
char s[1005];

int main()
{
	freopen("race.in","r",stdin);
	freopen("race.out","w",stdout);
	scanf("%d%d%d",&N,&M,&K);
	for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		{
			char c;
			scanf(" %c",&c);
			if (c>='a' && c<='z')
				X[c-'a']=i, Y[c-'a']=j, A[i][j]=1;
			else
				A[i][j]=c-'0';
		}
	int x, y, n;
	scanf("%d%d%s%d%d",&x,&y,s,X+26,Y+26);
	n=strlen(s), s[n]='z'+1;
	for (int i=0; i<=n && K>=0; i++)
	{
		int xx(X[s[i]-'a']), yy(Y[s[i]-'a']);
		while (x!=xx || y!=yy)
		{
			if ((K-=A[x][y])<0) break;
			if (x<xx) x++;
			if (x>xx) x--;
			if (y<yy) y++;
			if (y>yy) y--;
		}
	}
	printf("%d %d\n",x,y);
	return 0;
}

