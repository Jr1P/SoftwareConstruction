#include <cstdio>
#include <algorithm>
const int N = 1e4+5;
const int M = 5e4+5;

int n, m, cnt, fa[N];
int head[N], anc[N][18], dep[N], minw[N][18];
bool vis[N];

struct Edge {
    int u, v, w;
    bool operator < (const Edge o) const {
        return w > o.w;
    }
}E[M << 1];

struct EE {
    int v, next, w;
}e[M];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void add(int u, int v, int w) {
    e[++cnt] = EE{v, head[u], w};
    head[u] = cnt;
}

bool _unino(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return false;
    if(fx < fy) fa[fy] = fx;
    else if(fx > fy) fa[fx] = fy;
    return true;
}

void dfs(int u) {
    vis[u] = 1;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(!vis[v]) {
            dep[v] = dep[u]+1;
            minw[v][0] = e[i].w;
            anc[v][0] = u;
            dfs(v);
        }
    }
}

int LCA(int u, int v) {
    int ans = __INT_MAX__;
    if(find(u) != find(v)) return -1;
    if(dep[u] < dep[v]) std::swap(u, v);
    for(int det = dep[u]-dep[v], i = 0; det; det >>= 1, i++) {
        if(det & 1) {
            ans = std::min(ans, minw[u][i]);
            u = anc[u][i];
        }
    }
    if(u == v) return ans;
    for(int i = 17; i >= 0; i--)
        if(anc[u][i] != anc[v][i]) {
            ans = std::min(ans, minw[u][i]);
            ans = std::min(ans, minw[v][i]);
            u = anc[u][i];
            v = anc[v][i];
        }
    ans = std::min(ans, minw[u][0]);
    ans = std::min(ans, minw[v][0]);
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) fa[i] = i, head[i] = -1;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        E[i] = (Edge){u, v, w};
    }
    std::sort(E+1, E+m+1);
    for(int i = 1; i <= m; i++)
        if(_unino(E[i].u, E[i].v))
            add(E[i].u, E[i].v, E[i].w),
            add(E[i].v, E[i].u, E[i].w);
    for(int i = 1; i <= n; i++)
        if(!vis[i]) {
            anc[i][0] = i; dep[i] = 0; minw[i][0] = __INT_MAX__;
            dfs(i);
        }
    for(int i = 1; i <= 17; i++) {
        for(int u = 1; u <= n; u++) {
            anc[u][i] = anc[anc[u][i-1]][i-1];
            minw[u][i] = std::min(minw[u][i-1], minw[anc[u][i-1]][i-1]);
        }
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int a = LCA(x, y);
        printf("%d\n", a);
    }
    return 0;
}