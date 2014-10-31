#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define N 210000
#define MOD 1000000007
#define int64 long long
#define foru(i,a,b) for(int i=a;i<=b;++i)

using namespace std;
int tsum[4*N][6],tr[4*N],c[6][6],a[N],n,m,l,r,x,ans;
int64 sum[N][6]; 
char ch;
int summ(int l,int r,int k)
{
	if(!k) return (r-l+1);
	if(!l) return 0;
	return (sum[r][k]-sum[l-1][k]+MOD)%MOD;
}
void renew(int l,int r,int no)
{
	if(tr[no]<0) return;
	foru(i,0,5) tsum[no][i]=(int64)tr[no]*summ(l,r,i)%MOD;
	tr[2*no]=tr[no]; tr[2*no+1]=tr[no]; tr[no]=-1;
}
void update(int no)
{
	foru(i,0,5) tsum[no][i]=(tsum[2*no][i]+tsum[2*no+1][i])%MOD;
}
int getsum(int l,int r,int ll,int rr,int k,int no)
{
	if(l>rr||ll>r) return 0;
	renew(l,r,no);
	if(ll<=l&&r<=rr) return tsum[no][k];
	return (getsum(l,(l+r)>>1,ll,rr,k,2*no)+getsum(((l+r)>>1)+1,r,ll,rr,k,2*no+1))%MOD;
}
void rev(int l,int r,int ll,int rr,int x,int no)
{
	renew(l,r,no);
	if(l>rr||ll>r) return;
	if(ll<=l&&r<=rr)
	{
		foru(i,0,5) tsum[no][i]=(int64)x*summ(l,r,i)%MOD;
		tr[2*no]=x; tr[2*no+1]=x;
		return;
	}
	rev(l,(l+r)>>1,ll,rr,x,2*no); rev(((l+r)>>1)+1,r,ll,rr,x,2*no+1);
	update(no);
}
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>m;
	foru(i,1,n) cin>>a[i];
	foru(i,1,n)
	  for(int64 j=0,k=1;j<=5;++j,k*=i,k%=MOD)
	    sum[i][j]=(sum[i-1][j]+k)%MOD;
	foru(i,0,5) c[i][0]=1;
	foru(i,1,5)
	  foru(j,1,i) c[i][j]=c[i-1][j]+c[i-1][j-1];
	memset(tr,128,sizeof(tr));
	foru(i,1,n) rev(1,n,i,i,a[i],1);
	while(m--)
	{
		cin>>ch>>l>>r>>x;
		if(ch=='?')
		{
			ans=0;
			foru(i,0,x)
			{
				int64 res=getsum(1,n,l,r,i,1);
				res*=c[x][i]; res%=MOD;
				res*=summ(l-1,l-1,x-i),res%=MOD;
				if((x-i)&1) res*=-1;
				res=(res+MOD)%MOD;
				ans+=res; ans%=MOD;
			}
			cout<<ans<<endl;
		}
		else rev(1,n,l,r,x,1);
	}
	return 0;
}

