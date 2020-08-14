#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 500;
const int M = 2e5;

int n, m, cnt;
int head[N], match[N];
bool check[N];

struct Edge {
    int v, nxt;
} e[M];

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
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &m, &n);
        cnt = 0;
        memset(head, -1, sizeof(head));
        for(int i = 1; i <= m; i++) {
            int p;
            scanf("%d", &p);
            while(p--) {
                int u;
                scanf("%d", &u);
                add(u, i+n);
            }
        }
        if(m == hungrian()) puts("YES");
        else puts("NO");
    }
    return 0;
}