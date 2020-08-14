#include <cstdio>
typedef long long ll;
const int INF = 0x7fffffff;
const int mod = 1e9+7;
const int N = 1e5+500;
const int M = 3e5+5;

struct Edge {
    int v, nxt;
}e[M<<1];

int n, m, tim, sum, top, cnt;
int low[N], dfn[N], sta[N], color[N], head[N], mc[N], f[N], cost[N];
bool insta[N];

inline int min(int x, int y) { return x < y ? x : y; }

void init() {
    for(int i = 1; i <= n; i++)
        head[i] = 0, low[i] = dfn[i] = 0, insta[i] = false, color[i] = 0;
    cnt = tim = sum = top = 0;
}

void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    insta[u] = true;
    sta[++top] = u;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(insta[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        // color[u] = ++sum;
        mc[++sum] = cost[u]; f[sum] = 1;
        insta[u] = false;
        while(sta[top] != u) {
            if(cost[sta[top]] < mc[sum]) {
                mc[sum] = cost[sta[top]];
                f[sum] = 1;
            } else if(cost[sta[top]] == mc[sum]) f[sum]++;
            // color[sta[top]] = sum;
            insta[sta[top--]] = false;
        }
        top--;
    }
}

int main() {
    while(~scanf("%d", &n)) {
        init();
        for(int i = 1; i <= n; i++) scanf("%d", &cost[i]);
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
        ll C = 0, ans = 1;
        for(int i = 1; i <= sum; i++)
            C += mc[i], ans = (ans * f[i]) % mod;
        printf("%lld %lld\n", C, ans);
    }
    return 0;
}