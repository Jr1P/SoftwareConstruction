#include <cstdio>
const int N = 13;
const int MOD = 1e8;

int n, m, dp[N][1 << N], map[N], state[1 << N], cnt;

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int tmp;
            scanf("%d", &tmp);
            if(tmp) map[i] += (1 << (m - j - 1));
        }
    for(int i = 0; i < (1 << m); i++) if((i & (i >> 1)) == 0) state[++cnt] = i;
    for(int i = 1; i <= cnt; i++)
        dp[0][i] = (map[0] & state[i]) == state[i];
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= cnt; j++) {
            if((map[i - 1] & state[j]) != state[j]) continue;
            for(int k = 1; k <= cnt; k++)
                if(((map[i] & state[k]) == state[k]) && (state[j] & state[k]) == 0)
                    dp[i][k] = (dp[i][k] + dp[i - 1][j]) % MOD;
        }
    int ans = 0;
    for(int i = 1; i <= cnt; i++)
        ans = (ans + dp[n - 1][i]) % MOD;
    printf("%d\n", ans % MOD);
    return 0;
}