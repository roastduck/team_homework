#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PI;
typedef pair<int,PI> PII;
#define fi first
#define se second
#define it iterator

int N, M, ans[100005];
set<PI> S;

int main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d%d",&N,&M);
	vector<PII> ORI(M);
	vector<PI> NOW, QRY(N);
	for (int i=0;i<M;i++)
	{
		int l, r, t;
		scanf("%d%d%d",&l,&r,&t);
		ORI[i]=PII(t,PI(l,r));
	}
	sort(ORI.begin(),ORI.end());
	for (vector<PII>::it i=ORI.begin(); i!=ORI.end(); i++)
	{
		int LO=i->se.fi, HI=i->se.se;
		set<PI>::it lo=S.upper_bound(PI(LO,1)), hi=S.lower_bound(PI(HI,-1));
		if (lo!=hi)
		{
			if (lo!=S.end() && lo->se==-1) LO=(lo++)->fi;
			if (hi!=S.end() && hi->se==-1) HI=(--hi)->fi;
		}
		for (set<PI>::it j=lo;j!=hi;j++) 
			NOW.push_back(PI(i->fi-j->fi,j->se));
		S.erase(lo,hi);
		if (lo==hi && hi!=S.end() && hi->se==-1)
			continue;
		NOW.push_back(PI(i->fi-HI,1));
		NOW.push_back(PI(i->fi-LO,-1));
		S.insert(PI(HI,-1));
		S.insert(PI(LO,1));
	}
	sort(NOW.begin(),NOW.end());
	for (int i=0;i<N;i++)
	{
		scanf("%d",&QRY[i].fi);
		QRY[i].se=i;
	}
	sort(QRY.begin(),QRY.end());
	int cnt(0);
	long long tot(0);
	for (vector<PI>::it i=QRY.begin(), j=NOW.begin(); i!=QRY.end(); i++)
	{
		while (j!=NOW.end() && j->fi<i->fi) tot+=j->fi*j->se, cnt+=j->se, j++;
		ans[i->se]=(long long)i->fi*cnt-tot;
	}
	for (int i=0;i<N;i++) printf("%d\n",ans[i]);
	return 0;
}

