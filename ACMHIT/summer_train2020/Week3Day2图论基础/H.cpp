#include <cstdio>
#include <algorithm>
const int N = 5e4+5;
const int M = 1e5+5;

int n, m, cnt, fa[N];
int head[N], anc[N][21], dep[N], maxw[N][21];
bool vis[N];

struct Edge {
    int u, v, w;
    bool operator < (const Edge o) const {
        return w < o.w;
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
            maxw[v][0] = e[i].w;
            anc[v][0] = u;
            dfs(v);
        }
    }
}

int LCA(int u, int v) {
    int ans = 0;
    if(find(u) != find(v)) return -1;
    if(dep[u] < dep[v]) std::swap(u, v);
    for(int det = dep[u]-dep[v], i = 0; det; det >>= 1, i++) {
        if(det & 1) {
            ans = std::max(ans, maxw[u][i]);
            u = anc[u][i];
        }
    }
    if(u == v) return ans;
    for(int i = 20; i >= 0; i--)
        if(anc[u][i] != anc[v][i]) {
            ans = std::max(ans, maxw[u][i]);
            ans = std::max(ans, maxw[v][i]);
            u = anc[u][i];
            v = anc[v][i];
        }
    ans = std::max(ans, maxw[u][0]);
    ans = std::max(ans, maxw[v][0]);
    return ans;
}

int main() {
    bool f = true;
    while(~scanf("%d%d", &n, &m)) {
        if(!f) puts("");
        f = false; 
        cnt = 0;
        for(int i = 1; i <= n; i++) fa[i] = i, head[i] = -1, vis[i] = false;
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
                anc[i][0] = i; dep[i] = 0; maxw[i][0] = 0;
                dfs(i);
            }
        for(int i = 1; i <= 20; i++) {
            for(int u = 1; u <= n; u++) {
                anc[u][i] = anc[anc[u][i-1]][i-1];
                maxw[u][i] = std::max(maxw[u][i-1], maxw[anc[u][i-1]][i-1]);
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
    }
    return 0;
}