#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<long long,bool> PI;
#define fi first
#define se second

const int maxn=10005;
const long long _a=104729, _b=64, _c=252097800623ll, _d=63, _e=62;

int N, m, a[maxn], b[maxn<<1], c[maxn<<1], size[maxn<<1];
long long code[maxn<<1], _pow[maxn];
bool symm[maxn<<1];
char color[maxn];

void Calc(int addr, int fa, int x)
{
	size[addr]=1;
	for (int i=a[x];i;i=c[i]) if (b[i]!=fa && !~code[i])
		Calc(i,x,b[i]);
	vector< pair<long long, int> > A;
	for (int i=a[x];i;i=c[i]) if (b[i]!=fa)
	{
		A.push_back(make_pair(code[i],i));
		size[addr]+=size[i];
	}
	sort(A.begin(),A.end());
	code[addr]=_b;
	symm[addr]=true;
	PI flag(-1,false);
	int even(0);
	for (int i=0;i<A.size();i++)
	{
		code[addr]=(code[addr]*_pow[size[A[i].se]+3]+A[i].fi)%_c;
		if (!~flag.fi) flag=PI(A[i].fi,symm[A[i].se]); else
		if (flag.fi==A[i].fi) flag.fi=-1; else
		{
			if (!flag.se || ++even>1) symm[addr]=false;
			flag=PI(A[i].fi,symm[A[i].se]);
		}
	}
	code[addr]=(((code[addr]*_a+_d)%_c*_a+color[x])%_c*_a+_e)%_c;
	if (~flag.fi && (!flag.se || ++even>1)) symm[addr]=false;
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	_pow[0]=1;
	for (int i=1;i<maxn;i++) _pow[i]=(_pow[i-1]*_a)%_c;
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		m=1;
		memset(a,0,sizeof a);
		memset(code,255,sizeof code);
		scanf("%d",&N);
		for (int i=1;i<=N;i++) scanf(" %c",&color[i]);
		for (int i=1;i<N;i++)
		{
			int x, y;
			scanf("%d%d",&x,&y);
			m++, b[m]=y, c[m]=a[x], a[x]=m;
			m++, b[m]=x, c[m]=a[y], a[y]=m;
		}
		for (int i=2;i<=m;i++) if (!~code[i])
			Calc(i,b[i^1],b[i]);
		try
		{
			for (int i=2;i<=m;i+=2)
				if (code[i]==code[i^1])
					throw(true);
			for (int i=1;i<=N;i++)
			{
				map<long long,bool> S;
				for (int j=a[i];j;j=c[j])
					if (S.count(code[j]))
						S.erase(code[j]);
					else
						S[code[j]]=symm[j];
				bool ok(S.size()<=2);
				for (map<long long,bool>::iterator i=S.begin(); i!=S.end() && ok; i++)
					ok&=i->se;
				if (ok) throw(true);
			}
			throw(false);
		} catch (bool vdt)
		{
			printf("Case #%d: ",t);
			puts(vdt? "SYMMETRIC": "NOT SYMMETRIC");
		}
	}
	return 0;
}

