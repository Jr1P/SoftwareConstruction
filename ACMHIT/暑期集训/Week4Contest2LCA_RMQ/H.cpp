#include <cstdio>
#define N 100050

struct Edge {
    int v, next;
}e[N<<1];

int fa[N][20], head[N], depth[N];
int n, q, cnt, s, t, f;

inline void init() {
    for(int i = 1; i <= n; i++) {
        head[i] = -1;
        depth[i] = 0;
    }
}

inline int max(int x, int y) {
    return x > y ? x : y;
}

inline void _swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

inline void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int u) {
    for(int i = 1; i < 20; i++)
        fa[u][i] = fa[fa[u][i-1]][i-1];
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != fa[u][0]) {
            fa[v][0] = u;
            depth[v] = depth[u]+1;
            dfs(v);
        }
    }
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) _swap(u, v);
    for(int det = depth[u]-depth[v], i = 0; det; i++, det >>= 1)
        if(det&1) u = fa[u][i];
    if(u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int dis(int u, int v) {
    int anc = LCA(u, v);
    return depth[u]+depth[v]-2*depth[anc];
}

int work(int a, int b, int c) {
    return (a+b-c)/2+1;
}

int main() {
    scanf("%d%d", &n, &q);
    init();
    for(int i = 2; i <= n; i++) {
        int v;
        scanf("%d", &v);
        add(i, v);
        add(v, i);
    }
    fa[1][0] = 1;
    depth[1] = 0;
    dfs(1);
    while(q--) {
        int ans = 0;
        scanf("%d%d%d", &s, &t, &f);
        int lst = dis(s, t), lsf = dis(s, f), ltf = dis(t, f);
        ans = max(ans, work(lst, lsf, ltf));
        ans = max(ans, work(lst, ltf, lsf));
        ans = max(ans, work(lsf, ltf, lst));
        printf("%d\n", ans);
    }
    return 0;
}