#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define N 200050

struct Edge{
    int u, v;
}e[N<<1];

int fa[N];
int n, color[N], s, d;
int cnt[2], dis[N];
bool vis[N];
vector<int > G[N];

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void _union(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if(f1 == f2) return ;
    if(f1 < f2)
        fa[f2] = f1;
    else fa[f1] = f2;
}

queue<int > q;

void bfs(int u) {
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    while(!q.empty()) q.pop();
    q.push(u);
    vis[u] = true;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int i = 0; i < G[now].size(); i++) {
            int v = G[now][i];
            if(!vis[v]) {
                q.push(v);
                vis[v] = true;
                s = v;
                dis[v] = dis[now]+1;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &color[i]);
        fa[i] = i;
    }
    for(int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[2*i-1].u = u; e[2*i-1].v = v;
        e[i*2].u = v; e[i*2].v = u;
        if(color[u] == color[v])
            _union(u, v);
    }
    for(int i = 1; i <= n; i++) fa[i] = find(i);
    for(int i = 1; i < n; i++) {
        int u = e[i*2-1].u, v = e[i*2-1].v;
        if(fa[u] != fa[v]) {
            G[fa[u]].push_back(fa[v]);
            G[fa[v]].push_back(fa[u]);
        }
    }
    int i = 1;
    for(; G[i].size() == 0 && i <= n; i++) ;
    if(i > n) {
        printf("0\n");
        return 0;
    }
    bfs(i);
    bfs(s);
    printf("%d\n", (dis[s]+1)/2);
    return 0;
}