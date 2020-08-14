#include <cstdio>
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
const int INF = 0x3f3f3f3f;
const int N = 500;
const int M = 1e4;

inline int min(int x, int y) { return x < y ? x : y; }

struct Node {
    int u, dis;
};

int a, b, m, L, K, n;
int dis[N][N], dp[N][20];
bool use[N][N];

void floyed() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dis[i][j] > dis[i][k]+dis[k][j]) {
                    dis[i][j] = dis[i][k]+dis[k][j];
                    if(dis[i][j] <= L && k <= a) use[i][j] = 1;
                }
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d%d%d", &a, &b, &m, &L, &K);
        n = a+b;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) dis[i][j] = INF, use[i][j] = 0;
        for(int i = 1; i <= n; i++) dis[i][i] = 0; 
        while(m--) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            dis[u][v] = dis[v][u] = w;
            if(w <= L) use[u][v] = use[v][u] = 1;
        }
        floyed();
        for(int i = 1; i <= n; i++) dp[i][0] = dis[1][i];
        for(int i = 2; i <= n; i++) {
            for(int k = 1; k <= K; k++) {
                int tmp = INF;
                for(int j = 1; j < i; j++)
                    if(use[j][i])
                        tmp = min(tmp, min(dp[j][k-1], dp[j][k]+dis[j][i]));
                    else tmp = min(tmp, dp[j][k]+dis[j][i]);
                dp[i][k] = tmp;
            }
        }
        printf("%d\n", dp[n][K]);
    }
    return 0;
}