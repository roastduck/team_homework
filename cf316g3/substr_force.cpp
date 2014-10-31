#include<cstdio>
#include<cstring>
#include<set>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int m, L[15], R[15], ans;
string s, t[15];
set<string> S;

int main()
{
	freopen("substr.in","r",stdin);
	freopen("substr.ans","w",stdout);
	cin >> s >> m;
	for (int i=1;i<=m;i++)
		cin >> t[i] >> L[i] >> R[i];
	for (int i=0;i<(int)s.length();i++)
		for (int j=1;j<=(int)s.length()-i;j++)
		{
			string tmp=s.substr(i,j);
			bool ok(true);
			for (int k=1;k<=m && ok;k++)
			{
				int cnt(0);
				for (int p=0;p<=(int)t[k].length()-j;p++)
					if (tmp==t[k].substr(p,j)) cnt++;
				if (cnt<L[k] || cnt>R[k]) ok=false;
			}
			if (ok && S.find(tmp)==S.end())
			{
				S.insert(tmp);
				ans++;
			}
		}
	printf("%d\n",ans);
	return 0;
}

