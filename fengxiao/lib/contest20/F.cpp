#include<cstdio>
#include<cstring>
#define N 30
using namespace std;
int n,p;
int main()
{
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		int cnt=0;
		scanf("%d %d",&n,&p);
		for(i=1;i<=n;i++)
			if(cnt<2*n+p)
				for(j=i+1;j<=n;j++)
					if(cnt<2*n+p)
					{
						printf("%d %d\n",i,j);
						cnt++;
					}
					else break;
			else break;
	}
	return 0;
}
