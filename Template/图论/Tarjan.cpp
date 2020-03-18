#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 10010

vector<int > g[N];

bool vis[N], iscut[N];
int stack[N << 1], dfn[N << 1], low[N << 1], color[N], cnt[N];
int n, m, sum = 0, ans = 0, top = 0, tim = 0;

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	vis[u] = true;
	stack[++top] = u;
	int size = g[u].size();
	for(int i = 0; i < size; ++i) {
		int v = g[u][i];
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else {
			if(vis[v])
				low[u] = min(low[u], dfn[v]);
		}
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

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }

/*void Tarjan(int u, int fa) { // 割点
    low[u] = dfn[u] = ++tim;
    int sz = g[u].size(), child = 0;
    for(int i = 0; i < sz; i++) {
        int v = g[u][i];
        if(!dfn[v]) {
            Tarjan(v, fa);
            low[u] = min(low[v], low[u]);
            if(low[v] >= dfn[u] && u != fa) iscut[u] = true;
			// if(low[v] > dfn[u]) u - v 是桥
            if(u == fa) child++;
        } else
            low[u] = min(low[u], dfn[v]);
    }
    if(fa == u && child >= 2) iscut[u] = true;
}*/

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i])
			tarjan(i);
	for(int i = 1; i <= n; i++)
		cnt[color[i]]++;
	for(int i = 1; i <= sum; i++)
		if (cnt[i] > 1)
			ans++;
	printf("%d\n", ans);
	return 0;
}