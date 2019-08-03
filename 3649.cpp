#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 200000;
int head[MAXN],nxt[MAXN<<1],tim[MAXN],tot,n,m;
long long dis[MAXN];
bool vis[MAXN],flag = 0;
struct Edge
{
    int from,to,cost;
}edge[MAXN<<1];
void build(int f,int t,int d)
{
    edge[++tot].from = f;
    edge[tot].to = t;
    edge[tot].cost = d;
    nxt[tot] = head[f];
    head[f] = tot;
}
deque <int>q;
void spfa(int s)
{
    memset(dis,-1,sizeof(dis));
    dis[s] = 0;
    vis[s] = 1;tim[0]=1;
    q.push_front(s);
    while(!q.empty())
    {
        int x = q.front();
        q.pop_front();
        vis[x] = 0;
        for(int i = head[x]; i ; i = nxt[i])
        {
            Edge e = edge[i];
            if(dis[e.to] < dis[x]+e.cost)
            {
                dis[e.to] = dis[x]+e.cost;
                if(++tim[e.to] > n)
                {
                    flag = 1;
                    return ;
                }
                if(!vis[e.to])
                {
                    if(q.empty())
                    q.push_back(e.to );
                    else if(dis[q.front()] < dis[e.to])
                    q.push_front(e.to );
                    else
                    q.push_back(e.to);
                    vis[e.to] = 1;
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int t,a,b;
    for(int i = 1; i <= m; i ++)
    {
        scanf("%d%d%d",&t,&a,&b);
        if(t == 1)build(a,b,0),build(b,a,0);
        else if(t == 2)
        {
            build(a,b,1);
        }
        else if(t == 3)
        build(b,a,0);
        else if(t == 4)
        build(b,a,1);
        else if(t == 5)
        build(a,b,0);
    }
    for(int i = n; i >= 1; i --)
    build(0,i,1);
    spfa(0);
    if(flag)
    puts("-1");
    else
    {
        long long ans = 0;
        for(int i = 1; i <= n; i ++)
        ans += dis[i];
        printf("%lld\n",ans);
    }
    return 0;
}