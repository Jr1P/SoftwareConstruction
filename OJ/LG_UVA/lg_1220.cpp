#include <cstdio>
#include <cmath>
#include <cstring>
#define N 55

int n, c;
int dp[N][N][2], a[N], w[N], pl[N];

inline int min(int x, int y) { return x < y ? x : y; }

inline int cal(int i, int j, int l, int r) {
    return abs(pl[j] - pl[i]) * (w[n] - w[r - 1] + w[l]);
}

int main() {
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i++) 
        scanf("%d%d", &pl[i], &a[i]);
    for(int i = 1; i <= n; i++)
        w[i] = w[i - 1] + a[i];
    memset(dp, 127, sizeof(dp));
    dp[c][c][0] = dp[c][c][1] = 0;
    for(int j = c; j <= n; j++)
        for(int i = j - 1; i > 0; i--) {
            dp[i][j][0] = min(dp[i + 1][j][0] + cal(i + 1, i, i, j + 1), dp[i + 1][j][1] + cal(j, i, i, j + 1));
            dp[i][j][1] = min(dp[i][j - 1][1] + cal(j - 1, j, i - 1, j), dp[i][j - 1][0] + cal(i, j, i - 1, j));
        }
    printf("%d\n", min(dp[1][n][0], dp[1][n][1]));
    return 0;
}