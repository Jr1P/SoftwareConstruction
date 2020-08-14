#include <cstdio>
const int N = 2e4+500;
const int M = 1e5+5;

struct Edge {
    int v, nxt;
}e[M];

int n, m, tim, sum, top, cnt;
int low[N], dfn[N], sta[N], color[N], head[N], du[N], size[N];
bool insta[N];

inline int min(int x, int y) { return x < y ? x : y; }

void init() {
    for(int i = 1; i <= n; i++)
        head[i] = 0, low[i] = dfn[i] = 0, insta[i] = false, color[i] = du[i] = 0;
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
        color[u] = ++sum;
        size[sum] = 1;
        insta[u] = false;
        while(sta[top] != u) {
            color[sta[top]] = sum;
            insta[sta[top--]] = false;
            size[sum]++;
        }
        top--;
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        init();
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
        for(int u = 1; u <= n; u++)
            for(int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].v;
                if(color[u] != color[v]) du[color[u]]++;
            }
        int ans = 0, f = 0;
        for(int i = 1; i <= sum; i++) {
            if(!f && du[i] == 0) {
                ans = size[i];
                f = 1;
            } else if(f && du[i] == 0) {
                ans = 0;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}