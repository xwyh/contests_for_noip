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
