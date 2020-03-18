#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define drep(i, n, a) for(int i = n; i >= a; i--)
const int N = 1005;

int n, m;
int match[N << 1];
bool check[N << 1];
std::vector<int >G[N << 1];

bool dfs(int u) {
    rep (i, 0, G[u].size() - 1) {
        int v = G[u][i];
        if (!check[v]) {
            check[v] = true;
            if (match[v] == -1 || dfs(match[v])) { 
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    mem(match, -1);
    rep (i, 1, n) {
        if (match[i] == -1) {
            mem(check, 0);
            if (dfs(i))
                ans++;
        }
    }
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        rep(i, 1, n) G[i].clear();
        rep(i, 1, n) {
            scanf("%d", &m);
            rep(j, 1, m) {
                int p, q;
                scanf("%d%d", &p, &q);
                G[i].push_back(n + p * 13 + q);
            }
        }
        printf("%d\n", hungarian());
    }
    return 0;
}