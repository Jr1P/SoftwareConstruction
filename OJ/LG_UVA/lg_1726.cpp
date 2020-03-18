#include <cstdio>
#include <vector>
#include <iostream>
#define N 5050
#define INF 0x3fffffff

int n, m, tim, top, sum;
int dfn[N], stack[N << 1], cnt[N], color[N], low[N << 1];
bool vis[N];
std::vector<int > g[N];

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	vis[u] = true;
	stack[++top] = u;
	int sz = g[u].size();
	for(int i = 0; i < sz; i++) {
		int v = g[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else
			if(vis[v]) low[u] = std::min(low[u], low[v]);
	}
	if(dfn[u] == low[u]) {
		color[u] = ++sum;
		vis[u] = false;
		while(stack[top] != u) {
			color[stack[top]] = sum;
			vis[stack[top--]] = false;
		}
		top--;
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(v);
		if(w == 2)
			g[v].push_back(u);
	}
	for(int i = 1; i <= n; i++)
		if(!dfn[i])
			tarjan(i);
	int p = 1;
	for(int i = 1; i <= n; i++)
		cnt[color[i]]++;
	for(int i = 2; i <= sum; i++)
		if(cnt[i] > cnt[p])
			p = i;
	printf("%d\n", cnt[p]);
	for(int i = 1; i <= n; i++)
		if(color[i] == p)
			printf("%d ", i);
	return 0;
}
