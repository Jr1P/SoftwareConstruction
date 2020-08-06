#include <cstdio>
#include <iostream>
const int N = 1e4;

int w[N], v[N], mmax;
int dp[N << 1];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d%d", &w[i], &v[i]);
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= w[i]; j--)
            dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]),
            mmax = std::max(dp[j], mmax);
    printf("%d\n", mmax);
    return 0;
}