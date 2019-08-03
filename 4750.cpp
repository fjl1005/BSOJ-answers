#include<cstdio>
#include<algorithm>
#define N 605
#define M 500010
using namespace std;
int head[N],dfn[N],belong[N],low[N],scc;
int map[N][N],q[N],top,tot,n,m1,m2,id,ans;
bool vis[N];
struct edge{int next,to;}e[M];
#define add(u,v) e[++tot]=(edge){head[u],v},head[u]=tot
void tarjan(int x)
{
    low[x]=dfn[x]=++id;
    q[++top]=x;vis[x]=1;
    for(int i=head[x];i;i=e[i].next)
    if(!dfn[e[i].to])
    tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
    else if(vis[e[i].to])
    low[x]=min(low[x],dfn[e[i].to]);
    int now=0;
    if(low[x]==dfn[x])
    {
        scc++;
        while(now!=x)
        {
            now=q[top--];
            belong[now]=scc;
            vis[now]=0;
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(i!=j)map[i][j]=-1e9;
    else map[i][j]=0;
    int x,y;
    while(m1--)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
        map[x][y]=max(map[x][y],1);
        map[y][x]=max(map[y][x],-1);
    }
    while(m2--)
    {
        scanf("%d%d",&x,&y);
        add(x,y);
        map[x][y]=max(map[x][y],0);
    }
    for(int i=1;i<=n;i++)
    if(!dfn[i])tarjan(i);
    for(int p=1;p<=scc;p++)
    {
        for(int k=1;k<=n;k++)if(belong[k]==p)
        for(int i=1;i<=n;i++)if(belong[i]==p)
        if(map[i][k]!=-1e9)
        for(int j=1;j<=n;j++)if(belong[j]==p)
        if(map[k][j]!=-1e9)
        map[i][j]=max(map[i][j],map[i][k]+map[k][j]);
        int now=0;
        for(int i=1;i<=n;i++)if(belong[i]==p)
        for(int j=1;j<=n;j++)if(belong[j]==p)
        now=max(now,abs(map[i][j]));
        ans+=now+1;
    }
    for(int i=1;i<=n;i++)
    if(map[i][i]!=0)
    return puts("NIE"),0;
    printf("%d",ans);
}