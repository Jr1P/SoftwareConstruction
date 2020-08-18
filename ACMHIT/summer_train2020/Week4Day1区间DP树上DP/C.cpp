#include <cstdio>
#include <algorithm>
#include <cstring>
const int N = 1005;
const int INF = 0x3fffffff;

int n, l, a[N];
int dp[N][N][2], s[N][N][2];

inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

signed main() {
    while(~scanf("%d%d", &n, &l)) {
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        a[++n] = l;
        std::sort(a+1, a+n+1);
        int pos = std::lower_bound(a+1, a+n+1, l)-a;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dp[i][j][0] = dp[i][j][1] = INF;
        dp[pos][pos][0] = dp[pos][pos][1] = 0;
        for(int i = pos; i; i--) {
            for(int j = pos; j <= n; j++) {
                if(i == j) continue;
                int k = n-j+i;
                dp[i][j][0] = min(dp[i+1][j][0]+(a[i+1]-a[i])*k, dp[i+1][j][1]+(a[j]-a[i])*k);
                dp[i][j][1] = min(dp[i][j-1][0]+(a[j]-a[i])*k, dp[i][j-1][1]+(a[j]-a[j-1])*k);
            }
        }
        printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
    }
    return 0;
}