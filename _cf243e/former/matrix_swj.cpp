#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define fo(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef vector<int> table;
typedef vector<table> matrix;
const int mn=510;
int n,a[mn][mn],cntb[mn];
int perm[mn],mark[mn];
table e[mn];
char map[mn][mn];
bool split(matrix&u,table&b,matrix&wh,int r)
{
    int k=b[r];
    swap(b[r],b.back());
    b.pop_back();
    matrix nu,nwh;
    fo(D,0,1)
    {
        int seen=0;
        bool fail=0;
        nu.clear(),nwh.clear();
        fo(i,0,(int)u.size()-1)
        {
            table x[2];
            fo(j,0,(int)u[i].size()-1)
            {
                int z=u[i][j];
                x[a[k][z]].pb(z);
            }
            int pp[2]={nu.size()+1,nu.size()};
            if(!seen&&i!=u.size()-1)
            {
                swap(pp[0],pp[1]);
                if(x[0].size())nu.pb(x[0]);
                if(x[1].size())nu.pb(x[1]),seen=1;
            }
            else
            {
                if(x[1].size()&&seen==2){fail=1;break;}
                if(x[1].size())nu.pb(x[1]);
                if(x[0].size())nu.pb(x[0]),seen=2;
            }
            if(fail)break;
            nwh.resize(nu.size());
            if(x[0].size()&&x[1].size())
            {
                int p=1;
                if(x[0].size()<x[1].size())p=0;
                fo(j,0,(int)wh[i].size()-1)
                {
                    int cnt=0;
                    int z=wh[i][j];
                    if(z==k)continue;
                    fo(k,0,(int)x[p].size()-1)cnt+=a[z][x[p][k]];
                    if(cnt&&cnt!=cntb[z])mark[z]=1;
                    else
                    {
                        if(cnt==cntb[z])nwh[pp[p]].pb(z);
                        else nwh[pp[p^1]].pb(z);
                    }
                }
            }
            else if(x[0].size()||x[1].size())nwh.back()=wh[i];
            if(i==u.size()-1&&!x[0].size())nwh.pb(table()),nu.pb(table());
        }
        if(fail)
        {
            reverse(u.begin(),u.end()-1);
            reverse(wh.begin(),wh.end()-1);
        }
        else
        {
            u=nu;
            wh=nwh;
            return 1;
        }
    }
    return 0;
}
bool solve(table&b,table&in,int lo)
{
    fo(i,0,(int)b.size()-1)
        if(mark[b[i]]||cntb[b[i]]==in.size())
        {
            swap(b[i],b.back());
            b.pop_back();
        }
    if(!b.size())
    {
        fo(i,0,(int)in.size()-1)perm[in[i]]=lo+i;
        return 1;
    }
    int best=0;
    fo(i,0,(int)b.size()-1)if(cntb[b[i]]>cntb[b[best]])best=i;
    matrix uu;uu.pb(in);
    matrix wh;wh.pb(b);
    mark[b[best]]=1;
    if(!split(uu,b,wh,best))return 0;
    while(b.size())
    {
        int cnd=-1;
        fo(i,0,(int)b.size()-1)if(mark[b[i]]){cnd=i;break;}
        if(cnd==-1)
        {
            fo(i,0,(int)uu.size()-1)
            {
                if(!solve(wh[i],uu[i],lo))return 0;
                lo+=uu[i].size();
            }
            return 1;
        }
        else
            if(!split(uu,b,wh,cnd))return 0;
    }
    fo(i,0,(int)uu.size()-1)
    {
        solve(wh[i],uu[i],lo);
        lo+=uu[i].size();
    }
    return 1;
}
int main()
{
    scanf("%d",&n);
    fo(i,0,n-1)
    {
        scanf("%s",map[i]);
        fo(j,0,n-1)
        {
            cntb[i]+=(a[i][j]=map[i][j]-48);
            if(a[i][j])e[i].pb(j);
        }
    }
    table tb,rt;
    fo(i,0,n-1)rt.pb(i);
    fo(i,0,n-1)
        if(cntb[i]>0&&cntb[i]<n)
            tb.pb(i);
    int res[mn][mn];
    if(solve(tb,rt,0))
    {
        puts("YES");
        fo(i,0,n-1)
            fo(j,0,n-1)
                res[i][perm[j]]=a[i][j];
        fo(i,0,n-1)
        {
            fo(j,0,n-1)
                printf("%d",res[i][j]);
            printf("\n");
        }
        return 0;
    }
    puts("NO");
    return 0;
}

