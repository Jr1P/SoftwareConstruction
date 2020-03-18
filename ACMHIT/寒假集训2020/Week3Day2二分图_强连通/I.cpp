#include <cstdio>
#include <vector>
#include <cstring>

const int N = 2050;
int n, m, k;
std::vector<int > G[N << 1];
int match[N << 1];
bool check[N << 1];
bool flag[35][35];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int dfs(int u) {
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
    for(int i = 1; i <= n * m; i++) {
        if(match[i] == -1) {
            memset(check, false, sizeof(check));
            if(dfs(i)) ans++;
        }
    }
    return ans;
}

inline bool chec(int x, int y) {
    if(flag[x][y] || x <= 0 || x > n || y <= 0 || y > m) return false;
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        flag[y][x] = true;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(flag[i][j]) continue;
            for(int p = 0; p < 4; p++) {
                int tx = i + dx[p], ty = j + dy[p];
                if(chec(tx, ty))
                    G[(i - 1) * m + j].push_back((tx - 1) * m + ty + n * m);
            }
        }
    if(n * m - k == hungarian())
        puts("YES");
    else puts("NO");
    return 0;
}