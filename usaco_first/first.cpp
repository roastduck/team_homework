#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

const int maxn=30005, maxl=300005;

struct data
{
	data *l, *r;
	char c;
	int end;
	data() :l(0), r(0), c(0), end(0) {}
};

int N, a[30][30], b[30][30], m, f[30], list[1000], cnt[30], step[maxl], ans_num;
char s[maxl];
bool ans[maxn], flag[30];
string ss[maxn];
data *root, *thi[maxl], *fro[maxl];

void Ins(char *c, int NAME)
{
	if (!root) root=new data(), root->c=*c;
	data *x=root;
	while (true)
	{
		while (x->c!=*c)
		{
			if (!x->r) x->r=new data(), x->r->c=*c;
			x=x->r;
		}
		if (x->end) return;
		if (*(c+1)==0)
		{
			x->end=NAME;
			return;
		}
		c++;
		if (!x->l) x->l=new data(), x->l->c=*c;
		x=x->l;
	}
}

bool spfa()
{
	int st,en;
	memset(flag,0,sizeof flag);
	memset(f,255,sizeof f);
	memset(cnt,0,sizeof cnt);
	for (int ii=0;ii<26;ii++) if (f[ii]==-1)
	{
		f[ii]=0;
		list[st=en=1]=ii;
		while (st<=en)
		{
			int now(list[st]);
			for (int i=1;i<=b[now][0];i++) if (f[now]+1>f[b[now][i]])
			{
				f[b[now][i]]=f[now]+1;
				if (!flag[b[now][i]])
				{
					flag[b[now][i]]=true;
					if (++cnt[b[now][i]]>26) return false;
					list[++en]=b[now][i];
				}
			}
			st++, flag[now]=false;
		}
	}
	return true;
}

void Scan()
{
	m=1, thi[m]=fro[m]=root, step[m]=1;
	while (m)
	{
		data *&y=thi[m];
		if (step[m]==1)
		{
			step[m]++;
			for (data *x=fro[m];x;x=x->r) if (x!=y)
				if (!(a[x->c-97][y->c-97]++))
				{
					b[x->c-97][0]++;
					b[x->c-97][b[x->c-97][0]]=y->c-97;
				}
			if (y->end)
			{
				if ((ans[y->end]=spfa()))
					ans_num++;
			}
			else
				m++, thi[m]=fro[m]=y->l, step[m]=1;
		} else
		{
			step[m]--;
			for (data *x=fro[m];x;x=x->r) if (x!=y)
				if (!(--a[x->c-97][y->c-97]))
					b[x->c-97][0]--;
			y=y->r;
			if (!y) m--;
		}
	}
}

int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf(" %s",s);
		ss[i]=s;
		Ins(s,i);
	}
	Scan();
	printf("%d\n",ans_num);
	for (int i=1;i<=N;i++)
	{
		if (ans[i]) cout<<ss[i]<<endl;
	}
	return 0;
}

