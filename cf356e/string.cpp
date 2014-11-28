#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxn=1e5+5;

int N, sa[maxn], rank[maxn], hei[maxn][20], app[maxn][20];
ll ori[maxn], chg[maxn][26];
bool f[maxn][20];
char s[maxn];

void buildSA()
{
	static int tank[maxn], tmp[maxn], rk[maxn<<1];
	for (int i=1;i<=N;i++) tank[s[i]]++;
	for (int i=1;i<128;i++) tank[i]+=tank[i-1];
	for (int i=1;i<=N;i++) sa[tank[s[i]]--]=i;
	for (int i=1,j=0;i<=N;i++)
	{
		if (!j || s[sa[i]]>s[sa[i-1]]) j++;
		rank[sa[i]]=j;
	}
	for (int k=1;k<N;k<<=1)
	{
		int j(0);
		for (int i=N+1;i<=N+k;i++) tmp[++j]=i-k;
		for (int i=1;i<=N;i++) if (sa[i]>k) tmp[++j]=sa[i]-k;
		memset(tank,0,sizeof tank);
		for (int i=1;i<=N;i++) tank[rank[tmp[i]]]++;
		for (int i=2;i<=N;i++) tank[i]+=tank[i-1];
		for (int i=N;i;i--) sa[tank[rank[tmp[i]]]--]=tmp[i];
		memcpy(rk,rank,sizeof rank);
		for (int i=1,j=0;i<=N;i++)
		{
			if (!j || rk[sa[i]]>rk[sa[i-1]] || rk[sa[i]]==rk[sa[i-1]] && rk[sa[i]+k]>rk[sa[i-1]+k]) j++;
			rank[sa[i]]=j;
		}
	}
	for (int i=1;i<=N;i++)
	{
		hei[rank[i]][0]=max(0,hei[rank[i-1]][0]-1);
		while (s[i+hei[rank[i]][0]]==s[sa[rank[i]-1]+hei[rank[i]][0]]) hei[rank[i]][0]++;
	}
	for (int j=1;(1<<j)<=N;j++)
		for (int i=1;i+(1<<j)-1<=N;i++)
			hei[i][j]=min(hei[i][j-1],hei[i+(1<<j>>1)][j-1]);
}

int LCP(int x, int y)
{
	x=rank[x], y=rank[y];
	if (x>y) swap(x,y);
	x++;
	int k=log2(y-x+1);
	return min(hei[x][k],hei[y-(1<<k)+1][k]);
}

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%s",s+1);
	N=strlen(s+1);
	buildSA();
	for (int i=1;i<=N;i++)
		f[i][1]=true, app[i][1]=(1<<(s[i]-'a'));
	ll tot=0;
	for (int j=2;(1<<j)-1<=N;j++)
		for (int i=(1<<j>>1);i+(1<<j>>1)-1<=N;i++)
		{
			int x=LCP(i-(1<<j>>1)+1,i+1),
			    lb=i-(1<<j>>1)+1, rb=i+(1<<j>>1)-1, lc=i-(1<<j>>2), rc=i+(1<<j>>2);
			app[i][j]=(app[lc][j-1]|app[rc][j-1]|app[i][1]);
			ll val=ll((1<<j)-1)*((1<<j)-1);
			if (x>=(1<<j>>1)-1)
			{
				if (f[lc][j-1] && f[rc][j-1])
				{
					if (!(app[lc][j-1]&app[i][1]))
					{
						f[i][j]=true;
						ori[lb]+=val, ori[rb+1]-=val;
						tot+=val;
					}
					for (int k=0;k<26;k++) if (!(app[lc][j-1]&(1<<k)))
						chg[i][k]+=val;
				}
			}
			else
				if (LCP(lb+x+1,i+x+2)+x>=(1<<j>>1)-2)
				{
					if (f[rc][j-1] && !(app[rc][j-1]&app[i][1]))
						chg[lb+x][s[i+x+1]-'a']+=val;
					if (f[lc][j-1] && !(app[lc][j-1]&app[i][1]))
						chg[i+x+1][s[lb+x]-'a']+=val;
				}
		}
	ll cost=0, ans=tot;
	for (int i=1;i<=N;i++)
	{
		cost+=ori[i];
		for (int j=0;j<26;j++)
			ans=max(ans,tot-cost+chg[i][j]);
	}
	printf("%I64d\n",ans+N);
	return 0;
}

