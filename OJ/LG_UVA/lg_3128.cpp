#include <cstdio>
#include <iostream>
#define N 50005
#define DEPTH 18

struct Edge {
    int v, next;
}e[N << 1];

int fa[N][21], depth[N], head[N], diff[N];
int n, m, cnt, ans;

inline int read() {
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x;
}

void init() {
    for(int i = 1; i <= n; i++)
        head[i] = -1;
}

inline void add(int u, int v) {
    e[++cnt] = Edge{v, head[u]};
    head[u] = cnt;
}

void dfs(int u) {
    for(int i = 1; i <= DEPTH; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(fa[u][0] != v) {
            fa[v][0] = u;
            depth[v] = depth[u] + 1;
            dfs(v);
        }
    }
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) std::swap(u, v);
    for(int det = depth[u] - depth[v], i = 0; det; det >>= 1, i++)
        if(det & 1) u = fa[u][i];
    if(u == v) return u;
    for(int i = DEPTH; i >= 0; i--)
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

void dfs2(int u) {
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa[u][0]) continue;
        dfs2(v);
        diff[u] += diff[v];
    }
    ans = std::max(ans, diff[u]);
}

int main() {
    scanf("%d%d", &n, &m); init();
    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        add(u, v); add(v, u);
    }
    depth[fa[1][0] = 1] = 0;
    dfs(1);
    for(int i = 1; i <= m; i++) {
        int u, v, anc;
        u = read(); v = read();
        diff[u]++; diff[v]++;
        diff[anc = LCA(u, v)]--; diff[fa[anc][0]]--;
    }
    dfs2(1);
    printf("%d\n", ans);
    return 0;
}