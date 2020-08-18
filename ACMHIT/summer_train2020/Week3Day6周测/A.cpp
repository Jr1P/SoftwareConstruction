#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 5050;

struct Edge {
    int u, v, nxt;
}e[N*N];

int n, m, cnt, tim, top, sum;
int head[N], dfn[N], low[N], color[N], sta[N], chudu[N], size[N], chu[N];
bool insta[N];

inline int min(int x, int y) { return x < y ? x : y; }

void add(int u, int v) {
    e[++cnt] = (Edge){u, v, head[u]};
    head[u] = cnt;
}

void init() {
    for(int i = 1; i <= n; i++) {
        head[i] = -1;
        insta[i] = false;
        dfn[i] = low[i] = color[i] = size[i] = chudu[i] = chu[i] = 0;
    }
    sum = cnt = tim = top = 0;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    insta[u] = true;
    sta[++top] = u;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
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
    while(~scanf("%d", &n) && n) {
        init();
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v); chudu[u]++;
        }
        for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
        for(int i = 1; i <= cnt; i++)
            if(color[e[i].u] != color[e[i].v])
                chu[color[e[i].u]]++;
        int ans[N], tot = 0;
        for(int i = 1; i <= n; i++)
            if(chu[color[i]] == 0) ans[++tot] = i;
        for(int i = 1; i < tot; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[tot]);
    }
    return 0;
}