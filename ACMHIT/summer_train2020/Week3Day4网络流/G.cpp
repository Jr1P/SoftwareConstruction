#include <cstdio>
#include <cstring>
const int N = 3000;
const int M = 4e5+5;
const int INF = 0x3f3f3f3f;

struct Edge {
    int v, nxt, w;
} e[M];

int n, m, cnt = -1, s, t;
int head[N], q[N], dep[N], cur[N];

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }
void add(int u, int v, int w) {
    e[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

bool bfs(int s, int t) {
    for(int i = 0; i <= t; i++) cur[i] = head[i], dep[i] = -1;
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

int f[N], a[N];

int main() {
    while(~scanf("%d", &n)) {
        int ans = 0; cnt = -1;
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= n; i++) scanf("%d", a+i);
        f[1] = 1;
        for(int i = 2; i <= n; i++) {
            f[i] = 1;
            for(int j = 1; j < i; j++)
                if(a[i] > a[j] && f[i] < f[j]+1)
                    f[i] = f[j]+1;
            ans = max(ans, f[i]);
        }
        s = 0, t = n+1;
        for(int i = 1; i <= n; i++) {
            if(f[i] == 1) add(s, i, 1), add(i, s, 0);
            if(f[i] == ans) {
                add(i, t, 1), add(t, i, 0);
                continue;
            }
            for(int j = i+1; j <= n; j++)
                if(f[j] == f[i]+1) add(i, j, 1), add(j, i, 0);
        }
        printf("%d\n%d\n", ans, Dinic());
    }
    return 0;
}