#include <cstdio>
const int N = 1000;
const int M = 40000;
const int INF = __INT_MAX__;

struct Edge {
    int u, v, nxt, cost, flow;
}e[M];


int dis[N], head[N], pre[N], flow[N], q[M];
bool inq[N];

int n, m, cnt = -1, s, t, K;

inline int min(int x, int y) { return x < y ? x : y; }

inline void add(int u, int v, int cost, int cap) {
    e[++cnt] = (Edge){u, v, head[u], cost, cap};
    head[u] = cnt;
}

bool spfa(int s, int t) {
    int hd = 0, tp = 0, u;
    for(int i = 0; i <= t; i++) dis[i] = INF, inq[i] = false;
    flow[q[tp++] = s] = INF;
    pre[s] = dis[s] = 0;
    inq[s] = true;
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

int MCMF() {
    int _flow = 0, cost = 0;
    while(spfa(s, t)) {
        _flow += flow[t];
        cost += dis[t]*flow[t];
        int u = t;
        while(u != s) {
            e[pre[u]].flow -= flow[t];
            e[pre[u]^1].flow += flow[t];
            u = e[pre[u]].u;
        }
    }
    if(_flow != K) return -1;
    return cost;
}

int main() {
    while(~scanf("%d%d%d", &n, &m, &K)) {
        cnt = -1;
        for(int i = 0; i <= n; i++) head[i] = -1;
        for(int i = 1; i <= m; i++) {
            int u, v, a, c;
            scanf("%d%d%d%d", &u, &v, &a, &c);
            for(int j = 1; j <= c; j++)
                add(u, v, (2*j-1)*a, 1), add(v, u, -(2*j-1)*a, 0);
        }
        s = 0, t = n;
        add(s, 1, 0, K); add(1, s, 0, 0);
        int ans = MCMF();
        printf("%d\n", ans);
    }
    return 0;
}