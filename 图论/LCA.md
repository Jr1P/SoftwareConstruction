# LCA板子

## 倍增

```cpp
#include <cstdio>
#define N 500050

struct Edge {
    int v, next;
}e[N<<1];

int fa[N][21], depth[N], head[N];
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
    for(int i = 1; i <= n; i++)
        head[i] = -1;
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
    for(int det = depth[u]-depth[v], i = 0; det; det >>= 1, i++)
        if(det&1) u = fa[u][i];
    if(u == v) return u;
    for(int i = 20; i >= 0; i--)
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    return fa[u][0];
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    init();
    for(int i = 1; i < n; i++) {
        int u, v;
        u = read(); v = read();
        add(u, v); add(v, u);
    }
    fa[s][0] = s;
    depth[s] = 0;
    dfs(s);
    for(int i = 1; i <= m; i++) {
        int u, v;
        u = read(); v = read();
        printf("%d\n", LCA(u, v));
    }
    return 0;
}
```

## Tarjan

```cpp
#include <cstdio>
using namespace std;
#define N 500050

struct Edge {
    int v, next;
}e[N<<1];

struct Query {
    int id, p, next;
}query[N<<1];

int qhead[N], head[N], fa[N], ans[N];
int n, m, s, a, b, cnt, cnt2;
bool vis[N], arr[N];

inline int read() {
    int x = 0;
    char c = getchar();
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9') {
        x = (x<<3)+(x<<1)+(c^48);
        c = getchar();
    }
    return x;
}

inline void init() {
    for(int i = 1; i <= n; i++) {
        head[i] = qhead[i] = -1;
        fa[i] = i;
        vis[i] = arr[i] = false;
        ans[i] = 0;
    }
}

inline void add(int u, int v) {
    e[++cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

inline void addq(int u, int v) {
    query[++cnt2].p = v;
    query[cnt2].next = qhead[u];
    qhead[u] = cnt2;
}

inline int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void _union(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if(f1 == f2)
        return ;
    fa[f2] = f1;
}

void tarjan(int u) {
    arr[u] = true;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(!vis[v] && !arr[v]) {
            tarjan(v);
            _union(u, v);
            vis[v] = true;
        }
    }
    vis[u] = true;
    for(int i = qhead[u]; i != -1; i = query[i].next) {
        int v = query[i].p;
        if(vis[v]) 
            ans[query[i].id] = find(v);
    }
}

int main() {
    n = read(); m = read(); s = read();
    init();
    for(int i = 1; i < n; i++) {
        int u, v;
        u = read(); v = read();
        add(u, v);
        add(v, u);
    }
    for(int i = 1; i <= m; i++) {
        int a, b;
        a = read(); b = read();
        addq(a, b);
        query[cnt2].id = i;
        addq(b, a);
        query[cnt2].id = i;
    }
    tarjan(s);
    for(int i = 1; i <= m; i++)
        printf("%d\n", ans[i]);
    return 0;
}
```

## 树链剖分

