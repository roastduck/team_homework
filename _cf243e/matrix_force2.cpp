#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=505;

int N, order[maxn];
char A[maxn][maxn];

int main()
{
	scanf("%d",&N);
	for (int i=0;i<N;i++) order[i]=i;
	for (int i=0;i<N;i++)
		scanf("%s",A[i]);
	do
	{
		bool ok(true);
		for (int i=0;i<N;i++)
		{
			bool start(false), finish(false);
			for (int j=0;j<N;j++)
			{
				if (finish && A[i][order[j]]=='1')
				{
					ok=false;
					break;
				}
				start|=(A[i][order[j]]=='1');
				finish|=start && (A[i][order[j]]=='0');
			}
			if (!ok) break;
		}
		if (ok)
		{
			puts("YES");
			for (int i=0;i<N;i++)
			{
				for (int j=0;j<N;j++) putchar(A[i][order[j]]);
				putchar('\n');
			}
			return 0;
		}
	} while (next_permutation(order,order+N));
	puts("NO");
	return 0;
}

