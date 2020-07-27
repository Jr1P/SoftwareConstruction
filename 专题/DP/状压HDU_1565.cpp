#include <cstdio>
#include <iostream>
#include <cstring>
const int N = 21;

int n, a[N][N], dp[2][1 << N], state[1 << N];

inline int calc(int row, int state) {
    int ans = 0, p = n - 1;
    while(state) {
        if(state & 1)
            ans += a[row][p];
        state >>= 1;
        p--;
    }
    return ans;
}

int main() {
    while(~scanf("%d", &n)) {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        memset(dp, 0, sizeof(dp));
        int cnt = 0;
        for(int i = 0; i < (1 << n); i++) if((i & (i >> 1)) == 0) state[++cnt] = i;
        for(int i = 1; i <= cnt; i++)
            dp[0][i] = calc(0, state[i]);
        for(int i = 1; i < n; i++) {
            int t = i & 1;
            for(int j = 1; j <= cnt; j++) {
                for(int k = 1; k <= cnt; k++)
                    if((state[j] & state[k]) == 0)
                        dp[t][k] = std::max(dp[t ^ 1][j] + calc(i, state[k]), dp[t][k]);
            }
        }
        int ans = 0;
        for(int i = 0; i < 2; i++)
            for(int j = 1; j <= cnt; j++)
                ans = std::max(ans, dp[i][j]);
        printf("%d\n", ans);
    }

    return 0;
}