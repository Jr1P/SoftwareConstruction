#include <cstdio>
#include <queue>
#pragma GCC optimize(2)
const int N = 1e4 + 5;
const int M = 1e4 + 5;
const int INF = 0x7fffffff;
#define rep(i, a, n) for(int i = (a); i <= (n); i++)

int n, m, cnt;
int head[N], dis[N], num[N];
bool exist[N];

struct Edge {
    int v, nxt, w;
    Edge() {}
    Edge(int _v, int _nxt, int _w) : v(_v), nxt(_nxt), w(_w) {}
}e[M];

inline void add(int u, int v, int w) {
    e[++cnt] = Edge(v, head[u], w);
    head[u] = cnt;
}

std::queue<int > q;
bool spfa(int u) {
    while(!q.empty()) q.pop();
    q.push(u); exist[u] = true;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        for(int i = head[now]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(dis[now] + e[i].w < dis[v]) {
                dis[v] = dis[now] + e[i].w;
                if(++num[v] >= n)
                    return true;
                if(!exist[v]) {
                    q.push(v);
                    exist[v] = true;
                }
            }
        }
        exist[now] = false;
    }
    return false;
}

inline void init() {
    rep(i, 1, n)
        dis[i] = INF, exist[i] = false, head[i] = num[i] = 0;
    dis[1] = 0; cnt = 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        init();
        rep(i, 1, m) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            if(w >= 0)
                add(v, u, w);
        }
        if(spfa(1)) puts("YE5"); // 负环
        else puts("N0");
    }
    return 0;
}