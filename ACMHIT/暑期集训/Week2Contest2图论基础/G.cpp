#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
#define N 250050
const long long INF = 0x7fffffffffffffff;

typedef long long ll;

struct Edge{
    int v, next;
    ll w;
}e[N];

struct Node{
    int u;
    ll dis;
    bool operator < (const Node& rhs) const {
        return dis > rhs.dis;
    }
};

int n, m, cnt;
int head[N];
bool vis[N];
ll a[N], dis[N];

inline void init() {
    for(int i = 0; i <= n; i++) {
        dis[i] = INF;
        head[i] = -1;
        vis[i] = false;
    }
    dis[0] = 0;
}

inline void add(int u, int v, ll w) {
    e[++cnt].w = w;
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}

void dij(int s) {
    priority_queue<Node > q;
    while(!q.empty()) q.pop();
    Node tmp;
    tmp.u = s; tmp.dis = 0;
    q.push(tmp);
    while(!q.empty()) {
        int u = q.top().u;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(dis[v] > dis[u]+e[i].w) {
                dis[v] = dis[u]+e[i].w;
                tmp.u = v; tmp.dis = dis[v];
                q.push(tmp);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    init();
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        w <<= 1;
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        add(0, i, a[i]);
    }
    dij(0);
    for(int i = 1; i <= n; i++)
        printf("%lld ", dis[i]);
    return 0;
}