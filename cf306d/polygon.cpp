#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

const long double pi=acosl(-1), x00=0, y00=0, X0=100, Y0=0;

int N;
long double X, Y, _X, _Y, x, y;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	srand(918);
	scanf("%d",&N);
	if (N<=4) return puts("No solution"), 0;
	x=x00+100, y=y00;
	printf("%.5f %.5f\n",(double)x,(double)y);
	for (int i=2;i<=N;i++)
	{
		X=X0*cosl((i-1)*2*pi/N)-Y0*sinl((i-1)*2*pi/N);
		Y=Y0*cosl((i-1)*2*pi/N)+X0*sinl((i-1)*2*pi/N);
		_X=X0*cosl(i*2*pi/N)-Y0*sinl(i*2*pi/N);
		_Y=Y0*cosl(i*2*pi/N)+X0*sinl(i*2*pi/N);
		long double p=((x00-(N-i)*0.1*X0-x)*_Y-(y00-y)*_X)/(X*_Y-Y*_X);
		if (p<1/X0) p=1/X0;
		long double q=(y00+(N-i)-y)/Y;
		if (i==N) p=q;
		if (Y>=0 || q<1e-9 || q>1) q=1;
		if (q<p) q=p;
		p+=(q-p)*rand()/RAND_MAX;
		x+=X*p, y+=Y*p;
		printf("%.5f %.5f\n",(double)x,(double)y);
	}
	return 0;
}

