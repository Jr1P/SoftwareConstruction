#include <cstdio>
#include <queue>
#include <vector>
const int N = 5e3 + 5;
const int INF = 0x7fffffff;

int n, m, s;
int dis[N], num[N];
bool exist[N];

struct Edge {
    int v, w;
    Edge() {}
    Edge(int _v, int _w) : v(_v), w(_w) {}
};

std::vector<Edge > g[N];

inline void init() {
    s = 0; // 源点
    for(int i = 0; i <= n; i++) {
        g[i].clear();
        dis[i] = INF;
        exist[i] = false;
    }
    dis[s] = 0;
    for(int i = 1; i <= n; i++)
        g[s].push_back(Edge(i, 0));
}

std::queue<int >q;
bool spfa() {
    while(!q.empty()) q.pop();
    q.push(s); exist[s] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop(); exist[u] = false;
        for(int i = 0; i < g[u].size(); i++) {
            int v = g[u][i].v;
            if(dis[v] > dis[u] + g[u][i].w) {
                dis[v] = dis[u] + g[u][i].w;
                if(++num[v] >= n)
                    return true;
                if(!exist[v]) {
                    q.push(v);
                    exist[v] = true;
                }
            }
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[v].push_back(Edge(u, w));
    }
    if(spfa()) puts("NO"); // 无解
    else
        for(int i = 1; i <= n; i++)
            printf("%d ", dis[i]);
    return 0;
}