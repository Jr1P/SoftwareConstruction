#include <cstdio>
const int N = 5e4+5;

int n, maxid, tim;
int low[N], dfn[N];
bool iscut[N];

struct Edge {
    int v, nxt;
}e[N<<1];

void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

inline int max(int x, int y) { return x > y ? x : y; }

void Tarjan(int u, int fa) {
    low[u] = dfn[u] = ++tim;
    int sz = g[u].size(), child = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].nxt;
        if(!dfn[v]) {
            Tarjan(v, fa);
            low[u] = min(low[v], low[u]);
            if(low[v] >= dfn[u] && u != fa) iscut[u] = true;
            if(u == fa) child++;
        } else low[u] = min(low[u], dfn[v]);
    }
    if(fa == u && child >= 2) iscut[u] = true;
}

int main() {
    while(~scanf("%d", &n)) {
        maxid = tim = cnt = 0;
        for(int i = 1; i <= n; i++) {
            head[i] = 0; low[i] = dfn[i] = 0;
            iscut[i] = false;
        }
        for(int i = 1; i <= n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            maxid = max(maxid, max(u, v));
            add(u, v); add(v, u);
        }
        for(int i = 1; i <= n; i++)
    }
    return 0;
}