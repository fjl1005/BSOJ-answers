#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;

#define gc getchar()

int n, m, now = 1;
struct Node {
    int u, v, w, is_in;
    bool operator <(const Node a)const {
        return w < a.w;
    }
} E[N * 3];
struct Node_2{int u, v, w, nxt;} G[(N * 3) << 1];
int fa[N][30], Max[N][30], Tmax[N][30], deep[N], head[N], father[N];
int Mi[30];

#define LL long long
LL Answer; int Min = 1e9;

inline int read() {
    int x = 0; char c = gc;
    while(c < '0' || c > '9') c = gc;
    while(c >= '0' || c >= '9') x = x * 10 + c - '0', c = gc;
    return x;
}

void Add(int u, int v, int w) {G[now].v = v; G[now].w = w; G[now].nxt = head[u]; head[u] = now ++;}
int Getfa(int x) {return father[x] == x ? x : father[x] = Getfa(father[x]);}

void Mst() {
    int js(0);
    for(int i = 1; js != n - 1; i ++) {
        int u = E[i].u, v = E[i].v, fu = Getfa(u), fv = Getfa(v);
        if(fu != fv) {
            father[fu] = fv; 
            js ++; 
            E[i].is_in = 1; 
            Answer += (LL)E[i].w;
            Add(E[i].u, E[i].v, E[i].w);
            Add(E[i].v, E[i].u, E[i].w);
        }
    }
}

void Dfs(int x, int f_, int dep) {
    deep[x] = dep;
    for(int i = 1; ; i ++) {
        if(deep[x] - Mi[i] < 0) break;
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
        Max[x][i] = max(Max[x][i - 1], Max[fa[x][i - 1]][i - 1]);
        if(Max[x][i - 1] == Max[fa[x][i - 1]][i - 1]) 
            Tmax[x][i] = max(Tmax[x][i - 1], Tmax[fa[x][i - 1]][i - 1]);
        else
            Tmax[x][i] = max(min(Max[x][i - 1], Max[fa[x][i - 1]][i - 1]), 
                         max(Tmax[x][i - 1], Tmax[fa[x][i - 1]][i - 1]));
    }
    for(int i = head[x]; ~ i; i = G[i].nxt) {
        int v = G[i].v;
        if(v != f_) {fa[v][0] = x; Max[v][0] = G[i].w; Tmax[v][0] = -1; Dfs(v, x, dep + 1);}
    }
}

int Lca(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    int k = deep[x] - deep[y];
    for(int i = 0; i <=  17; i ++)
        if(k >> i & 1) x = fa[x][i];
    if(x == y) return x;
    for(int i = 17; i >= 0; i --)
        if(fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

void Work(int s, int t, int w_) {
    int m1 = 0, m2 = 0, k = deep[s] - deep[t];
    for(int i = 0; i <= 17; i ++) {
        if(k >> i & 1) {
            m2 = max(m2, Tmax[s][i]);
            if(Max[s][i] > m1) {m2 = max(m2, m1); m1 = Max[s][i];}
        }
    }
    if(m1 == w_) Min = min(Min, w_ - m2);
    else Min = min(Min, w_ - m1);
}

int main() {
    n = read(); m = read();
    for(int i = 1; i <= n; i ++) head[i] = -1, father[i] = i;
    Mi[0] = 1;
    for(int i = 1; i <= 17; i ++) Mi[i] = Mi[i - 1] * 2;
    for(int i = 1; i <= m; i ++) {E[i].u = read(), E[i].v = read(), E[i].w = read();}
    sort(E + 1, E + m + 1);
    Mst();
    Dfs(1, 0, 1);
    for(int i = 1; i <= m; i ++) {
        if(!E[i].is_in) {
            int u = E[i].u, v = E[i].v;
            int L = Lca(u, v);
            Work(u, L, E[i].w);
            Work(v, L, E[i].w);
        }
    }
    cout << Answer + Min;
    return 0;
}