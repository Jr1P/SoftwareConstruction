#include <cstdio>
#include <vector>
const int N = 505;
const int M = 60050;
const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, nxt, cost, flow;
}e[M];

struct Node {
    int x, y;
};

std::vector<Node> per, hou;
int dis[N], head[N], pre[N], flow[N], q[M];
bool inq[N];

int n, m, cnt = -1, s, t;
char map[N][N];

inline int min(int x, int y) { return x < y ? x : y; }
inline void add(int u, int v, int cost) {
    e[++cnt] = (Edge){u, v, head[u], cost, 1}; head[u] = cnt;
    e[++cnt] = (Edge){v, u, head[v], -cost, 0}; head[v] = cnt;
}

inline int abs(int x) { return x < 0? -x: x; }
inline int dist(Node x, Node y) {
    return abs(x.x-y.x)+abs(x.y-y.y);
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
    return cost;
}

int main() {
    while(scanf("%d%d", &n, &m) && n && m) {
        cnt = -1;
        for(int i = 0; i < n; i++) scanf("%s", map[i]);
        for(int i = 0; i < N; i++) head[i] = -1;
        per.clear(), hou.clear();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                if(map[i][j] == 'm') per.push_back((Node){i, j});
                else if(map[i][j] == 'H') hou.push_back((Node){i, j});
            }
        int p = per.size(), h = hou.size();
        for(int i = 0; i < p; i++)
            for(int j = 0; j < h; j++)
                add(i+1, p+j+1, dist(per[i], hou[j]));
        s = 0, t = p+h+1;
        for(int i = 0; i < p; i++)
            add(s, i+1, 0);
        for(int j = 0; j < h; j++)
            add(p+j+1, t, 0);
        printf("%d\n", MCMF());
    }
    return 0;
}