//2018年4月30日12:20:22
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 100001;
const int M = 500001; 

const int INF = 1e9+7; 

int n, m;
int w[N];

int fir[N], nxt[M], to[M], edge_num;
void addEdge(int x, int y){
    to[++edge_num] = y;
    nxt[edge_num] = fir[x];
    fir[x] = edge_num;
}

int f[N], mi[N];

void dfs(int x, int minx, int pre){
    int flag = 1;
    minx = min(w[x], minx);
    if(mi[x] > minx) mi[x] = minx, flag = 0;
    int maxx = max(f[pre], w[x]-minx);
    if(f[x] < maxx) f[x] = maxx, flag = 0;
    if(flag) return;
    for(int i=fir[x]; i; i=nxt[i]) dfs(to[i], minx, x);
}

int main(){
    scanf("%d%d", &n, &m); 
    for(int i=1; i<=n; i++)
        scanf("%d", &w[i]);
    for(int i=1; i<=N; i++)
        mi[i] = INF;
    for(int i=1; i<=m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if(z == 1){
            addEdge(x, y); 
        }else if(z == 2){
            addEdge(x, y); addEdge(y, x);
        }
    }
    
    dfs(1, INF, 0);
    
    printf("%d\n", f[n]);

    return 0;
}