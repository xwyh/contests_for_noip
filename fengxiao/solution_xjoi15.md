# Solution
```
/******************
xjoi链接：http://www.hzxjhs.com:83/contest/768
******************/
```
# #A mountain
```
/******************
     主要算法：二分+
     Data limit:
     30%的数据 n,m<=1000
     100%的数据 n,m<=300000,max(|h[i]|)<10^12,max(|h[i]+i*p|)<10^18,
******************/
```
### 题意
给你长度为n的数组a，a[i]表示这座山的高度，并且给你一些斜率值  
山的绝对高度满足:h=a[i]+sita*(i-1)  
求在每个斜率下绝对高度最小的山峰的高度  
（斜率可能为负）
### 题解
先将a数组按价值（高度）顺序排序  
分析可发现当斜率增大时最矮山峰的位置呈不下降的折线，也就是说在一定区间中是同一座山当最小山峰，然后是下一座。。。  
于是就可以想到二分的方法，二分状态记录当时准备计算的斜率区间的左右端点，及待计算的两个点  
如果这两个点算出来的答案是一样的，那么说明中间的也是如此，那么可以直接计算，否则继续二分  
然后对相应的询问输出ans即可  
### 核心代码
```
/******************
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 300010
#define int long long
using namespace std;
const int INF=1e17;
int n,m;
struct P{int a,pos;} a[N];
int h[N],ans[N];
bool cmp(P a,P b) {return a.a>b.a;}
inline int get_p(int p,int l,int r)
{
    int minn=INF,pos=0;
    for(int i=l;i<=r;i++)
    {
        int tmp=h[i]+i*a[p].a;
        if(tmp<minn) {minn=tmp; pos=i;}
    }
    return pos;
}
void bs(int s,int e,int l,int r)
{
    if(s==e) {int p=get_p(s,l,r); ans[a[s].pos]=h[p]+a[s].a*p; return;}
    int p1=get_p(s,l,r),p2=get_p(e,l,r);
    if(p1==p2)
    {
        for(int i=s;i<=e;i++) ans[a[i].pos]=h[p1]+a[i].a*p1;
        return;
    }
    ans[a[s].pos]=h[p1]+a[s].a*p1;
    ans[a[e].pos]=h[p2]+a[e].a*p2;
    int mid=(s+e)/2;
    if(s+1<=mid) bs(s+1,mid,p1,p2);
    if(mid+1<=e-1) bs(mid+1,e-1,p1,p2);
}
main()
{
    int i;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++) scanf("%lld",&h[i]);
    for(i=1;i<=m;i++) scanf("%lld",&a[i].a),a[i].pos=i;
    sort(a+1,a+m+1,cmp);
    bs(1,m,1,n);
    for(i=1;i<=m;i++) printf("%lld\n",ans[i]);
    return 0;
}
******************/
```
### 错题记录

***
# #B 
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
### 错题记录

***
# #C 
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
### 错题记录

***
