// STD !!!

#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8;
struct point
{
	double x,y;
}P[110];
const point _0={0,0};
int n;
inline double dist(point a,point b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
bool check(point A,double d)
{
	int i;
	for (i=1;i<=n;i++)
		if (sqrt(dist(A,P[i]))+eps<d) return false;
	return true;
}
int main()
{
	freopen("hole.in","r",stdin), freopen("hole.ans","w",stdout);
	point Q,R;
	double d1,d2,d3,A,B,C,D,E,F,_d,ans;
	int i,j,k,l;
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%lf%lf",&P[i].x,&P[i].y);
	ans=-1;
	for (i=1;i<=n-2;i++)
		for (j=i+1;j<=n-1;j++)
			for (k=j+1;k<=n;k++)
			{
				d1=dist(P[i],P[j]); d2=dist(P[j],P[k]); d3=dist(P[i],P[k]);
				if ((d1+d2>d3)&&(d1+d3>d2)&&(d2+d3>d1))
				{
					A=2*(P[j].x-P[i].x); B=2*(P[j].y-P[i].y);
					C=dist(_0,P[j])-dist(_0,P[i]);
					D=2*(P[k].x-P[i].x); E=2*(P[k].y-P[i].y);
					F=dist(_0,P[k])-dist(_0,P[i]);
					Q.x=(C*E-B*F)/(A*E-B*D); Q.y=(C*D-A*F)/(B*D-A*E);
					_d=sqrt(dist(Q,P[i]));
					if (check(Q,_d)) ans=max(ans,_d);
				}
			}
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++)
			if (i!=j)
				for (k=1;k<=n;k++)
					if ((i!=j)&&(j!=k)&&(i!=k))
					{
						d1=dist(P[i],P[j]); d2=dist(P[j],P[k]); d3=dist(P[i],P[k]);
						if (fabs(d1+d2-d3)<eps)
						{
							Q.x=(P[i].x+P[k].x)/2; Q.y=(P[i].y+P[k].y)/2;
							R.x=2*Q.x-P[j].x; R.y=2*Q.y-P[j].y;
							for (l=1;l<=n;l++)
								if ((fabs(R.x-P[l].x)<eps)&&(fabs(R.y-P[l].y)<eps))
								{
									_d=sqrt(dist(Q,P[i]));
									if (check(Q,_d)) ans=max(ans,_d);
									break;
								}
						}
					}
	if (ans<0) printf("-1\n");
	else printf("%.6lf\n",ans);
	return 0;
}

// STD !!!
