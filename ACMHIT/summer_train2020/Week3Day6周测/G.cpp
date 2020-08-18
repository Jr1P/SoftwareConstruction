#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 205;

struct Edge {
    int u, v, w, nxt;
}e[N];

int n, cnt = -1, mark = -1;
int deg[10], head[10], sum[10], color[10], oddDeg[10];

void init() {
    memset(color, 0, sizeof(color));
    memset(sum, 0, sizeof(sum));
    memset(oddDeg, 0, sizeof(oddDeg));
}

void add(int u, int v, int w) {
    e[++cnt] = (Edge){u, v, w, head[u]};
    head[u] = cnt;
}

void dfs(int u, int col) {
    color[u] = col;
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!color[v] && i != mark && i != (mark^1)) dfs(v, col);
    }
}

int work() {
    init();
    for(int i = 1; i <= 4; i++)
        if(!color[i]) dfs(i, i);
    for(int i = 1; i <= 4; i++)
        if(deg[i] & 1) oddDeg[color[i]]++;
    for(int i = 0; i <= cnt; i += 2) {
        if(i == mark) continue;
        int u = e[i].u, v = e[i].v;
        sum[color[u]] += e[i].w;
    }
    int ans = 0;
    for(int i = 1; i <= 4; i++)
        ans = std::max(ans, sum[i]);
    return ans;
}

int main() {
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &w, &v);
        add(u, v, w); add(v, u, w);
        deg[u]++, deg[v]++;
    }
    int ans = work();
    bool f = true;
    for(int i = 1; i <= 4; i++) 
        if(oddDeg[i] > 2) f = false;
    if(f) {
        printf("%d\n", ans);
        return 0;
    }
    ans = 0;
    for(int i = 0; i <= cnt; i += 2) {
        int u = e[i].u, v = e[i].v;
        if(u == v) continue;
        mark = i;
        deg[u]--, deg[v]--;
        ans = std::max(ans, work());
        deg[u]++, deg[v]++;
    }
    printf("%d\n", ans);
    return 0;
}