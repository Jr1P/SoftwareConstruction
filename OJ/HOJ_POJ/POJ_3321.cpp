#include <cstdio>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 1e5 + 5;

struct Edge {
    int v, nxt;
}e[N << 1];

int n, m, cnt, len, x, y, val;
int head[N], left[N], right[N], dfn[N], num[N], tree[N];
bool vis[N];

void init() {
    for(int i = 1; i <= n; i++)
        head[i] = -1, num[i] = 1, vis[i] = false, tree[i] = 0;
    len = cnt = 0;
}

inline void add(int u, int v) {
    e[cnt] = Edge{v, head[u]};
    head[u] = cnt++;
}

void dfs(int u) {
    vis[u] = true;
    dfn[++len] = u;
    left[u] = len;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!vis[v]) dfs(v);
    }
    right[u] = len;
}

inline int lowbit(int k) { return k & (-k); }

inline void addnum(int x, int val) {
    for(int i = x; i <= n; i += lowbit(i))
        tree[i] += val;
}

inline int query(int x) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i))
        ans += tree[i];
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
        for(int i = 1; i <= n; i++) addnum(dfn[i], 1);
        scanf("%d", &m);
        while(m--) {
            char type; int u;
            getchar();
            scanf("%c%d", &type, &u);
            x = left[u], y = right[u];
            if(type == 'Q')
                printf("%d\n", query(y) - query(x - 1));
            else {
                if(num[u]) val = -1;
                else val = 1;
                addnum(x, val);
                num[u] ^= 1;
            }
        }
    }
    return 0;
}