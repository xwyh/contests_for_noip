#include<bits/stdc++.h>//f[i][j]->V<==>i Num<==>j; 
#define N 1010
#define P 1000000007
#define int long long
using namespace std;
int n,m,f[N][60],c[N][60],t[N],ans[N][60];
void work()
{
	int n=1000,m=50,i,j,k;
	f[0][0]=1;
	for(i=1;i<=n;i++)//current item
		for(j=n;j-i>=0;j--)//V
			for(k=m;k>0;k--)//number
				f[j][k]=(f[j][k]+f[j-i][k-1])%P;
	for(i=0;i<=1000;i++) c[i][1]=1;
    for(j=2;j<=m;j++) 
        for(i=0;i<=n;i++)
            for(k=0;k<=i;k++)
                c[i][j]=(c[i][j]+c[i-k][j-1])%P;
	t[1]=1; for(i=2;i<=m;i++) t[i]=(t[i-1]*i)%P;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			for(k=1;k<=i;k++)
				ans[i][j]=(ans[i][j]+(f[k][j]*c[i-k][j+1])%P)%P;
			ans[i][j]=(ans[i][j]*t[j])%P;
		}
}
main()
{
	int i,j,T;
	work();
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%I64d %I64d",&n,&m);
		if(m>50) {puts("0"); continue;}
		printf("%I64d\n",ans[n][m]);
	}
	return 0;
}
