#include<cstdio>
#include<cstring>
#include<algorithm>
#include<exception>
using namespace std;

const int maxn=550015;

int n, m, L[15], R[15], tag[maxn], sa[maxn], rank[maxn], rmq[maxn][25], S[maxn][15];
char s[maxn];

void buildSA()
{
	static int tank[maxn], tmp[maxn], rk[maxn<<1];
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

void buildRMQ()
{
	for (int i=1;i<=n;i++)
	{
		rmq[rank[i]][0]=max(rmq[rank[i-1]][0]-1,0);
		while (s[i+rmq[rank[i]][0]]==s[sa[rank[i]-1]+rmq[rank[i]][0]]) rmq[rank[i]][0]++;
	}
	for (int k=1;(1<<k)<=n;k++)
		for (int i=1;i+(1<<k)-1<=n;i++)
			rmq[i][k]=min(rmq[i][k-1],rmq[i+(1<<k>>1)][k-1]);
}

void calcS()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			S[i][j]=S[i-1][j]+(tag[sa[i]]==j);
}

inline int LCP(register int x, register int y)
{
	if (x==y) return n;
	if (x>y) swap(x,y);
	x++;
	int k=31-__builtin_clz(y-x+1);
	return min(rmq[x][k],rmq[y-(1<<k)+1][k]);
}

inline int upper(int l, int r, int t, int v)
{
	int ret(r);
	while (l<=r)
	{
		int mid((l+r)>>1);
		if (LCP(mid,t)>=v) r=mid-1, ret=min(ret,mid); else l=mid+1;
	}
	return ret;
}

inline int lower(int l, int r, int t, int v)
{
	int ret(l);
	while (l<=r)
	{
		int mid((l+r)>>1);
		if (LCP(mid,t)>=v) l=mid+1, ret=max(ret,mid); else r=mid-1;
	}
	return ret;
}

inline int check(int l, int r)
{
	bool hi(false), lo(false);
	for (int i=1;i<=m;i++)
	{
		hi|=(S[r][i]-S[l-1][i]>R[i]);
		lo|=(S[r][i]-S[l-1][i]<L[i]);
	}
	if (hi && lo) throw(exception());
	return hi? 1: lo? -1: 0;
}

int main()
{
	freopen("substr.in","r",stdin);
	freopen("substr.out","w",stdout);
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	int len=n;
	s[++n]='#';
	for (int i=1;i<=m;i++)
	{
		scanf("%s%d%d",s+n+1,&L[i],&R[i]);
		while (s[n]) tag[++n]=i;
		s[n]='$';
	}
	buildSA();
	buildRMQ();
	calcS();
	long long ans(0);
	for (int i=2,j=1;i<=n;i++) if (!tag[sa[i]])
	{
		int lo(len-sa[i]+2), hi(0);
		try
		{
			for (int l=LCP(i,j)+1,r=len-sa[i]+1;l<=r;)
			{
				int mid((l+r)>>1), ub, lb, vdt;
				ub=upper(1,i,i,mid);
				lb=lower(i,n,i,mid);
				vdt=check(ub,lb);
				if (vdt<=0) r=mid-1, lo=min(lo,mid); else l=mid+1;
			}
			for (int l=lo,r=len-sa[i]+1;l<=r;)
			{
				int mid((l+r)>>1), ub, lb, vdt;
				ub=upper(1,i,i,mid);
				lb=lower(i,n,i,mid);
				vdt=check(ub,lb);
				if (vdt>=0) l=mid+1, hi=max(hi,mid); else r=mid-1;
			}
		} catch (exception err) {}
		ans+=max(0,hi-lo+1);
		j=i;
	}
	printf("%I64d\n",ans);
	return 0;
}

