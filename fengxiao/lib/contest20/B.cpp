#include<cstdio>
#include<cstring>
#define N 1010
using namespace std;
int n,k,a[N],ans=0;
int sum[N];
int map[N][N],bas;
bool used[N];
int main()
{
	int i,j;
	scanf("%d %d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		if(!used[i])
			for(j=i;j<=n;j++)
				if(a[j]-a[i]==k*(j-i))
				{
					used[j]=1;
					map[i][++map[i][0]]=j;
				}
	int maxn=0,pos=0;
	for(i=1;i<=n;i++)
		if(map[i][0]>maxn && a[i]-k*(i-1)>0) {maxn=map[i][0]; pos=i;}
	printf("%d\n",n-map[pos][0]);// printf("%d %d?",pos,bas);
	memset(used,0,sizeof(used));
	for(i=1;i<=map[pos][0];i++) used[map[pos][i]]=1;
	bas=a[pos]-k*(pos-1);
	for(i=1;i<=n;i++)
		if(!used[i])
		{
			if(bas+k*(i-1)>a[i]) printf("+ %d %d\n",i,bas+k*(i-1)-a[i]);
			else  printf("- %d %d\n",i,a[i]-(bas+k*(i-1)));
		}
	return 0;
}
