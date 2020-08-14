#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 55;

int n, m;
int match[N*N], head[N*N];
bool check[N*N];
char map[N][N];
int num1[N][N], num2[N][N];
int tot1 = 0, tot2 = 0, tot = 0, cnt = 0;

struct Edge {
    int v, nxt;
} e[N*N];

inline void add(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
    head[u] = cnt;
}

bool dfs(int u) {
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(!check[v]) {
            check[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungrian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i = 1; i <= tot1; i++) {
        memset(check, false, sizeof(check));
        ans += dfs(i);
    }
    return ans;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(head, -1, sizeof(head));
        tot1 = tot2 = cnt = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s", map[i]);
            for(int j = 0; j < m; j++) {
                if(map[i][j] == '*') {
                    if(!num1[i+1][j])
                        num1[i+1][j+1] = ++tot1;
                    else num1[i+1][j+1] = num1[i+1][j];
                    if(!num2[i][j+1])
                        num2[i+1][j+1] = ++tot2;
                    else num2[i+1][j+1] = num2[i][j+1];
                }
            }
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(map[i][j] == '*')
                    add(num1[i+1][j+1], num2[i+1][j+1]+750);
        printf("%d\n", hungrian());
    }
    return 0;
}