#include <cstdio>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define N 2050
#define M 4000060

char g[N][N];
bool vis[N];
int n, ans, head[N], cnt;

struct Edge
{
	int v, next;
}e[M];

inline void add(int u, int v) {
	e[++cnt].v = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}

queue<int > q;

void bfs(int x) {
	while(!q.empty()) q.pop();
	q.push(x);
	ans++;
	vis[x] = 1;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = head[u]; i != -1; i = e[i].next) {
			int v = e[i].v;
			if(!vis[v]) {
				q.push(v);
				vis[v] = 1;
				ans++;
			}
		}
	}
}

int main() {
	ans = 0;
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) head[i] = -1;
	for(int i = 1; i <= n; i++) {
		char c = getchar();
		scanf("%s", g[i]);
		for(int j = 1; j <= n; j++)
			if(g[i][j-1] == '1')
				add(i, j);

	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) vis[j] = false;
		bfs(i);
	}
	printf("%d\n", ans);
	return 0;
}