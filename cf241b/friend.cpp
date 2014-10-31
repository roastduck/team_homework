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

const int maxn=50005, maxl=maxn*30, mo=1e9+7;

int N, M, ans, A[maxn], st, en, low1[maxl], mid1[maxl], high1[maxl], low2[maxl], mid2[maxl], high2[maxl];

inline void Calc(int LOW1, int HIGH1, int LOW2, int HIGH2, int k)
{
	if (LOW1==HIGH1 || LOW2==HIGH2) return;
	for (int p=1;p<=k;p<<=1)
	{
		register int lcnt(0), hcnt(0);
		for (register int *j=A+LOW1;j<A+HIGH1;j++) lcnt+=bool(*j&p);
		for (register int *j=A+LOW2;j<A+HIGH2;j++) hcnt+=bool(*j&p);
		ans=(ans+(long long)p*((HIGH1-LOW1-lcnt)*hcnt+lcnt*(HIGH2-LOW2-hcnt))%mo)%mo;
	}
}

inline void Add(int LOW1, int HIGH1, int LOW2, int HIGH2)
{
	if (LOW1==HIGH1 && LOW2==HIGH2) return;
	en++, low1[en]=LOW1, high1[en]=HIGH1, low2[en]=LOW2, high2[en]=HIGH2;
}

int main()
{
	freopen("friend.in","r",stdin);
	freopen("friend.out","w",stdout);
	READ(N), READ(M);
	for (int i=1;i<=N;i++) READ(A[i]);
	sort(A+1,A+N+1);
	low1[0]=1;
	high1[0]=low2[0]=lower_bound(A+1,A+N+1,1<<29)-A;
	high2[0]=N+1;
	bool flag(true);
	for (int k=(1<<29);k;k>>=1)
	{
		int tot(0);
		for (int i=st;i<=en;i++)
		{
			tot+=(high1[i]-low1[i])*(high2[i]-low2[i]);
			mid1[i]=lower_bound(A+low1[i],A+high1[i],(A[low1[i]]&~(k-1))|(k>>1))-A;
			mid2[i]=lower_bound(A+low2[i],A+high2[i],(A[low2[i]]&~(k-1))|(k>>1))-A;
		}
		if (tot<=M)
		{
			M-=tot;
			int tmp(en);
			for (;st<=tmp;st++)
			{
				Calc(low1[st],high1[st],low2[st],high2[st],k);
				Add(low1[st],mid1[st],mid1[st],high1[st]);
				Add(low2[st],mid2[st],mid2[st],high2[st]);
			}
			flag=true;
		} else
		{
			if (flag) ans+=(long long)M*k%mo, ans%=mo;
			int tot2(0);
			for (int i=st;i<=en;i++)
			{
				tot2+=(high1[i]-mid1[i])*(mid2[i]-low2[i]);
				tot2+=(mid1[i]-low1[i])*(high2[i]-mid2[i]);
			}
			if (tot2<=M)
			{
				M-=tot2;
				int tmp(en);
				for (;st<=tmp;st++)
				{
					Calc(mid1[st],high1[st],low2[st],mid2[st],k>>1);
					Calc(low1[st],mid1[st],mid2[st],high2[st],k>>1);
					Add(low1[st],mid1[st],low2[st],mid2[st]);
					Add(mid1[st],high1[st],mid2[st],high2[st]);
				}
				flag=false;
			} else
			{
				int tmp(en);
				for (;st<=tmp;st++)
				{
					Add(mid1[st],high1[st],low2[st],mid2[st]);
					Add(low1[st],mid1[st],mid2[st],high2[st]);
				}
				flag=true;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

