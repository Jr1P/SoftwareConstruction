#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 105;
const int M = 2e4;
const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, nxt, flow, cost;
} e[M];

int n, m, k, cnt, sum, s, t;
int B[N], sp[N][N], dis[N], flow[N], head[N], pre[N];
bool inq[N];

inline int min(int x, int y) { return x < y ? x : y; }

inline void add(int u, int v, int flow, int cost) {
    e[++cnt] = (Edge){u, v, head[u], flow, cost};
    head[u] = cnt;
    e[++cnt] = (Edge){v, u, head[v], 0, -cost};
    head[v] = cnt;
}

bool spfa(int s, int t) {
    mem(dis, 0x3f); mem(inq, false);
    int q[M], hd = 0, tp = 0, u;
    flow[q[tp++] = s] = INF;
    inq[s] = true;
    pre[s] = dis[s] = 0;
    while(hd != tp) {
        inq[u = q[hd++]] = false;
        for(int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if(dis[u]+e[i].cost < dis[v] && e[i].flow) {
                dis[v] = dis[u]+e[i].cost;
                pre[v] = i;
                flow[v] = min(flow[u], e[i].flow);
                if(!inq[v]) inq[q[tp++] = v] = true;
            }
        }
    }
    return dis[t] != INF;
}

bool MCMF() {
    int _flow = 0, cost = 0;
    while(spfa(s, t)) {
        _flow += flow[t];
        cost -= dis[t]*flow[t];
        int u = t;
        while(u != s) {
            e[pre[u]].flow -= flow[t];
            e[pre[u]^1].flow += flow[t];
            u = e[pre[u]].u;
        }
    }
    return n-_flow >= sum-cost;
}

int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while(T--) {
        cnt = -1; sum = 0;
        scanf("%d%d%d", &n, &m, &k);
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= m; i++) {
            scanf("%d", &B[i]);
            sum += B[i];
        }
        for(int i = 1; i <= n; i++) add(s, i, 1, 0);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                scanf("%d", &sp[i][j]);
                if(sp[i][j]) add(j, i+n, 1, 0);
            }
        s = 0, t = (n+m+1);
        for(int i = 1; i <= m; i++) {
            add(i+n, t, B[i]/k, -k);
            if(B[i]%k > 1) add(i+n, t, 1, -(B[i]%k));
        }
        if(MCMF()) printf("Case #%d: YES\n", ++kase);
        else printf("Case #%d: NO\n", ++kase);
    }

    return 0;
}