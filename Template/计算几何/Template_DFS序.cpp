#include <vector>
#include <cstdio>
const int N = 1e5 + 5;

std::vector<int> g[N];
int n, len = 0;
int dfn[N], l[N], r[N];
bool vis[N];

inline void print(int p[]) {
	for(int i = 1; i <= n; i++)
		printf("%d ", p[i]);
	puts("");
}

void dfs(int u) {
	vis[u] = 1;
	int x = len + 1;
	dfn[++len] = u;
	l[u] = len;
	int sz = g[u].size();
	for (int i = 0; i < sz; i++)
		if(!vis[g[u][i]])
			dfs(g[u][i]);
	r[u] = len;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1);
	print(dfn);
	print(l);
	print(r);
}
/*
10
1 3
3 2
3 4
4 6
4 7
1 5
5 8
5 9
8 10
*/