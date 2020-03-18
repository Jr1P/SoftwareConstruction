#include <cstdio>

int n, ans;
int num[105][105], dp[105][105];

inline int max(int x, int y) { return x > y ? x : y; }

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d", &num[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + num[i][j];
            ans = max(dp[i][j], ans);
        }
    printf("%d\n", ans);
    return 0;
}