#include <cstdio>
#include <queue>
#include <cstring>
#define rep(i, a, n) for(int i = a; i <= n; i++)
const int N = 205 << 1;

struct Edge {
    int v, next;
    Edge() {}
    Edge(int v1, int next1) : v(v1), next(next1) {}
} e[N * N], e1[N * N];

int n, m, cnt, head[N], cnt1, head1[N];
int color[N], match[N];
bool vis[N], check[N];

inline void init(int n) {
    cnt = cnt1 = 0;
    rep(i, 0, n)
        head[i] = -1, vis[i] = false, color[i] = -1,
        head1[i] = -1;
}

inline void add(int u, int v) {
    e[++cnt] = Edge(v, head[u]);
    head[u] = cnt;
}

inline void add1(int u, int v) {
    e1[++cnt1] = Edge(v, head1[u]);
    head1[u] = cnt1;
}

std::queue<int > q;
bool bfs(int u) {
    while(!q.empty()) q.pop();
    q.push(u);
    vis[u] = 1;
    color[u] = 0;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i = head[now], v = e[i].v; i != -1; i = e[i].next, v = e[i].v) {
            if(color[now] == color[v])
                return false;
            if(vis[v]) continue;
            color[v] = color[now] ^ 1;
            vis[v] = 1;
            q.push(v);
        }
    }
    return true;
}

bool dfs(int u) {
    for(int i = head1[u], v = e1[i].v; i != -1; i = e1[i].next, v = e1[i].v)
        if(!check[v]) {
            check[v] = 1;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, -1, sizeof(match));
    for (int i = 1; i <= n; i++) {
        memset(check, false, sizeof(check)),
        ans += dfs(i);
    }
    return ans;
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        bool f = false;
        init(n);
        while(m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
            add1(u, v + n);
        }
        rep(i, 1, n) 
            if(!vis[i] && !bfs(i)) {
                puts("No");
                f = true;
                break;
            }
        if(f) continue;
        printf("%d\n", hungarian());
    }
    return 0;
}