#include<bits/stdc++.h>
#define N 200005
using namespace std;
int last[N*10],b[N*10],a[N*10],st[N*10],f[N*10],maxn[N][30];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        st[i]=max(st[i-1],last[a[i]+1000000]+1);
        f[i]=i-st[i]+1;
        maxn[i][0]=f[i];
        last[a[i]+1000000]=i;
    }
    for(int j=1;j<20;j++)
        for(int i=1;i<=n+1-(1<<j);i++)
            maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x++,y++;
        int l=x,r=y;
        while(x<y)
        {
            int mid=(x+y)>>1;
            if(st[mid]<l)x=mid+1;else y=mid;
        }
        if(st[x]<l)x=x+1;
        int nmax=0;
        if(x<=r)
        {
            int k=log2(double(r-x+1));
            nmax=max(maxn[x][k],maxn[r-(1<<k)+1][k]);
        }
        printf("%d\n",max(nmax,x-l));
    }
    return 0;
}