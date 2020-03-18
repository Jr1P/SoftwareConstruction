#include <cstdio>
#include <queue>
const int M = 2e5 + 5;
const int N = 1e5 + 5;
const int INF = 0x7fffffff;
#define rep(i, a, n) for(int i = a; i <= n; i++)

int n, m, s, cnt;
int head[N], dis[N];
bool vis[N];

struct Edge {
    int v, nxt, w;
    Edge() {}
    Edge(int _v, int _nxt, int _w) : v(_v), nxt(_nxt), w(_w) {}
}e[M];

struct Node {
    int dis, u;
    bool operator < (const Node a) const {
        return a.dis < dis;
    }
    Node() {}
    Node(int _u, int _dis) : u(_u), dis(_dis) {}
};

inline void add(int u, int v, int w) {
    e[++cnt] = Edge(v, head[u], w);
    head[u] = cnt;
}

std::priority_queue<Node> q;
void dijkstra(int u) {
    while(!q.empty()) q.pop();
    q.push(Node(u, 0));
    while(!q.empty()) {
        int now = q.top().u; q.pop();
        if(vis[now]) continue;
        vis[now] = true;
        for(int i = head[now]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(!vis[v] && dis[v] > dis[now] + e[i].w) {
                dis[v] = dis[now] + e[i].w;
                q.push(Node(v, dis[v]));
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    rep(i, 1, n) dis[i] = INF;
    dis[s] = 0;
    rep(i, 1, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra(s);
    rep(i, 1, n) printf("%d ", dis[i]);
    return 0;
}