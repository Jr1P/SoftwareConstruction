#include <cstdio>
const int N = 10;

int n, k1, cnt;
int state[1 << N];
long long dp[N][1 << N][N * N];

inline int calc(int state) {
    int ans = 0;
    while(state) {
        if(state & 1) ans++;
        state >>= 1;
    }
    return ans;
}

inline bool check(int j, int k) {
    return ((state[j] & state[k]) == 0) && (((state[j] << 1) & state[k]) == 0) && (((state[j] >> 1) & state[k]) == 0);
}

int main() {
    scanf("%d%d", &n, &k1);
    for(int i = 0; i < (1 << n); i++) 
        if(((i & (i >> 1)) == 0) && ((i & (i << 1)) == 0)) state[++cnt] = i;
    // printf("%d\n", cnt);
    dp[1][0][0] = 1;
    for(int i = 1; i <= cnt; i++)
        dp[1][i][calc(state[i])] = 1;
    for(int i = 2; i <= n; i++)
        for(int k = 1; k <= cnt; k++) {
            int num = calc(state[k]);
            for(int j = 1; j <= cnt; j++)
                if(check(j, k))
                    for(int l = num; l <= k1; l++)
                        dp[i][k][l] += dp[i - 1][j][l - num];
        }
    long long ans = 0;
    for(int i = 1; i <= cnt; i++)
        ans += dp[n][i][k1];
    printf("%lld\n", ans);
    return 0;
}