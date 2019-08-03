#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define inf 0x7f7f7f7f
using namespace std;
const int N=5e5+5;
int n,m;
int cov[N],f[N];
int l[N],r[N];
int a[N];
int q[N];
int main()
{
    scanf("%d%d",&n,&m);
    fo(i,1,n+1)r[i]=i-1; 
    fo(i,1,m)
    {
        int l1,r1;
        scanf("%d%d",&l1,&r1);
        r[r1]=min(r[r1],l1-1);
        l[r1+1]=max(l[r1+1],l1);
        //q[i].l=l,q[i].r=r;
    }
    fd(i,n,1)r[i]=min(r[i+1],r[i]);
    fo(i,2,n+1)l[i]=max(l[i],l[i-1]);
    int j=1;
    int t=1,w=1;
    q[1]=0;
    fo(i,1,n+1)
    {
        while (j<=r[i]&&j<=n)
        {
            if (f[j]==-1)
            {
                j++;
                continue;
            }
            while (f[j]>f[q[w]]&&t<=w)w--;
            q[++w]=j;
            j++;
        }
        while (q[t]<l[i]&&t<=w)t++;
        if (t<=w)f[i]=f[q[t]]+(i!=n+1?1:0);
        else f[i]=-1; 
    }
    printf("%d\n",f[n+1]);
}