#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff;
const int MAXN =1e5+1;
const int MAXM =2e5+1;

int n, m, head[MAXN], dis[MAXN], cnt;
bool vis[MAXN];

struct EDGE {
	int w, next, v;
}e[MAXM];

struct NODE {
	int u, dis;
    bool operator < (const NODE& a) const {
        return dis < a.dis;
    }
};

inline void init() {
	for(int i = 1; i <= n; i++) {
		head[i] = -1;
		vis[MAXN] = false;
		dis[i] = -INF;
	}
	dis[1] = 0;
}

inline void add(int u, int v, int w) {
	e[++cnt].w = w;
	e[cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dijkstra(int s) {
	priority_queue<NODE> q;
	NODE temp;
	while(!q.empty()) q.pop();
	temp.u = s; temp.dis = 0;
	q.push(temp);
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if(!vis[v] && dis[v] < dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				temp.u = v; temp.dis = dis[v];
				q.push(temp);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	init();
	for(int i = 1; i <= m; i++) {
		int u, v, w;
        char ch;
		scanf("%d %d %d %c", &u, &v, &w, &ch);
		add(u, v, w);
		add(v, u, w);
	}
	dijkstra(1);
    int ma = 0, s;
    for(int i = 1; i <= n; i++) {
        if(dis[i] > ma) {
            s = i;
            ma = dis[i];
        }
    }
	for(int i = 1; i <= n; i++) {
        dis[i] = -INF;
        vis[i] = false;
    }
    dis[s] = 0;
    dijkstra(s);
    ma = 0;
    for(int i = 1; i <= n; i++) {
        if(dis[i] > ma)
            ma = dis[i];
    }
    printf("%d\n", ma);
	return 0;
}