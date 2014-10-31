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
#define R 6
#define f(S,M,D,NS,NM) sprintf(O[T++], "%d %d -> %c %d %d", S, M, D, NS, NM);
#define t(S,M) sprintf(O[T++], "%d %d -> R", S, M);

int main()
{
	freopen("turing.in","r",stdin);
	freopen("turing.out","w",stdout);
	f(C0,1,'E',C1,0);
	f(C1,0,'W',D0,2);
	f(C1,1,'E',C1,1);
	f(C1,2,'E',C2,1);
	f(C2,0,'W',D1,1);
	f(C2,1,'E',C1,2);
	f(C2,2,'E',C2,2);
	f(D0,0,'E',R,3);
	f(D0,1,'W',D0,2);
	f(D0,2,'W',D1,1);
	f(D1,0,'E',C0,0);
	f(D1,1,'W',D1,1);
	f(D1,2,'W',D1,2);
	t(R,0);
	f(R,1,'E',R,3);
	f(R,2,'E',R,3);
	int N, S;
	scanf("%d",&N);
	if (N<2)
	{
		f(0,0,'W',-1,0);
		f(-1,0,'W',-2,0);
		S=-2;
	} else
		S=0, N-=2;
	for (int k=1;k<=N;k<<=1,S--)
		f(S,0,'W',S-1,bool(N&k)+1);
	f(S,0,'E',C1,1);
	printf("%d\n",T);
	while (T--)
		puts(O[T]);
	return 0;
}

