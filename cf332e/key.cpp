#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, k;
char p[1000005], s[205];
bool now[2005], ans[2005];

int main()
{
	freopen("key.in","r",stdin);
	freopen("key.out","w",stdout);
	gets(p), gets(s);
	scanf("%d",&k);
	n=strlen(p), m=strlen(s);
	int b=n/k;
	bool exist(false);
	for (int one=0;one<=k;one++) if (one*b<=m && one*(b+1)>=m)
	{
		bool fail(false);
		memset(now,0,k);
		for (int i=one-1,j=k-1;i>=0;j--)
		{
			if (j<0)
			{
				fail=true;
				break;
			}
			bool ok(true);
			for (int r=0;(r*k+j<n||r*one+i<m)&&ok;r++)
				if (r*k+j>=n || r*one+i>=m || p[r*k+j]!=s[r*one+i])
					ok=false;
			if (ok)
				now[j]=1, i--;
		}
		if (!fail && (!exist || memcmp(now,ans,k)<0))
			memcpy(ans,now,k), exist=true;
	}
	if (exist)
		for (int i=0;i<k;i++) putchar(ans[i]?'1':'0');
	else
		putchar('0');
	putchar('\n');
	return 0;
}

