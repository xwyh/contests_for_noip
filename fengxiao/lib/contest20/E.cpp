#include<bits/stdc++.h>
#define N 50010
using namespace std;
int n,m,ans,a[N],b[N],g[N];
map<int,bool> mp;
int gcd(int a,int b) {if(a<b) swap(a,b); return b==0? a : gcd(b,a%b);}
int calc(int x)
{
	int sum=0;
	for (int i=2;i*i<=x;i++) 
		while (x%i==0)
		{
			if (mp[i]) sum--; else sum++;
			x/=i;
		}
	if(x>1) if(mp[x]) sum--; else sum++;
	return sum;
}
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),g[i]=gcd(g[i-1],a[i]);
	for(i=1;i<=m;i++) scanf("%d",&b[i]),mp[b[i]]=1;
	for(i=n;i>=1;i--) 
		if(calc(g[i])<0)
		{
			for(j=1;j<=i;j++)
				a[j]/=g[i],g[j]/=g[i];
		//	printf("%d\n",i);
		}
//	for(i=1;i<=n;i++) printf("%d ",a[i]); puts("");
	for(i=1;i<=n;i++) ans+=calc(a[i]);
	printf("%d",ans);
}
