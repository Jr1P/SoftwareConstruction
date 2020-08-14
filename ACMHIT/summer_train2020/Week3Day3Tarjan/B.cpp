#include <cstdio>
const int N = 2e5+5;
const int M = 4e5+5;

struct Edge {
    int u, v, nxt;
    bool isBr, cuted;
} e[M<<1];

int n, m, s, t, ds, dt, sp, cnt, degs, degt, tim;
int dfn[N], low[N], head[N];

inline int min(int x, int y) { return x < y ? x : y; }

void add(int u, int v) {
    e[cnt] = (Edge){u, v, head[u], false, false};
    head[u] = cnt++;
}

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tim;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[v], low[u]);
            if((u == s && v == t) || (u == t && v == s)) sp = i;
            if(low[v] > dfn[u]) e[i].isBr = e[i^1].isBr = true;
        } else low[u] = min(low[u], dfn[v]);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) head[i] = -1;
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
        if(u == s || v == s) degs++;
        if(u == t || v == t) degt++;
    }
    // for(int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i, 0);
    scanf("%d%d%d%d", &s, &t, &ds, &dt);
    bool fs = false, ft = false;
    if(!e[sp].isBr) degs--, degt--, m--, e[sp].cuted = e[sp^1].cuted = true;
    for(int i = head[s]; i != -1; i = e[i].nxt) {
        if(degs <= ds) {
            fs = true;
            break;
        }
        if(i != sp && !e[i].isBr && m >= n-1) degs--, e[i].cuted = e[i^1].cuted = true;
    }
    if(!fs) {
        puts("No");
        return 0;
    }
    for(int i = head[t]; i != -1; i = e[i].nxt) {
        if(degt <= dt) {
            ft = true;
            break;
        }
        if(i != sp && !e[i].isBr && m >= n-1) degt--, e[i].cuted = e[i^1].cuted = true;
    }
    if(!ft) {
        puts("No");
        return 0;
    }
    for(int i = 0; i < cnt; i += 2) {
        int u = e[i].u, v = e[i].v;
    }
    // if(m != n-1)
    //     for(int i = 1; i <= n; i++)
    //         for(int j = head[i]; j != -1; j = e[j].nxt) {
    //             if(m == n-1) break;
    //             if(!e[i].isBr && !e[i].cuted) e[i].cuted = e[i^1].cuted = true, m--;
    //         }
    // if(m > n-1) {
    //     puts("No");
    //     return 0;
    // }
    // puts("Yes");
    // for(int i = 0, j = 1; i < cnt && j <= n-1; i += 2)
    //     if(!e[i].cuted) printf("%d %d\n", e[i].u, e[i].v), j++;
    return 0;
}