#include <cstdio>
#include <algorithm>
using namespace std;
#define N 15050
#define M 30050

struct Edge {
    int u, v, w;
}e[M<<1];

struct EDGE {
    int v, next, w;
}edge[N<<1];

int n, m, k, cnt, ecnt;
int father[N], head[N], depth[N], fa[N][21], ma[N][21];
bool vis[N];

inline void _swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

inline void add(int u, int v, int w) {
    edge[++ecnt].v = v;
    edge[ecnt].w = w;
    edge[ecnt].next = head[u];
    head[u] = ecnt;
}

inline int find(int x) {
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

inline bool _union(int x, int y) {
    int f1 = find(x), f2 = find(y);
    if(f1 == f2) return false;
    if(f1 > f2)
        father[f1] = f2;
    else father[f2] = f1;
    return true;
}

inline bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

inline int max(int x, int y) {
    return x>y?x:y;
}

void dfs(int u) {
    for(int i = 1; i <= 20; i++) {
        fa[u][i] = fa[fa[u][i-1]][i-1];
        ma[u][i] = max(ma[u][i-1], ma[fa[u][i-1]][i-1]);
    }
    for(int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if(v != fa[u][0]) {
            fa[v][0] = u;
            depth[v] = depth[u]+1;
            ma[v][0] = edge[i].w;
            dfs(v);
        }
    }
}

int LCA(int u, int v) {
    int ans = 0;
    if(depth[u] < depth[v]) _swap(u, v);
    for(int det = depth[u]-depth[v], i = 0; det; det >>= 1, i++) {
        if(det&1) {
            ans = max(ans, ma[u][i]);
            u = fa[u][i];
        }
    }
    if(u == v) return ans;
    for(int i = 20; i >= 0; i--)
        if(fa[u][i] != fa[v][i]) {
            ans = max(ans, ma[u][i]);
            u = fa[u][i];
            ans = max(ans, ma[v][i]);
            v = fa[v][i];
        }
    ans = max(ans, ma[u][0]);
    ans = max(ans, ma[v][0]);
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int u, v, w;
    for(int i = 1; i <= n; i++) {
        father[i] = i;
        head[i] = -1;
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        e[++cnt].u = u; e[cnt].v = v; e[cnt].w = w;
    }
    sort(e+1, e+1+cnt, cmp);
    for(int i = 1; i <= cnt; i++) {
        if(_union(e[i].v, e[i].u)) {
            add(e[i].u, e[i].v, e[i].w);
            add(e[i].v, e[i].u, e[i].w);
        }
    }
    fa[1][0] = 1;
    depth[1] = 0;
    dfs(1);
    while(k--) {
        scanf("%d%d", &u, &v);
        printf("%d\n", LCA(u, v));
    }
    return 0;
}