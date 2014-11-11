#include<cctype>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const int maxl=450005, maxr=105, mo=1000003;

int tot, tank[30], C[maxl][maxr], f[30][maxr];

int main()
{
	freopen("runs.in","r",stdin);
	freopen("runs.out","w",stdout);
	for (int i=0;i<=450000;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=min(100,i);j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	}
	int T;
	scanf("%d",&T);
	for (int tt=1;tt<=T;tt++)
	{
		tot=0;
		memset(tank,0,sizeof tank);
		char last(0), c;
		scanf(" ");
		while (isalpha(c=getchar()))
		{
			if (last!=c) tot++;
			tank[c-'a'+1]++;
			last=c;
		}
		for (int i=2;i<=26;i++) tank[i]+=tank[i-1];
		memset(f,0,sizeof f);
		f[0][0]=1;
		for (int i=1;i<=26;i++)
		{
			if (tank[i]>tank[i-1])
			{
				for (int j=1;j<=tot;j++)
					for (int p=0; 2*p<=j+1 && p<=tank[i]-tank[i-1]; p++)
						for (int q=max(0,-tank[i-1]+j-p); j-p-2*q+1>=p && j-p-2*q>=0 && p+q<=tank[i]-tank[i-1]; q++) if (p || q)
							f[i][j]=(f[i][j]+(ll)f[i-1][j-p-2*q]*C[j-p-2*q+1][p]%mo*C[tank[i-1]-j+p+2*q][q]%mo*C[tank[i]-tank[i-1]-1][p+q-1])%mo;
			}
			else
				for (int j=0;j<=tot;j++)
					f[i][j]=f[i-1][j];
		}
		printf("Case #%d: %d\n",tt,f[26][tot]);
	}
	return 0;
}

