#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1e6+5;

struct NODE
{
	int l, tag, flag;
	NODE *f, *ch[26];
};

int pn;
char s[maxn];
NODE *root, *tail, pool[maxn<<1], *ord[maxn<<1];

void Build(int c, int l)
{
	NODE *np, *p;
	ord[pn]=np=&pool[pn], pn++;
	np->l=l, np->tag=1;
	for (p=tail; p && !p->ch[c]; p=p->f)
		p->ch[c]=np;
	tail=np;
	if (p)
		if (p->ch[c]->l==p->l+1)
			np->f=p->ch[c];
		else
		{
			NODE *x, *q=p->ch[c];
			ord[pn]=x=&pool[pn], pn++;
			*x=*q;
			x->tag=0;
			x->l=p->l+1;
			q->f=np->f=x;
			for (; p && p->ch[c]==q; p=p->f)
				p->ch[c]=x;
		}
	else
		np->f=root;
}

inline bool cmp(NODE *a, NODE *b)
{
	return a->l<b->l;
}

void Go(NODE *&x, int c, int &l)
{
	for (; x && !x->ch[c]; x=x->f)
		if (x->f) l=x->f->l;
	if (!x) l=0, x=root; else l++, x=x->ch[c];
}

int main()
{
	freopen("cyclical.in","r",stdin);
	freopen("cyclical.out","w",stdout);
	scanf("%s",s);
	ord[pn]=tail=root=&pool[pn], pn++;
	for (int i=0;s[i];i++)
		Build(s[i]-'a',i+1);
	sort(ord,ord+pn,cmp);
	for (int i=pn-1;i;i--)
		ord[i]->f->tag+=ord[i]->tag;
	int Q;
	for (scanf("%d",&Q);Q;Q--)
	{
		scanf("%s",s);
		int len=strlen(s), ans=0, l=0;
		NODE *x=root;
		for (int i=0;i<len*2-1;i++)
		{
			Go(x,s[i%len]-'a',l);
			while (x->f && x->f->l>=len)
				x=x->f, l=x->l;
			if (l>=len && x->flag!=Q)
				ans+=x->tag, x->flag=Q;
		}
		printf("%d\n",ans);
	}
	return 0;
}

