#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
	for (int k=1;(1<<k)<n;k++)
		for (int i=1;i+(1<<k)<=n;i++)
			rmq[i][k]=min(rmq[i][k-1],rmq[i+(1<<k>>1)][k-1]);
}

void calcS()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			S[i][j]=S[i-1][j]+(tag[sa[i]]==j);
}

inline int LCP(int x, int y)
{
	if (x>y) swap(x,y);
	int k=log2(y-x+1);
	return min(rmq[x][k],rmq[y-(1<<k)+1][k]);
}

int main()
{
	freopen("substr.in","r",stdin);
	freopen("substr.out","w",stdout);
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	s[++n]='$';
	for (int i=1;i<=m;i++)
	{
		scanf("%s%d%d",s+n+1,&L[i],&R[i]);
		while (s[n]) tag[++n]=i;
		s[n]='#';
	}
	buildSA();
	buildRMQ();
	calcS();
	long long ans(0);
	for (int i=1;s[i]!='$';i++)
	{
		int l, r, mid, vdt, A(rank[i]), B(0), C(n+1), D(rank[i]);
		const int HI(1), LO(2);
		try
		{
			for (l=1,r=rank[i]-1;l<=r;)
			{
				mid=((l+r)>>1), vdt=0;
				for (int j=1;j<=m;j++)
				{
					if (S[rank[i]][j]-S[mid-1][j]<L[j]) vdt|=LO;
					if (S[rank[i]][j]-S[mid-1][j]>R[j]) vdt|=HI;
				}
				if (vdt==(HI|LO)) throw(vdt);
				if (vdt&HI) l=mid+1; else r=mid-1;
				if (!vdt) A=min(A,mid);
			}
			for (l=1,r=rank[i]-1;l<=r;)
			{
				mid=((l+r)>>1), vdt=0;
				for (int j=1;j<=m;j++)
				{
					if (S[rank[i]][j]-S[mid-1][j]<L[j]) vdt|=LO;
					if (S[rank[i]][j]-S[mid-1][j]>R[j]) vdt|=HI;
				}
				if (vdt==(HI|LO)) throw(vdt);
				if (vdt&LO) r=mid-1; else l=mid+1;
				if (!vdt) B=max(B,mid);
			}
			for (l=rank[i]+1,r=n;l<=r;)
			{
				mid=((l+r)>>1), vdt=0;
				for (int j=1;j<=m;j++)
				{
					if (S[mid][j]-S[rank[i]][j]<L[j]) vdt|=LO;
					if (S[mid][j]-S[rank[i]][j]>R[j]) vdt|=HI;
				}
				if (vdt==(HI|LO)) throw(vdt);
				if (vdt&LO) l=mid+1; else r=mid-1;
				if (!vdt) C=min(C,mid);
			}
			for (l=rank[i]+1,r=n;l<=r;)
			{
				mid=((l+r)>>1), vdt=0;
				for (int j=1;j<=m;j++)
				{
					if (S[mid][j]-S[rank[i]][j]<L[j]) vdt|=LO;
					if (S[mid][j]-S[rank[i]][j]>R[j]) vdt|=HI;
				}
				if (vdt==(HI|LO)) throw(vdt);
				if (vdt&HI) r=mid-1; else l=mid+1;
				if (!vdt) D=max(D,mid);
			}
		} catch (int vdt)
		{
			continue;
		}
		if (A>B || C>D) continue;
		int MIN, MAX;
		MAX=min(LCP(rank[i],B+1),LCP(rank[i],C-1))-1;
		MIN=max(LCP(rank[i],A-1),LCP(rank[i],D+1))+1;
		ans+=max(0,MAX-MIN+1);
	}
	printf("%I64d\n",ans);
	return 0;
}

