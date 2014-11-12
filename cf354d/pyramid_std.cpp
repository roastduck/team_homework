// STD !!

#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef vector<int> V;
typedef V::iterator Vi;

const int N = int(1e5 + 5);
const int M = 1005;

int f[2][N], n, k;

V vec[N];

int min(int x, int y){return x<y ? x:y;}

int main()
{
	freopen("pyramid.in","r",stdin), freopen("pyramid.ans","w",stdout);
	scanf("%d%d", &n, &k);
	for(int i=1, x, y; i<=k; i++) scanf("%d%d", &x, &y), vec[y+n-x].push_back(n-x+1);
	for(int i=1; i<=n; i++) sort(vec[i].begin(), vec[i].end());
	
	int p = int(sqrt(6 * k) + 0.5);
	
	for(int i=1; i<=n; i++)
	{
		int e(i&1), g(1-e), j(min(p,i)), cnt(0), q(vec[i].size()-1);
		for(f[e][j+1]=1e9; j>=0; j--)
		{
			for(; q>=0 && vec[i][q]>j+1; q--) cnt++;
			f[e][j] = min(f[e][j+1], f[g][j]+(j+2)*(j+1)/2+2+3*cnt);
		}
		q = vec[i].size() - 1, cnt = 0, j = min(p,i);
		for(; j; j--)
		{
			for(; q>=0 && vec[i][q]>j; q--) cnt++;
			f[e][j] = min(f[e][j], f[g][j-1] + 3*cnt);
		}
		f[e][0] = min(f[e][0], f[g][0] + 3 * vec[i].size());
	}
	
	printf("%d\n", f[(n&1)][0]);
	
	return 0;
}

// STD !!
