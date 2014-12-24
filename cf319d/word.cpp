#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=50005, mo=1e9+9;

int n, m, pow31[maxn], *hs=new int[maxn], *ht=new int[maxn];
char *s=new char[maxn], *t=new char[maxn];

inline int hashsum(int *hash, int x, int y)
{
	return (hash[y-1]-(long long)hash[x-1]*pow31[y-x])%mo;
}

inline int LCP(int x, int y)
{
	int l(1), r(n-max(x,y)+1), ret(0);
	while (l<=r)
	{
		int mid((l+r)>>1);
		if ((hashsum(hs,x,x+mid)-hashsum(hs,y,y+mid))%mo==0)
			l=mid+1, ret=max(ret,mid);
		else
			r=mid-1;
	}
	return ret;
}

bool Exist(int l)
{
	for (int i=l+l;i<=n;i+=l)
	{
		int forw=LCP(i,i-l), back=l-forw;
		if (i-l-back>0 && LCP(i-back,i-l-back)==l)
			return true;
	}
	return false;
}

int main()
{
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	pow31[0]=1, hs[0]=ht[0]=0;
	for (int i=1;i<=n;i++)
	{
		hs[i]=(hs[i-1]*31ll+s[i])%mo;
		pow31[i]=pow31[i-1]*31ll%mo;
	}
	for (int l=1;l<=n;l++) if (Exist(l))
	{
		m=0, t[1]=0;
		for (int i=1;i<=n;i++)
		{
			while (n-i+1>=l && m>=l && (hashsum(hs,i,i+l)-hashsum(ht,m-l+1,m+1))%mo==0)
				i+=l;
			m++, t[m]=s[i], ht[m]=(ht[m-1]*31ll+t[m])%mo, t[m+1]=0;
		}
		swap(n,m), swap(s,t), swap(hs,ht);
	}
	puts(s+1);
	return 0;
}

