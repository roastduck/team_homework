#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=30005;

int N, n, sa[maxn<<1], rank[maxn<<1];
char s[maxn<<1];

void buildSA()
{
	static int tmp[maxn<<1], tank[maxn<<1], rk[maxn<<2];
	for (int i=1;i<=n;i++) tank[s[i]]++;
	for (int i=1;i<256;i++) tank[i]+=tank[i-1];
	for (int i=1;i<=n;i++) sa[tank[s[i]]--]=i;
	for (int i=1,j=0;i<=n;i++)
	{
		if (!j || s[sa[i]]>s[sa[i-1]]) j++;
		rank[sa[i]]=j;
	}
	for (int k=1;k<n;k<<=1)
	{
		int j(0);
		for (int i=n+1;i<=n+k;i++) tmp[++j]=i-k;
		for (int i=1;i<=n;i++) if (sa[i]>k) tmp[++j]=sa[i]-k;
		memset(tank,0,sizeof tank);
		for (int i=1;i<=n;i++) tank[rank[tmp[i]]]++;
		for (int i=2;i<=n;i++) tank[i]+=tank[i-1];
		for (int i=n;i;i--) sa[tank[rank[tmp[i]]]--]=tmp[i];
		memcpy(rk,rank,sizeof rank);
		for (int i=1,j=0;i<=n;i++)
		{
			if (!j || rk[sa[i]]>rk[sa[i-1]] || rk[sa[i]]==rk[sa[i-1]] && rk[sa[i]+k]>rk[sa[i-1]+k]) j++;
			rank[sa[i]]=j;
		}
	}
}

int main()
{
	freopen("bclgold.in","r",stdin);
	freopen("bclgold.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++) scanf(" %c",&s[i]);
	s[n=N+1]='$';
	for (int i=N;i;i--) s[++n]=s[i];
	buildSA();
	int cnt(0);
	for (int i=1,l=1,r=N+2;i<=N;i++)
	{
		putchar(s[(rank[l]<rank[r]?l:r)++]);
		if (++cnt==80) cnt=0, putchar('\n');
	}
	if (cnt) putchar('\n');
	return 0;
}

