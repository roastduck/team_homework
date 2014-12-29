#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=255;

int N, ans, X[maxn], Y[maxn], no[maxn][maxn], f[maxn][maxn];
double dir[maxn];

inline bool cmp(int a, int b) { return dir[a]<dir[b]; }
inline int cross(int x1, int y1, int x2, int y2) { return x1*y2-x2*y1; }

int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
		scanf("%d%d",&X[i],&Y[i]);
	for (int i=1;i<=N;i++)
	{
		for (int j=1,k=0;j<=N;j++) if (j!=i)
		{
			no[i][++k]=j;
			dir[j]=atan2(Y[j]-Y[i],X[j]-X[i]);
		}
		sort(no[i]+1,no[i]+N,cmp);
	}
	for (int i=1;i<=N;i++)
	{
		memset(f,0,sizeof f);
		for (int pp=1;pp<N;pp++)
		{
			int p=no[i][pp], qq, q=-1, rr, r;
			if (X[p]<X[i]) continue;
			for (int kk=1;kk<N;kk++)
			{
				int k=no[p][kk];
				if (X[k]<X[i]) continue;
				if (k==i) rr=kk, r=k;
				if (cross(X[p]-X[i],Y[p]-Y[i],X[k]-X[p],Y[k]-Y[p])<=0) continue;
				if (!~q || cross(X[k]-X[p],Y[k]-Y[p],X[q]-X[p],Y[q]-Y[p])>0) qq=kk, q=k;
			}
			if (!~q) break;
			int MAX(0);
			for (; cross(X[p]-X[i],Y[p]-Y[i],X[q]-X[p],Y[q]-Y[p])>0; qq%=N-1, qq++, q=no[p][qq])
			{
				if (X[q]<X[i]) continue;
				for (; cross(X[p]-X[r],Y[p]-Y[r],X[q]-X[p],Y[q]-Y[p])>0; rr%=N-1, rr++, r=no[p][rr])
					if (X[r]>=X[i]) MAX=max(MAX,f[r][p]);
				ans=max(ans,f[p][q]=MAX+1);
			}
		}
	}
	printf("%d\n",ans+2);
	return 0;
}

