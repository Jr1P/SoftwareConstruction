#include <cstdio>
#define rep(i, a, n) for(int i = a; i <= n; i++)
const int N = 1e5 + 5;

struct Edge {
    int v, nxt;
}e[N << 1];

int n, cnt, len;
int head[N], dfn[N], left[N], right[N], val[N];
bool vis[N];

void init() {
    rep(i, 1, n)
        head[i] = -1, vis[i] = false;
    cnt = len = 0;
}

inline void add(int u, int v) {
    e[cnt] = Edge{v, head[u]};
    head[u] = cnt++;
}

inline int gcd(int a, int b) {
    return b == 0 ? b : gcd(b, a % b);
}

void dfs(int u) {
    vis[u] = true;
    dfn[++len] = u;
    left[u] = len;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!vis[v])
            dfs(v);
    }
    right[u] = len;
}

int main() {
    while(~scanf("%d", &n)) {
        rep(i, 1, n - 1) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        rep(i, 1, n) scanf("%d", &val[i]);
        dfs(1);
    }
    return 0;
}