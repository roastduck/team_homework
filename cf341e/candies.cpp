#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, a[1005], name[1005], ans[1000005][2];

inline void Move(int x, int y)
{
	a[y]-=a[x], a[x]<<=1;
	m++, ans[m][0]=name[x], ans[m][1]=name[y];
}

inline void Reduce()
{
	int p(a[2]/a[1]);
	for (int k=1;k<=p;k<<=1) Move(1,p&k?2:3);
}

inline void Sort()
{
	if (a[2]<a[1]) swap(a[1],a[2]), swap(name[1],name[2]);
	if (a[3]<a[1]) swap(a[1],a[3]), swap(name[1],name[3]);
	if (a[3]<a[2]) swap(a[2],a[3]), swap(name[2],name[3]);
}

int main()
{
	freopen("candies.in","r",stdin);
	freopen("candies.out","w",stdout);
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	{
		int x;
		scanf("%d",&x);
		if (x) n++, a[n]=x, name[n]=i;
	}
	if (n<2) return puts("-1"), 0;
	while (n>2)
	{
		do Sort(), Reduce(); while (a[2]);
		name[2]=name[n], a[2]=a[n], n--;
	}
	printf("%d\n",m);
	for (int i=1;i<=m;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}

