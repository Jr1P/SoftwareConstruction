#include <cstdio>
#include <cstring>
#include <vector>
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 505;

int n, m;
std::vector<int > g[N];
int match[N];
bool vis[N];

bool dfs(int u) {
    for(int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(match[v] == -1 || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    mem(match, -1);
    for(int i = 1; i <= n; i++)
        mem(vis, false),
        ans += dfs(i);
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) g[i].clear();
        while(m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].push_back(v + n);
        }
        printf("%d\n", n - hungarian());
    }
    return 0;
}