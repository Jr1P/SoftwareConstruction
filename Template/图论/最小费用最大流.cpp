// AC
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#define N 5050
#define M 50050
#define INF 0x3fffffff

struct Edge {
    int u, v, next, flow, cost; // cost 单位流量费用, flow 最大流量
    Edge() {}
    Edge(int u, int v, int next, int flow, int cost)
        : u(u), v(v), next(next), flow(flow), cost(cost) {}
} e[M<<1];

int n, m, s, t, cnt = 0;
int head[N], dis[N], pre[N], flow[N], q[N<<2];
bool inque[N];

inline int min(int x, int y) { return x < y ? x : y; }

inline void add(int u, int v, int flow, int cost) {
    e[cnt] = Edge(u, v, head[u], flow, cost);
    head[u] = cnt++;
}

bool SPFA(int s, int t) {
    int hd = 0, tp = 0;
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        inque[i] = false;
    }
    flow[q[tp++] = s] = INF;
    pre[s] = dis[s] = 0;
    inque[s] = true;
    int u;
    while (hd != tp) {
        inque[u = q[hd++]] = false; hd %= n;
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if (dis[u]+e[i].cost < dis[v] && e[i].flow > 0) {
                dis[v] = dis[u]+e[i].cost;
                pre[v] = i;
                flow[v] = min(flow[u], e[i].flow);
                if (!inque[v]) inque[q[tp++] = v] = true;
                tp %= n;
            }
        }
    }
    return dis[t] != INF;
}

int MCMF() {
    int _flow = 0, cost = 0;
    while (SPFA(s, t)) {
        _flow += flow[t];
        cost += dis[t]*flow[t];
        int u = t;
        while (u != s) {
            e[pre[u]].flow -= flow[t];
            e[pre[u]^1].flow += flow[t];
            u = e[pre[u]].u;
        }
    }
    printf("%d %d\n", _flow, cost);
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++) {
        int u, v, flow, cost;
        scanf("%d%d%d%d", &u, &v, &flow, &cost);
        add(u, v, flow, cost);
        add(v, u, 0, -cost);
    }
    MCMF();
    return 0;
}
