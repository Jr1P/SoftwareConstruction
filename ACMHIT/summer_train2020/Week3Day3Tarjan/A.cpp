#include <cstdio>
const int N = 1050;

struct Edge {
    int v, nxt;
} e[N<<1];

int n, m, cnt, tim, sum, top;
int head[N], sta[N], dfn[N], low[N], color[N], du[N];
bool insta[N];

inline int min(int x, int y) { return x < y ? x : y; }

void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    insta[u] = true;
    sta[++top] = u;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if(insta[v]) low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        color[u] = ++sum;
        insta[u] = false;
        while(sta[top] != u) {
            color[sta[top]] = sum;
            insta[sta[top--]] = false;
        }
        top--;
    }
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; i++) {
            head[i] = 0;
            insta[i] = false;
            dfn[i] = low[i] = 0;
            color[i] = du[i] = 0;
        }
        sum = top = cnt = tim = 0;
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v); add(v, u);
        }
        for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
        for(int i = 1; i <= n; i++)
            for(int j = head[i]; j; j = e[j].nxt) {
                int v = e[j].v;
                if(color[v] != color[i])
                    du[color[i]]++;
            }
        int ans = 0;
        for(int i = 1; i <= sum; i++)
            if(du[i] == 1) ans++;
        printf("%d\n", (ans+1)/2);
    }
    return 0;
}