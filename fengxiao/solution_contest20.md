# Solution of contest 20
```
/******************
    VJudge链接：  https://cn.vjudge.net/contest/172463
CodeForces链接：  http://codeforces.com/contest/403&402

题目按CF顺序排序
******************/
```
# #A Nuts 
```
/******************
     主要算法：模拟
     Data limit:k, a, b, v (2 ≤ k ≤ 1000; 1 ≤ a, b, v ≤ 1000)
******************/
```
### 题意
你有a个东西要放到盒子中,你有b个隔断可以分割某个盒子,但最多只能将盒子分成k份,每份盒子最多能放v个东西   
问你最少能用几个盒子放下a个东西 
### 题解
首先想想就知道如果有隔断一定先用完隔断,那么问题就是如何简便得处理隔断  
那么只需对k和剩下的隔断取个min即可  
这样统一处理便可  
注意先把k--  
### 核心代码
```
/******************
	scanf("%d %d %d %d",&k,&a,&b,&c); k--;
	while(1)
	{
		ans++;
		int t=min(k,b); b-=t;
		a-=(t+1)*c;
		if(a<=0) {printf("%d",ans); return 0;}
	}
******************/
```
### 错题记录
1A
***
# #B Trees in a Row 
```
/******************
    主要算法： 模拟
     Data limit: n, k (1 ≤ n, k ≤ 1000).
******************/
```
### 题意
给你一个序列的初始状态,要求将这个序列通过一些操作变为等差数列  
操作:可以改变任意一个数至任意值  
问最少进行多少次操作达成目标  
### 题解
我们可以将序列分成若干个集团,每个集团的性质就是(a[i]-a[j])/(i-j)==k即它们为初始差值就等于k的序列  
统计这些集团的成员数,那么修改的数就是n-max(集团成员数)  
然后根据那个集团的性质便可以推出所有的数字  
### 核心代码
```
/******************
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
******************/
```
### 错题记录
输出的时候算式写错了...
***
# #C Strictly Positive Matrix 
```
/******************
      主要算法：数论+图论(tarjan or floyd)
     Data limit: n (2 ≤ n ≤ 2000) 
******************/
```
### 题意
给你一个矩阵a,满足矩阵非负,问是否有a^k使矩阵为全正  
### 题解
由于不可能存在负数所以可以直接把矩阵化为01矩阵   
再根据数竞大佬的结论:a^k中a[i][j]的意义是i走k步到j的方案数  
那么可以分析出算法的雏形:只需判断这个矩阵在图的意义下是否联通即可  
由于这图是有向边,所以dfs和bfs都是会n^3而崩的  
于是便想到tarjan强联通分量,然后判断是否整个图都是强联通即可  
(听说有人用floyd+bitset水过,我也不知道是怎么水的)  
### 核心代码
```
/******************
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
******************/
```
### 错题记录
比赛的时候没想到数竞dalao的结论只打了个最裸的暴力然后GG了  
***
# #D Beautiful Pairs of Numbers 
```
/******************
      主要算法：DP+数学
     Data limit: t (1 ≤ t ≤  2*1e5) n and k (1 ≤ k ≤ n ≤ 1000).
******************/
```
### 题意
美丽数列定义:0<a1<=b1<a2<=b2<b3<=b4...<ak<=bk<=n  
给定n,k,求在此情况下美丽数列的数量  
### 题解
比赛的时候看到这题以为是DP+组合数然后写了个DP部分就不会写了      
其实实际上也差不多  
数组意义:f[i][j]->背包空间为i,选j个的方案数,c[i][j]->i个空间,j个空位,空位排列方式不同的方案数,ans[i][j]->i个空间放j个物品的最终答案,t[i]->i!
我们可以将这个问题抽象成背包:有n个空间,最多可以放50个物品(算一下sigma(1~50)就知道了),问有多少种取法  
由于该背包只要顺序不同或者空位不同便算不同的方案所以进行如下处理:  
顺序不同:直接乘个阶乘就可以了  
空位不同:利用c数组乘一下  
转移方程见代码中  
### 核心代码
```
/******************
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
******************/
```
### 错题记录
mdzz调了半天发现取模取错了  

***
# #E Upgrading Array 
```
/******************
      主要算法： 模拟
     Data limit: n and m (1 ≤ n, m ≤ 5000)
******************/
```
### 题意
给你若干个素数,定义其为bad prime
定义一个数字的美丽值如下:定义i的最小质因数为p f(i)=i==1 ? 0 :(p is bad prime ? f(i/p)-1 : f(i/p)+1);  
给你一个数列,数列的美丽值为其中元素的美丽值之和  
可以对数列进行如下操作:  
对序列前r个数取gcd,然后前r个数都除以gcd  
问进行若干次操作后序列最大的美丽值  
### 题解
首先分析美丽值的计算公式,可以发现一个数的美丽值其实就是其中好的质因数数量-坏的质因数数量  
于是只要从后往前扫一遍,如果除gcd之后赚了的话就除,否则继续向前即可  
### 核心代码
```
/******************
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
			for(j=1;j<=i;j++)
				a[j]/=g[i],g[j]/=g[i];
	for(i=1;i<=n;i++) ans+=calc(a[i]);
	printf("%d",ans);
}
******************/
```
###错题记录
刚开始写的太不清真了,常数爆炸,然后T了
***
# #F Searching for Graph
```
/******************
      主要算法：玄学
     Data limit:n (2 ≤ n ≤ 2*1e5)
******************/
```
### 题意
给你n,p,让你让你构建一个图,是的这幅图的边数恰好为2*n+p,其中任意子图的边数<=2*点数+p  
让你输出一种满足的方案  

### 题解
对着样例写  
如果还有边剩下就从1到n填...  
玄学不会证明啊
### 核心代码
```
/******************
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
******************/
```
###错题记录

***
# #G Two Rooted Trees (还不会做)
```
/******************
      主要算法：
     Data limit:
******************/
```
### 题意


### 题解

### 核心代码
```
/******************

******************/
```
###错题记录

***
