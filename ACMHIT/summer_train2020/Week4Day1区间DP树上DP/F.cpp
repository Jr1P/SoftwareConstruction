#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 1050;
const int INF = 0x3f3f3f3f;

int n, m, cnt = -1;
int d[N], cost[N], dis[N][N];
int dp[N][N], ans[N], head[N];

struct E {
    int v, nxt, w;
} e[N*N];

inline int min(int x, int y) { return x<y?x:y; }

inline void add(int u, int v, int w) {
    e[++cnt] = (E){v, head[u], w};
    head[u] = cnt;
}

void bfs(int s) {
    int q[N], hd = 0, tp = 0;
    dis[s][s] = 0;
    q[tp++] = s;
    while(hd != tp) {
        int u = q[hd++];
        for(int i = head[u]; i != -1; i = e[i].nxt) {
            int v = e[i].v;
            if(!dis[s][v] && v != s) {
                dis[s][v] = dis[s][u]+e[i].w;
                q[tp++] = v;
            }
        }
    }
}

void dfs(int u, int fa) {
    for(int i = head[u]; i != -1; i = e[i].nxt) {
        int v = e[i].v;
        if(v != fa) dfs(v, u);
    }
    for(int i = 1; i <= n; i++) {
        if(dis[u][i] > d[u]) dp[u][i] = INF;
        else {
            int tmp = 0;
            for(int j = head[u]; j != -1; j = e[j].nxt) {
                int v = e[j].v;
                if(v != fa) tmp += min(ans[v], dp[v][i]-cost[i]);
            }
            dp[u][i] = tmp+cost[i];
        }
    }
    for(int i = 1; i <= n; i++) ans[u] = min(ans[u], dp[u][i]);
}

void init() {
    mem(head, -1);
    mem(ans, 0x3f);
    mem(dis, 0);
    mem(dp, 0);
    cnt = -1;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        init();
        for(int i = 1; i <= n; i++) scanf("%d", cost+i);
        for(int i = 1; i <= n; i++) scanf("%d", d+i);
        for(int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w); add(v, u, w);
        }
        for(int i = 1; i <= n; i++) bfs(i);
        dfs(1, 0);
        printf("%d\n", ans[1]);
    }
    return 0;
}