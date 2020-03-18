#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[13][2550];
int f[20000][2];
int n, m, t;

void dfs(int l, int now, int pre) {
    if(l > m) return ;
    if(l == m) {
        f[t][0] = pre;
        f[t++][1] = now;
    }
    dfs(l+2, now<<2|3, pre<<2|3);
    dfs(l+1, now<<1|1, pre<<1);
    dfs(l+1, now<<1, pre<<1|1);
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == 0 && m == 0) break;
        t = 0;
        memset(dp, 0, sizeof(dp));
        dfs(0, 0, 0);
        dp[0][(1<<m)-1] = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < t; j++)
                dp[i+1][f[j][1]] += dp[i][f[j][0]];
        printf("%lld\n", dp[n][(1<<m)-1]);
    }
    return 0;
}