#include <cstdio>
const int N = 2000;
const int M = 3e5+5;
const int INF = __INT_MAX__;

struct Edge {
    int v, nxt, w;
} e[M];

int n, m, cnt = -1, s, t;
int head[N], q[N], dep[N], cur[N];
bool usf[N];

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

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while(T--) {
        int sum = 0;
        scanf("%d%d", &n, &m);
        s = 0, t = n+501; cnt = -1;
        for(int i = 0; i <= t; i++) head[i] = -1, usf[i] = false;
        for(int i = 1; i <= n; i++) {
            int p, be, end;
            scanf("%d%d%d", &p, &be, &end);
            add(s, i, p); add(i, s, 0);
            sum += p;
            for(int j = be; j <= end; j++) {
                usf[j+n] = true;   
                add(i, n+j, 1); add(n+j, i, 0);
            }
        }
        for(int i = n+1; i <= n+500; i++)
            if(usf[i]) add(i, t, m), add(t, i, 0);
        bool f = Dinic() == sum;
        printf("Case %d: %s\n\n", ++kase, f ? "Yes" : "No");
    }
    return 0;
}