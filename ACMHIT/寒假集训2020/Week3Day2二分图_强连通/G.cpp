#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define drep(i, n, a) for(int i = n; i >= a; i--)

const int N = 2050;

int n, m;
int match[N];
bool check[N];
std::vector<int > G[N];

bool dfs(int u) {
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!check[v]) {
            check[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
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
    memset(match, -1, sizeof(match));
    rep(i, 1, n) {
        if(match[i] == -1) {
            memset(check, false, sizeof(check));
            if(dfs(i)) ans++;
        }
    }
    return ans;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        for(int i = 1; i <= n; i++) G[i].clear();
        rep(i, 1, n) {
            int cnt;
            scanf("%d", &cnt);
            rep(j, 1, cnt) {
                int v;
                scanf("%d", &v);
                G[i].push_back(n + v);
            }
        }
        printf("%d\n", hungarian());
    }
    return 0;
}