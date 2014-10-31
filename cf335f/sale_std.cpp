#include <map>
#include <set>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
int n,a,v,s,p,t,j,k,l[500000];
long long ans;
map<int,int> m;
multiset<int> q;
int main()
{
    ios::sync_with_stdio(0);
    cin>>n;
    while(n--)cin>>a,m[a]++,ans+=a;
    map<int,int>::reverse_iterator i=m.rbegin();
    for(;i!=m.rend();i++){
        v=i->first;n=i->second;
        t=min((n+s)/2,s);p=max(t-n,0);
        for (j=t-1;j>=p;j--)
        if (j<q.size()){
            l[j]=*q.begin(); q.erase(q.begin());
        }
        else l[j]=0;
        for (j=p,k=s-j;j<k&&j<t;j++)
        if (l[j]<v) l[j]=v;
        else if (k--<t+1)l[k]=max(0,2*v-l[j]);
        q.insert(l+p,l+t);
        s+=n;
    }
    cout<<ans-accumulate(q.begin(),q.end(),0LL)<<endl;
}

