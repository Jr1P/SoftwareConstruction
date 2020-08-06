#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;
const int N = 105;
const int M = 5555;

ll dp[2][N][M];
ll a[N], b[N], c[N];
int n, t;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
        ll ans = a[n];
        memset(dp, -1, sizeof(dp));
        dp[0][1][n] = a[n];
        int t = 1, lt = 0;
        for(int i = n - 1; i; i--) {
            memset(dp[t], -1, sizeof(dp[t]));
            for(int j = 1; j <= n - i + 1; j++)
                for(int k = n; k <= (n + i) * (n - i + 1) / 2; k++) {
                    if(dp[lt][j - 1][k - i] != -1) dp[t][j][k] = std::max(dp[t][j][k], dp[lt][j - 1][k - i] + a[i]);
                    if(dp[lt][j][k] != -1) {
                        dp[t][j][k] = std::max(dp[t][j][k], dp[lt][j][k] + c[i] * j);
                        dp[t][j][k] = std::max(dp[t][j][k], dp[lt][j][k] + 1ll * (k - i * j) * b[i]);
                    }
                    ans = std::max(ans, dp[t][j][k]);
                }
            lt = t;
            t ^= 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}