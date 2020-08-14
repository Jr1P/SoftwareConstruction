#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
const int N = 305;
const int INF = __INT_MAX__;

inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

int val[N][N], ex0[N], ex1[N], match[N], slack[N];
bool vis0[N], vis1[N];
int n;

bool dfs(int u) {
    vis0[u] = 1;
    for(int i = 1; i <= n; i++) {
        if(vis1[i]) continue;
        int gap = ex0[u]+ex1[i]-val[u][i];
        if(!gap) {
            vis1[i] = true;
            if(match[i] == -1 || dfs(match[i])) {
                match[i] = u;
                return true;
            }
        } else slack[i] = min(slack[i], gap);
    }
    return false;
}

int KM() {
    mem(match, -1); mem(ex1, 0);
    for(int i = 1; i <= n; i++) {
        ex0[i] = val[i][1];
        for(int j = 2; j <= n; j++)
            ex0[i] = max(val[i][j], ex0[i]);
    }
    for(int i = 1; i <= n; i++) {
        mem(slack, 0x3f);
        while(1) {
            mem(vis0, false); mem(vis1, false);
            if(dfs(i)) break;
            int d = INF;
            for(int j = 1; j <= n; j++) if(!vis1[j]) d = min(d, slack[j]);
            for(int j = 1; j <= n; j++) {
                if(vis0[j]) ex0[j] -= d;
                if(vis1[j]) ex1[j] += d;
                else slack[j] -= d;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += val[match[i]][i];
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                scanf("%d", &val[i][j]);
        printf("%d\n", KM());
    }

    return 0;
}