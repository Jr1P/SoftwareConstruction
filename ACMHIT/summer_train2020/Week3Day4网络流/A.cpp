#include <cstdio>
const int N = 100;
const int M = 3000;
const int INF = __INT_MAX__;

struct Edge {
    int v, nxt, w;
} e[M];

int n, m, cnt = -1, s, t;
int head[N], q[N], dep[N], cur[N];

inline int min(int x, int y) { return x < y ? x : y; }
void add(int u, int v, int w) {
    e[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

bool bfs(int s, int t) {
    for(int i = 1; i <= n; i++) cur[i] = head[i], dep[i] = -1;
    int hd = 0, tp = 0;
    q[tp++] = s; dep[s] = 0;
    while(hd != tp) {
        int u = q[hd++];
        for(int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if(dep[v] == -1 && e[i].w) dep[q[tp++] = v] = dep[u]+1;
        }
    }
    return dep[t] != -1;
}

int dfs(int u, int flow) {
    if(u == t) return flow;
    int rem = flow;
    for(int &i = cur[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(e[i].w && dep[v] == dep[u]+1) {
            int c = dfs(v, min(rem, e[i].w));
            rem -= c;
            e[i].w -= c; e[i^1].w += c;
            if(!rem) break;
        }
    }
    if(rem == flow) dep[u] = -1;
    return flow-rem;
}

int Dinic() {
    int maxflow = 0;
    while(bfs(s, t)) maxflow += dfs(s, INF);
    return maxflow;
}

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        cnt = -1;
        for(int i = 1; i <= n; i++) head[i] = -1;
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w); add(v, u, 0);
        }
        s = 1, t = n;
        printf("Case %d: %d\n", ++kase, Dinic());
    }
    return 0;
}