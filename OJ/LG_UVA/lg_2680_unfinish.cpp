#include <cstdio>
#include <iostream>
const int N = 3e5 + 5;
const int DEPTH = 20;

struct Edge {
    int v, nxt;
}e[N << 1];

int n, m, cnt;
int diff[N], depth[N], head[N], fa[N][21], weight[N];

inline void add(int u, int v) {
    e[++cnt] = Edge{v, head[u]};
    head[u] = cnt;
}

void dfs1(int u) {
    for(int i = 1; i <= DEPTH; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[u][0]) continue;
        depth[v] = depth[u] + 1;
        fa[v][0] = u;
        dfs1(v);
    }
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) std::swap(u, v);
    for(int d = depth[u] - depth[v], i = 0; d; d >>= 1, i++)
        if(d & 1) u = fa[u][i];
    for(int i = DEPTH; i >= 0; i++)
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

void dfs2(int u) {
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[u][0]) continue;
        dfs2(v);
        diff[u] += diff[v];
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        scanf("%d", weight + v);
        add(u ,v); add(v, u);
    }
    dfs1(1);
    while(m--) {
        scanf("%d");
    }
    return 0;
}