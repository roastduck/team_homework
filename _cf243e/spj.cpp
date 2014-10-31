#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<set>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

const int maxn=505;

int N;
vector<bool> column[maxn];
multiset< vector<bool> > T;
fstream IN, OUT, ANS, LOG;

void bye(int score)
{
	LOG << score << endl;
	exit(0);
}

int main(int argc, char **argv)
{
	IN.open(argv[1],fstream::in);
	OUT.open(argv[2],fstream::in);
	ANS.open(argv[3],fstream::in);
	LOG.open(argv[4],fstream::out);
	if (!OUT.good()) bye(0);
	IN >> N;
	string s1, s2, t;
	getline(OUT,s1), getline(ANS,s2);
	if (s1!=s2) bye(0);
	if (s1=="NO")
	{
		OUT >> t;
		bye(!OUT.good());
	}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
		{
			char c;
			IN >> c;
			column[j].push_back(c=='1');
		}
	T.insert(column,column+N);
	for (int i=0;i<N;i++)
		column[i].clear();
	for (int i=0;i<N;i++)
	{
		OUT >> t;
		if (!OUT.good() || (int)t.length()!=N) bye(0);
		int status(0);
		for (int j=0;j<N;j++)
		{
			char c(t[j]);
			if (c!='0' && c!='1') bye(0);
			if (status==0 && c=='1') status=1;
			if (status==1 && c=='0') status=2;
			if (status==2 && c=='1') bye(0);
			column[j].push_back(c=='1');
		}
	}
	for (int i=0;i<N;i++)
	{
		multiset< vector<bool> > :: iterator pos = T.find(column[i]);
		if (pos==T.end()) bye(0);
		T.erase(pos);
	}
	OUT >> t;
	bye(!OUT.good());
	return 0;
}

