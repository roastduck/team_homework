#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=505;

int N, cnt[maxn], left[maxn], right[maxn], lcnt, rcnt, onel[maxn], oner[maxn];
bool start[maxn], done[maxn], empty[maxn];
char A[maxn][maxn], TMP[maxn][maxn];

inline void find_term()
{
	for (int i=0;i<N;i++)
	{
		left[i]=N, right[i]=0;
		for (int j=0;j<N;j++) if (A[i][j]=='1')
		{
			left[i]=min(left[i],j);
			right[i]=max(right[i],j);
		}
	}
}

inline void copy_col(char A[][maxn], int c1, char B[][maxn], int c2)
{
	for (int i=0;i<N;i++) B[i][c2]=A[i][c1];
}

int drop(int *begin, int *end)
{
	memset(empty,0,sizeof empty);
	int n(0);
	for (int *i=begin;i<end;i++)
	{
		copy_col(A,*i,TMP,n++);
		empty[*i]=true;
	}
	return n;
}

void pull_left(int L, int R, int *begin, int *end)
{
	int n(drop(begin,end));
	for (int i=R-1,j=R-1;i>=L+n;i--,j--)
	{
		while (empty[j]) j--;
		if (i!=j) copy_col(A,j,A,i);
	}
	for (int i=0;i<n;i++)
		copy_col(TMP,i,A,L+i);
	start[L+n]=true;
	find_term();
}

void pull_right(int L, int R, int *begin, int *end)
{
	int n(drop(begin,end));
	for (int i=L,j=L;i<R-n;i++,j++)
	{
		while (empty[j]) j++;
		if (i!=j) copy_col(A,j,A,i);
	}
	for (int i=0;i<n;i++)
		copy_col(TMP,i,A,R-n+i);
	start[R-n]=true;
	find_term();
}

inline void find_range(int row, int &begin, int &end, int &cnt, int *one)
{
	end++;
	while (!start[begin]) begin--;
	while (!start[end]) end++;
	cnt=0;
	for (int i=begin;i<end;i++) if (A[row][i]=='1')
		one[cnt++]=i;
}

void Split(int L, int R)
{
	int row(-1);
	for (int i=0;i<N;i++)
		if (!done[i] && left[i]>=L && right[i]<R && (!~row || cnt[row]<cnt[i]))
			if (cnt[i]==R-L)
				done[i]=true;
			else
				row=i;
	if (!~row) return;
	bool ok(false), jump(true);
	lcnt=0;
	for (int i=L;i<R;i++)
		if (A[row][i]=='1') onel[lcnt++]=i;
	if (lcnt==R-L)
		jump=false;
	else
		pull_left(L,R,onel,onel+lcnt);
	done[row]=true;
	while (!ok)
	{
		ok=true;
		for (int i=0;i<N;i++)
			if (
					!done[i] && left[i]>=L && right[i]<R && 
					(!start[left[i]] || !start[right[i]+1] || right[i]-left[i]+1!=cnt[i])
			   )
			{
				int lb(left[i]), le(left[i]), rb(right[i]), re(right[i]);
				find_range(i,lb,le,lcnt,onel);
				find_range(i,rb,re,rcnt,oner);
				if (lb==rb) continue;
				if (re==R && lb==L && (le-lb==lcnt || lcnt+rcnt==cnt[i]) && jump)
				{
					for (int k=rb;k>=lb;k--) start[k+rcnt]=start[k], start[k]=false;
					start[lb]=true;
					pull_left(lb,re,oner,oner+rcnt);
					rb=re=right[i];
					find_range(i,rb,re,rcnt,oner);
					pull_left(rb,re,oner,oner+rcnt);
				}
				else
				{
					pull_right(lb,le,onel,onel+lcnt);
					pull_left(rb,re,oner,oner+rcnt);
				}
				for (int k=0;k<N;k++)
					if (left[k]>=L && right[k]<R && cnt[k]<R-L && done[k] && A[k][R-1]=='1')
						jump=false;
				if (right[i]-left[i]+1!=cnt[i])
					puts("NO"), exit(0);
				done[i]=true, ok=false;
				break;
			}
	}
	for (int i=L,j=i+1;i<R;i=j,j++)
	{
		while (!start[j]) j++;
		Split(i,j);
	}
}

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d",&N);
	for (int i=0;i<N;i++)
	{
		scanf("%s",A[i]);
		for (int j=0;j<N;j++)
			if (A[i][j]=='1') cnt[i]++;
		if (!cnt[i]) done[i]=true;
	}
	find_term();
	start[0]=start[N]=true;
	Split(0,N);
	puts("YES");
	for (int i=0;i<N;i++)
		puts(A[i]);
	return 0;
}

