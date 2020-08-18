#include <cstdio>
#include <cstring>
const int N = 2005;
const int M = 3e4;

int n, m, cnt;
int head[N], match[N];
bool check[N];

struct Edge {
    int v, nxt;
}e[M];

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
    for(int i = 1; i <= n; i++) {
        memset(check, false, sizeof(check));
        ans += dfs(i);
    }
    return ans;
}


int main() {
    while(~scanf("%d%d", &n, &m)) {
        memset(head, -1, sizeof(head));
        cnt = 0;
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v+n);
        }
        printf("%d\n", hungrian());
    }
    return 0;
}