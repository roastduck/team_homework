#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long double ld;
typedef unsigned long long ull;

const ull mo=10000000000ull;

struct NUM
{
	ld x;
	ull y;
	
	NUM() {}
	NUM(ull v) : x(v), y(v%mo) {}
	NUM(ld _x, ull _y) : x(_x), y(_y) {}
	
	void output()
	{
		if (x>=1e10)
			printf("...%010I64u\n",y);
		else
			printf("%I64u\n",y);
	}
	
	NUM div3()
	{
		return NUM(x/3, y%3==0? y/3: (y+mo)%3==0? (y+mo)/3: (y+2*mo)/3);
	}
};

inline NUM operator+(const NUM &a, const NUM &b)
{
	return NUM(a.x+b.x,(a.y+b.y)%mo);
}

inline NUM operator-(const NUM &a, const NUM &b)
{
	return NUM(a.x-b.x,(mo+a.y-b.y)%mo);
}

inline NUM operator*(const NUM &a, const NUM &b)
{
	return NUM(a.x*b.x,a.y*b.y%mo);
}

NUM S(ull _n, ull _m)
{
	ull _t(min(_n,_m));
	NUM n(_n), m(_m), t(_t);
	if (_t&1) t = (_t*_t+1)/2*t*t; else t = _t/2*(t*t+1)*t;
	NUM a1, a2, A1, A2, B, ret(0);
	if (_m<_n)
	{
		a1 = _n*(_n+1)/2;
		a2 = _m*(_m+1)/2;
		A1 = a1*2*n+a1;
		A2 = a2*2*m+a2;
		B = _m*(_m-1)/2*(n-m);
		ret = (A1-A2).div3()*m-B;
	}
	if (_n<_m)
	{
		a1 = (_m-1)*_m/2;
		a2 = (_n-1)*_n/2;
		A1 = a1*2*m-a1;
		A2 = a2*2*n-a2;
		B = (_n*(_n-1)/2+n)*(m-n);
		ret = (A1-A2).div3()*n+B;
	}
	return ret+t;
}

int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int T;
	for (scanf("%d",&T);T--;)
	{
		int x1, y1, x2, y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		(S(x2,y2)-S(x1-1,y2)-S(x2,y1-1)+S(x1-1,y1-1)).output();
	}
	return 0;
}

