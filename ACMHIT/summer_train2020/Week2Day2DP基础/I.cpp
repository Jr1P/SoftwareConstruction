#include <cstdio>
#include <iostream>

const int N = 105;

int n, mmax;
int dp[N][N], a[N][N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j],
            mmax = std::max(dp[i][j], mmax);
    printf("%d\n", mmax);
    return 0;
}