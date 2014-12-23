#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct NODE
{
	int l;
	NODE *f, *ch[26];
};

int N, M, pn;
NODE *root, *tail, pool[100005];

inline void getal(char &c)
{
	do c=getchar(); while (!isalpha(c));
}

void Ins(int c, int l)
{
	NODE *p=tail, *np=pool+pn++;
	np->l=l, tail=np;
	for (; p && !p->ch[c]; p=p->f) p->ch[c]=np;
	if (!p)
		np->f=root;
	else
		if (p->ch[c]->l==p->l+1)
			np->f=p->ch[c];
		else
		{
			NODE *t=pool+pn++, *q=p->ch[c];
			*t=*q;
			np->f=q->f=t;
			t->l=p->l+1;
			for (; p && p->ch[c]==q; p=p->f) p->ch[c]=t;
		}
}

int main()
{
	freopen("letter.in","r",stdin);
	freopen("letter.out","w",stdout);
	scanf("%d%d",&N,&M);
	root=tail=pool+pn++;
	for (int i=1;i<=N;i++)
	{
		char c;
		getal(c);
		Ins(c-'A',i);
	}
	int ans(1);
	NODE *p=root;
	for (int i=1;i<=M;i++)
	{
		char c;
		getal(c), c-='A';
		if (p->ch[c])
			p=p->ch[c];
		else
			p=root->ch[c], ans++;
	}
	printf("%d\n",ans);
	return 0;
}

