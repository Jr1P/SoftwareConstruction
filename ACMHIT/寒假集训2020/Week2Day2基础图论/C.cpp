#include <cstdio>
#include <queue>
#include <vector>
const int N = 1000050;
const int INF = 0x5fffffff;

struct Edge {
    int v, w;
    Edge() {}
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

struct Node {
	int u, dis;
	bool operator < (const Node &a) const {
		return dis > a.dis;
	}
    Node() {}
    Node(int _u, int _dis) : u(_u), dis(_dis) {}
};

int n, s, t, m;
int dis[N], dis2[N];
bool vis[N], vis2[N];
std::vector<Edge> g1[N], g2[N];

inline void init() {
    for(int i = 0; i <= n; i++) {
        vis[i] = vis2[i] = false;
        g1[i].clear();
        g2[i].clear();
        dis[i] = dis2[i] = INF;
    }
}

std::priority_queue<Node> q;
void dijkstra(int s) {
	while(!q.empty()) q.pop();
	q.push(Node(s, 0));
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for(int i = 0; i < g1[u].size(); i++) {
			int v = g1[u][i].v;
			if(!vis[v] && dis[v] > dis[u] + g1[u][i].w) {
				dis[v] = dis[u] + g1[u][i].w;
				q.push(Node(v, dis[v]));
			}
		}
	}
}

void dijkstra2(int s) {
	while(!q.empty()) q.pop();
	q.push(Node(s, 0));
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis2[u]) continue;
		vis2[u] = true;
		for(int i = 0; i < g2[u].size(); i++) {
			int v = g2[u][i].v;
			if(!vis2[v] && dis2[v] > dis2[u] + g2[u][i].w) {
				dis2[v] = dis2[u] + g2[u][i].w;
				q.push(Node(v, dis2[v]));
			}
		}
	}
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        init();
        dis[1] = 0; dis2[1] = 0;
        while(m--) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            g1[v].push_back(Edge(u, w));
            g2[u].push_back(Edge(v, w));
        }
        dijkstra(1); dijkstra2(1);
        long long ans = 0L;
        for(int i = 1; i <= n; i++)
            ans += dis[i] + dis2[i];
        printf("%lld\n", ans);
    }
}