#include<bits/stdc++.h>
using namespace std;
int a,b,k,c,ans=0;
int main()
{
	int i;
	scanf("%d %d %d %d",&k,&a,&b,&c); k--;
	while(1)
	{
		ans++;
		int t=min(k,b); b-=t;
		a-=(t+1)*c;
		if(a<=0) {printf("%d",ans); return 0;}
	}
	return 0;
}
