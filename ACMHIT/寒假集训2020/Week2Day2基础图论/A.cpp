#include <cstdio>
#include <queue>
#include <vector>
const int N = 1050;
const int INF = 0x3fffffff;

struct Edge {
	int v, w;
	Edge() {}
	Edge(int _v, int _w) : v(_v), w(_w) {}
};

int n;
int father[N], cnt[N];
bool exist[N];
std::vector<Edge> g[N];

inline int min(int x, int y) { return x < y ? x : y; }

void init() {
	for(int i = 1; i <= n; i++)
		father[i] = i;
}

int find(int x) {
	if(x == father[x]) return x;
	return father[x] = find(father[x]);
}

inline void _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(x);
}

/*void floyd() {
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}*/

std::queue<int> q;
bool spfa() {
	while(!q.empty()) q.pop();
	q.push();
	exist[] = true;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = 0; i < g[u].size(); i++) {
			int v = g[u][i].v;
			if(dis[v] > dis[u] + g[u][i].w) {
				dis[v] = dis[u] + g[u][i].w;
				if(!exist[v]) {
					if(++cnt[v] >= n) return false;
					q.push(v);
					exist[v] = true;
				}
			}
		}
		exist[u] = false;
	}
	return true;
}

int main() {
	
	return 0;
}
