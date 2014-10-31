#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int T;
char O[35][20];

#define C0 1
#define C1 2
#define C2 3
#define D0 4
#define D1 5
#define f(S,M,D,NS,NM) sprintf(O[T++], "%d %d -> %c %d %d", S, M, D, NS, NM)
#define t(S,M) sprintf(O[T++], "%d %d -> R", S, M)

int main()
{
	freopen("turing.in","r",stdin);
	freopen("turing.out","w",stdout);
	int N, S(0);
	scanf("%d",&N);
	if (!N)
		t(0,0);
	else if (N==1)
		f(0,0,'E',1,0), t(1,0);
	else
	{
		N--;
		t(C0,0);
		f(C0,1,'E',C0,0);
		f(C0,2,'E',C2,0);
		f(C1,0,'W',D0,2);
		f(C1,1,'E',C1,1);
		f(C1,2,'E',C2,1);
		f(C2,0,'W',D1,1);
		f(C2,1,'E',C1,2);
		f(C2,2,'E',C2,2);
		f(D0,1,'W',D0,2);
		f(D0,2,'W',D1,1);
		f(D1,0,'E',C0,0);
		f(D1,1,'W',D1,1);
		f(D1,2,'W',D1,2);
		for (int k=1;k<=N;k<<=1,S--)
			f(S,0,'W',S-1,bool(N&k)+1);
		f(S,0,'E',C1,1);
	}
	printf("%d\n",T);
	while (T--)
		puts(O[T]);
	return 0;
}

