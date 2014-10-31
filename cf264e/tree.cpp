#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int maxn=100015, maxm=200015;
int N, M, height[maxn], pos[maxm], f[maxm<<1], g[maxn<<1];
set<int> left10, short10;
typedef set<int>::iterator iter;

#define pos(x,y) (((x)+(y))|((x)!=(y)))
void Ins(int f[], int l, int r, int q, int x)
{
	int mid((l+r)>>1);
	int &now=f[pos(l,r)], &son1=f[pos(l,mid)], &son2=f[pos(mid+1,r)];
	if (l==r)
	{
		now=x;
		return;
	}
	if (q<=mid) Ins(f,l,mid,q,x); else Ins(f,mid+1,r,q,x);
	now=max(son1,son2);
}

int Find(int f[], int l, int r, int ql, int qr)
{
	int mid((l+r)>>1);
	int &now=f[pos(l,r)];
	if (l==ql && r==qr) return now;
	if (qr<=mid) return Find(f,l,mid,ql,qr); else
	if (ql>mid) return Find(f,mid+1,r,ql,qr); else
		return max(Find(f,l,mid,ql,mid),Find(f,mid+1,r,mid+1,qr));
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int month=M-1;month>=0;month--)
	{
		// for (iter i=left10.begin();i!=left10.end();i++) printf("%d ",*i);printf("\n");
		int type, x, y;
		scanf("%d",&type);
		if (type==1)
		{
			scanf("%d%d",&x,&y);
			y+=month;
			iter i(short10.begin());
			for (;i!=short10.end() && *i<y;i++)
			{
				Ins(f,1,M+10,*i,0);
				Ins(g,1,N+10,pos[*i],0);
			}
			height[x]=y;
			pos[y]=x;
			left10.insert(x);
			i=short10.insert(y).first;
			for (;;i--)
			{
				int val(Find(g,1,N+10,pos[*i]+1,N+10));
				Ins(f,1,M+10,*i,val+1);
				Ins(g,1,N+10,pos[*i],val+1);
				if (i==short10.begin()) break;
			}
			printf("%d\n",Find(f,1,M+10,1,M+10));
		} else
		{
			scanf("%d",&x);
			iter i(left10.begin());
			for (int cnt=1;cnt<x;i++,cnt++)
			{
				Ins(f,1,M+10,height[*i],0);
				Ins(g,1,N+10,*i,0);
			}
			iter stop(i); stop++;
			// printf("%d",*stop);
			Ins(f,1,M+10,height[*i],0);
			Ins(g,1,N+10,*i,0);
			short10.erase(height[*i]);
			pos[height[*i]]=0;
			height[*i]=0;
			left10.erase(i);
			if (!left10.empty() && stop!=left10.begin())
			{
				stop--;
				for (i=stop;;i--)
				{
					int val=Find(f,1,M+10,height[*i]+1,M+10);
					Ins(f,1,M+10,height[*i],val+1);
					Ins(g,1,N+10,*i,val+1);
					if (i==left10.begin()) break;
				}
			}
			printf("%d\n",Find(f,1,M+10,1,M+10));
		}
	}
	return 0;
}

