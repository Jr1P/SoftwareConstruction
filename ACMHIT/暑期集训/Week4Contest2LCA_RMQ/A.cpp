#include <cstdio>
#include <cstring>
#define N 20050

struct Edge {
    int v, next;
}e[N<<1];

int fa[N][21], depth[N], head[N], ru[N];
int n, m, s, cnt;

inline int read() {
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9') c = getchar();
    while(c >= '0' && c <= '9') {
        x = (x<<3)+(x<<1)+(c^48);
        c = getchar();
    }
    return x;
}

void init() {
    cnt = 0;
    for(int i = 1; i <= n; i++) {
        head[i] = -1;
        depth[i] = 0;
        ru[i] = 0;
    }
    memset(fa, 0, sizeof(fa));
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
    for(int i = 1; i <= 20; i++)
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
    for(int det = depth[u]-depth[v], i = 0; det; det >>= 1, i++) {
        if(det&1) u = fa[u][i];
    }
    if(u == v) return u;
    for(int i = 20; i >= 0; i--)
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        init();
        for(int i = 1; i < n; i++) {
            int u, v;
            u = read(); v = read();
            add(u, v);// add(v, u);
            ru[v]++;
        }
        for(int i = 1; i <= n; i++)
            if(ru[i] == 0) {
                s = i;
                break;
            }
        fa[s][0] = s;
        depth[s] = 0;
        dfs(s);
        int u, v;
        u = read(); v = read();
        printf("%d\n", LCA(u, v));
    }
    return 0;
}