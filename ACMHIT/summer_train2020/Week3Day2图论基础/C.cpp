#include <cstdio>
#include <queue>
typedef long long ll;
const ll INF = __LONG_LONG_MAX__;
const int N = 2e6+500;

struct Edge {
    int v, nxt;
    ll w;
} e[N];

struct Node {
    int u; ll dis;
    bool operator < (const Node o) const {
        return dis > o.dis;
    }
};

int n, m, cnt, head[N];
ll dis[N];
bool vis[N];

std::priority_queue<Node> q;

inline void add(int u, int v, ll w) {
    e[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

void dij(int s) {
    while(!q.empty()) q.pop();
    q.push({s, 0});
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.top().u; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if(dis[v] > dis[u]+e[i].w) {
                dis[v] = dis[u]+e[i].w;
                q.push({v, dis[v]});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; i++) {
        dis[i] = INF;
        head[i] = -1; vis[i] = false;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        w <<= 1;
        add(u, v, w); add(v, u, w);
    }
    for(int i = 1; i <= n; i++) {
        ll a;
        scanf("%lld", &a);
        add(0, i, a);
    }
    dij(0);
    for(int i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}