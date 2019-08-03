#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
const int maxlongint=2147483647;
const int mo=1000000007;
const int N=100005;
using namespace std;
int dis[N],d[N],root,last[N],next[N*2],to[N*2],v[N*2],s,e,ans=maxlongint,n,m,tot,size[N],mx,ff;
bool bz[N];
int bj(int x,int y,int z)
{
    next[++tot]=last[x];
    last[x]=tot;
    to[tot]=y;
    v[tot]=z;
}
int findroot(int x,int fa)
{
    size[x]=1;
    int num=0;
    for(int i=last[x];i;i=next[i])
    {
        int j=to[i];
        if(j!=fa && bz[j])
        {
            findroot(j,x);
            size[x]+=size[j];
            num=max(num,size[j]);
        }
    }
    num=max(ff-size[x],num);
    if(num<mx)
    {
        root=x;
        mx=num;
    } 
}
int sodis(int x,int fa,int val)
{
    d[++tot]=val;
    for(int i=last[x];i;i=next[i])
    {
        int j=to[i];
        if(j!=fa && bz[j])
        {
            sodis(j,x,val+v[i]);
        }
    }
}
int rf(int l,int r,int val)
{
    while(l<r)
    {
        int mid=(l+r)/2;
        if(d[mid]+val<s)
            l=mid+1;
        else
            r=mid;
    }
    if(d[l]+val>=s)
        ans=min(d[l]+val,ans);
    else
    if(d[r]+val>=s)
        ans=min(d[r]+val,ans);
}
int dg(int x,int fa)
{
    bz[x]=false;
    tot=1;
    d[1]=0;
    for(int i=last[x];i;i=next[i])
    {
        int j=to[i];
        if(j!=fa && bz[j])
        {
            int k=tot+1;
            sodis(j,x,v[i]);
            for(int l=k;l<=tot;l++)
            {
                rf(1,k-1,d[l]);
            }
            sort(d+1,d+1+tot);
        }
    }
    int f=tot;
    for(int i=last[x];i;i=next[i])
    {
        int j=to[i];
        if(j!=fa && bz[j])
        {
            ff=f-1;
            root=0;
            mx=maxlongint;
            findroot(j,x);
            dg(root,x);
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<=n-1;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        bj(x,y,z);
        bj(y,x,z);
    }
    memset(bz,true,sizeof(bz));
    root=0;
    ff=n;
    mx=maxlongint;
    findroot(1,0);
    dg(root,0);
    if(ans>e)
        printf("-1\n");
    else
        printf("%d\n",ans);
}