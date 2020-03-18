#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 350
#define M 350
//Hungarian O(V*E)

vector<int> G[N<<1];
int n, m, e;
int match[N<<1]; //match[i]=j, 表示i与j配对
bool check[N<<1];

bool dfs(int u) {
    for (unsigned i = 0; i < G[u].size(); ++i) {
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
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; i++) {
        if (match[i] == -1) {
            memset(check, false, sizeof(check));
            if (dfs(i))
                ans++;
        }
    }
    return ans;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= n; i++) {
            int num, v;
            scanf("%d", &num);
            for(int j = 1; j <= num; j++) {
                scanf("%d", &v);
                G[i].push_back(v+n);
            }
        }
        printf("%d\n", hungarian());
    }
    return 0;
}
