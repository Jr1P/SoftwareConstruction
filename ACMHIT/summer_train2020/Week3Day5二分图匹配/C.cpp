#include <cstdio>
#include <cstring>
const int N = 205;

int n, m, cnt;
int ro = 0, co = 0;
int head[N], match[N];
bool check[N];
int vv[N][N], cc[N][N];
char map[N][N];

inline int max(int x, int y) { return x > y ? x : y; }

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
    for(int i = 1; i <= n+max(ro, co); i++) {
        memset(check, false, sizeof(check));
        ans += dfs(i);
    }
    return ans;
}


int main() {
    while(~scanf("%d", &n) && n) {
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++) vv[i][j] = cc[i][j] = 0;
        cnt = ro = co = 0;
        int pa = 50;
        memset(head, -1, sizeof(head));
        for(int i = 0; i < n; i++) scanf("%s", map[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(map[i][j] == 'X') ro++;
                else if(i == 0 && map[i][j] == '.') {
                    add(i+ro+1, j+1+pa);
                    cc[i][j] = i+ro+1;
                    vv[i][j] = j+1+pa;
                } else if(map[i][j] == '.' && cc[i-1][j]) {
                    add(i+ro+1, vv[i-1][j]);
                    vv[i][j] = vv[i-1][j];
                    cc[i][j] = cc[i-1][j];
                } else {
                    co++;
                    add(i+ro+1, n+pa+co);
                    vv[i][j] = n+pa+co;
                    cc[i][j] = i+ro+1;
                }
            }
        printf("%d\n", hungrian());
    }
    return 0;
}