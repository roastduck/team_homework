#include<cstdio>
#include<cstring>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int,int> PI;

int N, M, X, Y, dx, dy, d;
long long ans;
map<PI,int> S;

int GO()
{
	int t(min(max((N-X)*dx,(1-X)*dx),max((M-Y)*dy,(1-Y)*dy)));
	X+=dx*t, Y+=dy*t;
	dx=(X==N? -1: X==1? 1: dx);
	dy=(Y==M? -1: Y==1? 1: dy);
	if (dx==-1 && dy==1) d=1;
	if (dx==1 && dy==1) d=2;
	if (dx==1 && dy==-1) d=4;
	if (dx==-1 && dy==-1) d=8;
	return t;
}

int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	string s;
	cin >> N >> M >> X >> Y >> s;
	if (s=="UR") dx=-1, dy=1, d=1;
	if (s=="DR") dx=1, dy=1, d=2;
	if (s=="DL") dx=1, dy=-1, d=4;
	if (s=="UL") dx=-1, dy=-1, d=8;
	if (X>1 && X<N && Y>1 && Y<M) GO();
	do
		S[PI(X,Y)]|=d, ans+=GO();
	while (!(S[PI(X,Y)]&d) && S.size()<N+M-2);
	cout << (S.size()<N+M-2? -1ll: ans+1) << endl;
	return 0;
}

