#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 120000
using namespace std;
int pos,ft[N*40][10],n,bo[N],i,j,x,y,xx,yy,t[10],m;
char c[N];
vector<int> v[N];
void add(int x){
	++pos;
	v[x].push_back(pos);
	for(int i=0;i<10;++i)ft[pos][i]=t[i];
}
void work(){
	int i,j,l,d,last;
	for(l=1;l<=n;++l)if(!bo[l]){
		i=l; d=1; last=0;
		while(i>=l && i<=n){
			bo[i]=1;
			if(c[i]>='0' && c[i]<='9'){
				t[c[i]-48]++;
				c[i]--;
				last=0;
			}else if(c[i]=='>' || c[i]=='<'){
				d=(c[i]=='>'?1:-1);
				if(last)c[last]=0;
				last=i;
			}
			add(i);
			i+=d;
		}
		add(i);
	}
}
int Find(int x,int y){
	int s=lower_bound(v[x].begin(),v[x].end(),y)-v[x].begin();
	if(s==v[x].size())return 1<<30;
	return v[x][s];
}
int main(){
	freopen("tape.in","r",stdin), freopen("tape.ans","w",stdout);
	scanf("%d%d%s",&n,&m,c+1);
	work();
	for(i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		xx=v[x][0];
		yy=min(Find(x-1,xx),Find(y+1,xx));
		for(j=0;j<10;++j)printf("%d%c",ft[yy-1][j]-ft[xx-1][j],j==9?'\n':' ');
	}
}

