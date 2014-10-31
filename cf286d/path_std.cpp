// STD !!!

#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define N 200005
int Q,m,n,q,x[N],y[N],t[N],f[N],v[N],p[N],o[N];
bool cmp(const int i,const int j){return t[i]<t[j];}
int get(int x){return f[x]==x?x:f[x]=get(f[x]);}
int main()
{
	freopen("path.in","r",stdin), freopen("path.ans","w",stdout);
	scanf("%d%d",&Q,&m);
	rep(i,m) scanf("%d%d%d",x+i,y+i,t+i),v[n++]=x[i],v[n++]=y[i],p[i]=i;
	sort(v,v+n),n=unique(v,v+n)-v; sort(p,p+m,cmp); rep(i,n+1) f[i]=i,o[i]=-1;
	rep(k,m){
		int i=p[k],l=lower_bound(v,v+n,x[i])-v,r=lower_bound(v,v+n,y[i])-v;
		for (int j=get(l);j<r;j=get(j)) o[j]=t[i],f[j]=j+1;
		}
	m=0; if (*o>=0) t[m++]=*o-*v;
	rep(i,n-1) if (o[i]!=o[i+1]){
		if (o[i]>=0) t[m++]=o[i]-v[i+1];
		if (o[i+1]>=0) t[m++]=o[i+1]-v[i+1];
		}
	rep(i,m) p[i]=i; sort(p,p+m,cmp); int j=0,k=0,s=0,T=0;
	rep(i,Q){
		scanf("%d",&q);
		for (;j<m && t[p[j]]<=q;j++)
			s+=k*(T-t[p[j]]),T=t[p[j]],k+=p[j]&1?-1:1;
		s+=k*(T-q),T=q; printf("%d\n",s);
		}
	return 0;
}

// STD !!!
