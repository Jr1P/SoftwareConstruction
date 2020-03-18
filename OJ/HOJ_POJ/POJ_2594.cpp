#include <cstdio>
#include <cstring>
const int N = 505;

int match[N];
bool vis[N], g[N][N];
int n, m;

void floyed() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(g[i][k] && g[k][j])
                    g[i][j] = true;
}

bool dfs(int u) {
    for(int i = 1; i <= n; i++) {
        if(!vis[i] && g[u][i]) {
            vis[i] = true;
            if(!match[i] || dfs(match[i])) {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, 0, sizeof(match));
    for(int i = 1; i <= n; i++)
        memset(vis, false, sizeof(vis)),
        ans += dfs(i);
    return ans;
}

int main() {
    while(~scanf("%d%d", &n, &m) && (n || m)) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                g[i][j] = false;
        while(m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u][v] = true;
        }
        floyed();
        printf("%d\n", n - hungarian());
    }
    return 0;
}