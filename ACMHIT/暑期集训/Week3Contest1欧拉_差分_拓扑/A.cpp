#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define N 5050

int du[N], head[N];
int n, m, cnt;
int q[N<<1];
bool vis[N]; //g[1050][1050];

struct Edge {
	int v, next;
}e[N<<1];

inline void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void bfs() {
	int h = 0, t = 1;
	q[h] = 1;
	vis[1] = true;
	while(h != t) {
		int u = q[h];
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if(!vis[v]) {
				q[t++] = v;
				vis[v] = true;
			}
		}
		h++;
	}
}

int main() {
	while(scanf("%d", &n) != EOF) {
		bool f = false;
		if(n == 0) break;
		scanf("%d", &m);
		cnt = 0;
		//memset(g, false, sizeof(g));
		for(int i = 0; i <= n; i++) {
			vis[i] = false;
			head[i] = -1;
			du[i] = 0;
			q[i] = 0;
		}
		for(int i = 1; i <= m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			//if(!g[u][v]) {
				add(u, v), add(v, u);
			//	g[u][v] = 1;
				du[u]++; du[v]++;
			//}
		}
		bfs();
		for(int i = 1; i <= n; i++) {
			if((du[i]%2 == 1) || !vis[i]) {
				printf("0\n");
				f = true;
				break;
			}
		}
		if(!f) printf("1\n");
	} //
	return 0;
}