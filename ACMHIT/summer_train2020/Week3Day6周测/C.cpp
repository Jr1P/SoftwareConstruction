#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 305;

int match[N<<1], val[N][N], ex0[N], ex1[N], slack[N];
int n, m;
bool vis0[N], vis1[N];

inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

bool dfs(int u) {
    vis0[u] = true;
    for(int v = 1; v <= n; v++) {
        if(vis1[v]) continue;
        int gap = ex0[u]+ex1[v]-val[u][v];
        if(!gap) {
            vis1[v] = true;
            if(match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        } else slack[v] = min(slack[v], gap);
    }
    return false;
}

int KM() {
    mem(match, -1); mem(ex1, 0);
    for(int i = 1; i <= n; i++) {
        ex0[i] = val[i][1];
        for(int j = 2; j <= n; j++)
            ex0[i] = max(ex0[i], val[i][j]);
    }
    for(int i = 1; i <= n; i++) {
        mem(slack, 0x3f);
        while(1) {
            mem(vis1, false); mem(vis0, false);
            if(dfs(i)) break;
            int d = __INT_MAX__;
            for(int j = 1; j <= n; j++) if(!vis1[j]) d = min(d, slack[j]);
            for(int j = 1; j <= n; j++) if(vis0[j]) ex0[j] -= d;
            for(int j = 1; j <= n; j++)
                if(vis1[j]) ex1[j] += d;
                else slack[j] -= d;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(match[i] != -1) ans += val[match[i]][i];
    return -ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        mem(val, 0x8f);
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            val[u][v] = max(val[u][v], -w);
        }
        printf("%d\n", KM());

    }
    return 0;
}