#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define INF 99999999

int map[20][20];
int n, m;
int dp[20][1050];
int vis[20];

inline int min(int x, int y) {
    return x < y? x: y;
}

queue<int > q;

void dfs(int s, int pre) {
    if(pre == (1<<n)-1) return ;
    //if(dp[s][pre]) return ;
    for(int i = 1; i <= n; i++)
        if(i != s && map[s][i] && vis[i] < 2) {
            int now = pre|(1<<(i-1));
            //if(dp[i][now] > dp[s][pre]+map[s][i]) {
            dp[i][now] = dp[s][pre]+map[s][i];
            vis[i]++;
            dfs(i, now);
            vis[i]--;
            //}
        }
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        memset(dp, 127, sizeof(dp));
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            map[u][v] = map[v][u] = w;
        }
        //for(int i = 1; i <= n; i++)
        for(int i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            vis[i]++;
            dp[i][1<<(i-1)] = 0;
            dfs(i, 1<<(i-1));
        }
        int mm = INF;
        for(int i = 1; i <= n; i++)
            mm = min(mm, dp[i][(1<<n)-1]);
        if(mm != INF)
            printf("%d\n", mm);
        else printf("-1\n");
    }
    return 0;
}