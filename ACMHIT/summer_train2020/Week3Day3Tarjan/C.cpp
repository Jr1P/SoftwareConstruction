#include <cstdio>
const int N = 1e5 + 5;

struct Edge {
    int v, nxt;
}e[N << 1];

int n, m, cnt, len;
int head[N], l[N], r[N], dfn[N], num[N], c[N];
bool vis[N];

void init() {
    for(int i = 1; i <= n; i++)
        head[i] = -1, num[i] = 1, vis[i] = false, c[i] = 0;
    len = cnt = 0;
}

inline void add(int u, int v) {
    e[cnt] = Edge{v, head[u]};
    head[u] = cnt++;
}

void dfs(int u) {
    vis[u] = true;
    dfn[++len] = u;
    l[u] = len;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!vis[v]) dfs(v);
    }
    r[u] = len;
}

inline int lowbit(int k) { return k & (-k); }

inline void modify(int x, int val) {
    for(int i = x; i <= n; i += lowbit(i))
        c[i] += val;
}

inline int sum(int x) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        dfs(1);
        for(int i = 1; i <= n; i++) modify(dfn[i], 1);
        scanf("%d", &m);
        while(m--) {
            char type;
            int u, x, y, val;
            getchar();
            scanf("%c%d", &type, &u);
            x = l[u], y = r[u];
            if(type == 'Q')
                printf("%d\n", sum(y) - sum(x - 1));
            else {
                if(num[u]) val = -1;
                else val = 1;
                modify(x, val);
                num[u] ^= 1;
            }
        }
    }
    return 0;
}