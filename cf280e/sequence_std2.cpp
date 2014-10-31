//Orz Sevenkplus
//Orz xiaodao
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define REP(i,l,r) for((i)=(l);(i)<=(r);++(i))
#define REP2(i,l,r) for((i)=(l);(i)!=(r);++(i))
using namespace std;

typedef long long LL;
typedef double ld;

const int MAX=6000+10;
const ld INF=1e9;
const ld EPS=1e-9;

int n,q,A,B;
int x[MAX];

//我好奇如果真的是暴力维护导函数的话。。。那岂不是太暴力了啊
//我只需要根据前一个求出零点即可
struct node
{
	node *p,*lc,*rc;
	ld l;//导函数
	ld a,b;//导函数 ax+b
	ld y;//l处的值
	//操作有:
	//找到零点:平衡树里二分即可
	//平移:打标记应该可以，但是蛋疼纠结麻烦啊
	//插入一段导函数为0的区间，将所有区间加上一个一次函数的值，应该挺简单的，维护个增量函数就行了
};

void rotate(node* u)
{
	node* fa=u->p;
	node* gfa=fa->p;
	if(fa->lc==u)
	{
		if(u->rc)
			u->rc->p=fa;
		fa->lc=u->rc;
		u->rc=fa;
	}
	else
	{
		if(u->lc)
			u->lc->p=fa;
		fa->rc=u->lc;
		u->lc=fa;
	}
	fa->p=u;
	if(gfa->lc==fa)
		gfa->lc=u;
	else gfa->rc=u;
	u->p=gfa;
}

void Splay(node* u)
{
	node *fa,*gfa;
	for(;(fa=u->p);rotate(u))
		if((gfa=fa->p))
			rotate((gfa->lc==fa)==(fa->lc==u)?fa:u);
}

namespace BF
{
	ld ans[MAX];
	struct line
	{
		ld l,r,a,b;
		line(ld x,ld y,ld z,ld w)
		{
			l=x;
			r=y;
			a=z;
			b=w;
		}
		ld zero()
		{
			//a*x+b=0
			ld zz=-b/a;
			if(zz>=l && zz<=r)
				return zz;
			if(a>0)return l;
			else return r;
		}
	};
	vector<line> now,tmp;
	ld solve(int u)
	{
		int i;
		ld na=2;
		ld nb=-2*x[u];
		ld zz=-1;
		if(u!=1)
		{
			tmp.clear();
			ld mm=1e20;
			REP2(i,0,now.size())
			{
				ld t=now[i].zero();
				if(abs(t*now[i].a+now[i].b)<mm)
				{
					zz=t;
					mm=abs(t*now[i].a+now[i].b);
				}
			}
			ld p;
			if(u!=n+1)
			{
				tmp.clear();
				REP2(i,0,now.size())
				{
					if(now[i].r-now[i].l<1e-10)
						continue;
					if(now[i].l<=zz)
						tmp.pb(line(now[i].l+A,min(zz,now[i].r)+A,now[i].a+na,now[i].b-now[i].a*A+nb));
					if(now[i].r>=zz)
						tmp.pb(line(max(now[i].l,zz)+B,now[i].r+B,now[i].a+na,now[i].b-now[i].a*B+nb));
				}
				tmp.pb(line(zz+A,zz+B,na,nb));
				now=tmp;
				p=solve(u+1);
			}
			else p=-1;
			if(p<0 || ( p-zz>=A && p-zz<=B ) )
				ans[u-1]=zz;
			else if(abs(p-A-zz)<abs(p-B-zz))
				ans[u-1]=p-A;
			else ans[u-1]=p-B;
			ans[u-1]=min( max(ans[u-1],1.0),(ld)q );
			return ans[u-1];
		}
		else
		{
			zz=x[1];
			now.pb(line(1,q,na,nb));
			solve(2);
			return 0;
		}
	}
	int Main()
	{
		int i;
		ld sum=0;
		solve(1);
		REP(i,1,n)
		{
			printf("%lf ",ans[i]);
			sum+=(ans[i]-x[i])*(ans[i]-x[i]);
		}
		printf("\n%lf\n",sum);
		return 0;
	}
}

int main()
{
	freopen("sequence.in","r",stdin);freopen("sequence.ans","w",stdout);
	int i;
	scanf("%d%d%d%d",&n,&q,&A,&B);
	REP(i,1,n)
		scanf("%d",&x[i]);
	BF::Main();
	return 0;
}

