#include <cstdio>
#include <vector>
#define INF 0x3fffffff
#define N 10050

struct Edge {
	int v, w;
	Edge() {}
	Edge(int _v, int _w) : v(_v), w(_w) {}
};

int a, b, c, n, m;
int dis[N];
bool vis[N];
std::vector<Edge > g[N];

bool spfa(int u) {
	vis[u] = true;
	for(int i = 0; i < g[u].size(); i++) {
		int v = g[u][i].v;
		if(dis[u] + g[u][i].w > dis[v]) {
			dis[v] = dis[u] + g[u][i].w;	
			if(vis[v]) return false;
			if(!spfa(v)) return false;
		}
	}
	vis[u] = false;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int type;
		scanf("%d%d%d", &type, &a, &b);
		if(type == 3) {
			g[a].push_back(Edge(b, 0));
			g[b].push_back(Edge(a, 0));
		} else if(type == 2) {
			scanf("%d", &c);
			g[a].push_back(Edge(b, -c));
		} else {
			scanf("%d", &c);
			g[b].push_back(Edge(a, c));
		}
	}
	for(int i = 1; i <= n; i++) {
		g[0].push_back(Edge(i, 0));
		dis[i] = -INF;	
	}
	if(!spfa(0)) puts("No");
	else puts("Yes");
	return 0;
}
