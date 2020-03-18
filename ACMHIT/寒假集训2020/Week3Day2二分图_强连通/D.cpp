#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
const int N = 505;

std::vector<int > G[N];

bool vis[N], iscut[N], cutvis[N];
int dfn[N << 1], low[N << 1];
int m, tim = 0, maxn;
int cutnum = 0;
long long sz = 0;

inline int max(int x, int y) { return x > y ? x : y; }
inline int min(int x, int y) { return x < y ? x : y; }

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++tim;
    int sz = G[u].size(), child = 0;
    for(int i = 0; i < sz; i++) {
        int v = G[u][i];
        if(!dfn[v]) {
            tarjan(v, fa);
            low[u] = min(low[v], low[u]);
            if(low[v] >= dfn[u] && u != fa) iscut[u] = true;
            if(u == fa) child++;
        } else
            low[u] = min(low[u], dfn[v]);
    }
    if(fa == u && child >= 2) iscut[u] = true;
}

void dfs(int u) {
    sz++;
    vis[u] = true;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(iscut[v] && !cutvis[v]) {
            cutnum++;
            cutvis[v] = true;
            continue;
        }
        if(!vis[v] && !iscut[v])
            dfs(v);
    }
}

int main() {
    int kase = 0;
	while(scanf("%d", &m)) {
        maxn = 0;
        if(!m) break;
        for(int i = 1; i <= N; i++) {
            G[i].clear();
            vis[i] = iscut[i] = false;
            dfn[i] = low[i] = 0;
        }
        tim = 0;
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            maxn = max(max(u, v), maxn);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(int i = 1; i <= maxn; ++i)
            if(!dfn[i])
                tarjan(i, i);
        
        long long ans1 = 1L, ans0 = 0L;
        for(int i = 1; i <= maxn; i++) {
            if(!iscut[i] && !vis[i]) {
                memset(cutvis, false, sizeof(cutvis));
                sz = cutnum =  0;
                dfs(i);
                if(cutnum >= 2) continue;
                ans1 *= sz;
                ans0++;
            }
        }
        if(ans0 == 1 && ans1 != 1) {
            ans0 = 2;
            ans1 = ans1 * (ans1 - 1) / 2;
        }
        printf("Case %d: %lld %lld\n", ++kase, ans0, ans1);
    }
	return 0;
}