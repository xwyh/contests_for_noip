#include<bits/stdc++.h>
#define N 2010
using namespace std;
int a[N][N],n;
int dfn[N],low[N],cnt=0;
stack<int> sta; bool ins[N],vis[N],flag=1;
void tarjan(int u)
{
	if(!flag) return;
	dfn[u]=low[u]=++cnt;
	sta.push(u);vis[u]=ins[u]=1;
	for(int i=1;i<=n;i++) 
		if(a[u][i] && i!=u)
		{
			if(!vis[i])
			{
				tarjan(i);
				low[u]=min(low[i],low[u]);
			}
			else if(ins[i]) low[u]=min(low[u],dfn[i]);
			if(!flag) return;
		}
	int sum=0;
	if(dfn[u]==low[u])
		{int p; do {sum++;p=sta.top(); sta.pop(); ins[p]=0;}while(u!=p); if(sum!=n) flag=0; return;}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
			if(a[i][j]) a[i][j]=1;
		}
	tarjan(1);
	puts(flag ? "YES" : "NO");
	return 0;
}
