#include <cstdio>
#include <iostream>
const int N = 3e5 + 5;
const int DEPTH = 19;

struct Edge {
    int v, nxt;
} e[N << 1];

int n, cnt, ans, s;
int head[N], fa[N][20], diff[N], depth[N], vis[N];

inline void add(int u, int v) {
    e[++cnt] = Edge{v, head[u]};
    head[u] = cnt;
}

void dfs1(int u) {
    for(int i = 1; i <= DEPTH; i++)
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(fa[u][0] == v) continue;
        depth[v] = depth[u] + 1;
        fa[v][0] = u;
        dfs1(v);
    }
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) std::swap(u, v);
    for(int det = depth[u] - depth[v], i = 0; det; det >>= 1, i++)
        if(det & 1) u = fa[u][i];
    if(u == v) return u;
    for(int i = DEPTH; i >= 0; i--) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void dfs2(int u) {
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(fa[u][0] == v) continue;
        dfs2(v);
        diff[u] += diff[v];
    }
}

int main() {
    scanf("%d%d", &n, &s);
    fa[s][0] = 0;
    for(int i = 1; i <= n; i++) head[i] = -1;
    for(int i = 1; i < n; i++) scanf("%d", &vis[i]);
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(s);
    int anc = LCA(s, vis[1]);
    diff[s]++, diff[vis[1]]++;
    diff[anc]--, diff[fa[anc][0]]--;
    for(int i = 1; i < n - 1; i++) {
        int u = vis[i], v = vis[i + 1];
        anc = LCA(u, v);
        if(anc == u) {
            diff[v]++, diff[u]--;
            continue;
        } else if(anc == v) {
            diff[fa[u][0]]++, diff[fa[v][0]]--;
            continue;
        }
        diff[fa[vis[i]][0]]++;
        diff[vis[i + 1]]++;
        diff[anc]--, diff[fa[anc][0]]--;
    }
    dfs2(s);
    for(int i = 1; i <= n; i++)
        if(i == vis[n - 1])
            printf("%d\n", diff[i] - 1);
        else
            printf("%d\n", diff[i]);
    return 0;
}