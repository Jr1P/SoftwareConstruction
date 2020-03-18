#include <cstdio>
#include <cstring>
#include <vector>
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 505;

int n;
int match[N << 1];
bool check[N << 1];
std::vector<int > G[N << 1];

bool dfs(int u) {
    for(int i = 0; i < G[u].size(); i++) {
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
    for(int i = 1; i <= n; i++) {
        if (match[i] == -1) {
            mem(check, 0);
            if(dfs(i)) ans++;
            else break;
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                int tmp;
                scanf("%d", &tmp);
                if(tmp == 1)
                    G[i].push_back(n + j);
            }
        if(n == hungarian())
            puts("Yes");
        else puts("No");
    }
    return 0;
}