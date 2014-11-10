#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=85;

int N, n, sep[maxn<<1], L[maxn], R[maxn], minL[maxn][maxn], maxR[maxn][maxn];
double ans[maxn][maxn], f[maxn][maxn][maxn], reci[maxn];

void Push(int x, int i, int z)
{
	double a, b, c;
	a=double(min(sep[x],R[z])-L[z])*reci[z];
	b=double(sep[x+1]-sep[x])*reci[z];
	c=double(R[z]-max(L[z],sep[x+1]))*reci[z];
	memset(f[i+1],0,sizeof f[i+1]);
	for (int j=0;j<=i;j++)
		for (int k=0;k<=i-j;k++)
		{
			if (L[z]<sep[x])
				f[i+1][j+1][k]+=f[i][j][k]*a;
			if (L[z]<=sep[x] && R[z]>sep[x])
				f[i+1][j][k+1]+=f[i][j][k]*b;
			if (R[z]>sep[x+1])
				f[i+1][j][k]+=f[i][j][k]*c;
		}
}

void Calc(int x, int l, int r)
{
	if (l==r)
	{
		if (L[l]<=sep[x] && R[l]>sep[x])
		{
			double p=double(sep[x+1]-sep[x])*reci[l];
			for (int i=0;i<=N-1;i++)
				for (int j=0;j<=N-1-i;j++)
				{
					ans[l][i+1]+=f[N-1][i][j]*p/(j+1);
					ans[l][i+j+2]-=f[N-1][i][j]*p/(j+1);
				}
		}
		return;
	}
	int mid((l+r)>>1);
	if (minL[l][mid]<=sep[x] && maxR[l][mid]>sep[x])
	{
		for (int i=N-(r-l+1),z=mid+1;z<=r;i++,z++)
			Push(x,i,z);
		Calc(x,l,mid);
	}
	if (minL[mid+1][r]<=sep[x] && maxR[mid+1][r]>sep[x])
	{
		for (int i=N-(r-l+1),z=l;z<=mid;i++,z++)
			Push(x,i,z);
		Calc(x,mid+1,r);
	}
}

int main()
{
	freopen("rank.in","r",stdin);
	freopen("rank.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		scanf("%d%d",&L[i],&R[i]);
		sep[n++]=L[i], sep[n++]=R[i];
		reci[i]=1.0/(R[i]-L[i]);
	}
	for (int i=1;i<=N;i++)
	{
		minL[i][i-1]=0;
		maxR[i][i-1]=0x7fffffff;
		for (int j=i;j<=N;j++)
		{
			minL[i][j]=min(minL[i][j-1],L[j]);
			maxR[i][j]=max(maxR[i][j-1],R[j]);
		}
	}
	sort(sep,sep+n);
	n=unique(sep,sep+n)-sep;
	f[0][0][0]=1;
	for (int i=0;i<n-1;i++)
		Calc(i,1,N);
	for (int i=1;i<=N;i++)
	{
		double p(0);
		for (int j=1;j<=N;j++)
		{
			printf("%.8f",p+=ans[i][j]);
			putchar(j<N?' ':'\n');
		}
	}
	return 0;
}

