#include <cstdio>
#include <queue>
const int INF = 0x3f3f3f3f;
const int N = 5e3+5;
const int M = 1e5+5;

struct Edge {
    int v, nxt, w;
} e[M << 1];

struct Node {
    int u, dis;
    bool operator < (Node o) const {
        return dis > o.dis;
    }
};

int n, cnt, head[N], dis[N], ddis[N];
bool vis[N];

std::priority_queue<Node> q;

inline void add(int u, int v, int w) {
    e[++cnt] = (Edge){v, head[u], w};
    head[u] = cnt;
}

void dij(int s) {
    q.push({s, 0});
    dis[s] = ddis[s] = 0;
    while(!q.empty()) {
        int u = q.top().u; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(!vis[v] && dis[v] > dis[u]+e[i].dis) {
                dis[v] = dis[u]+e[i].dis;
                q.push({v, dis[v]});
            }
            if(!vis[v] && ddis[v] > ddis[u]+e[i].dis) {
                ddis[v] = ddis[u]+e[i].dis;
                q.push({v, ddis[v]});
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    for(int i = 1; i <= n; i++) dis[i] = ddis[i] = INF;
    dij(1);
    return 0;
}