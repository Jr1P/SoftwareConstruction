#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

const int N = 10055;

int n, m, ans;
int c[N], dp[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        dp[i] = 0;
    for(int i = 1; i <= n; i++) {
        int pre;
        scanf("%d%d", &c[i], &pre);
        int tmp = 0;
        for(int j = 1; j <= pre; j++) {
            int u;
            scanf("%d", &u);
            tmp = std::max(tmp, dp[u]);
        }
        dp[i] = tmp + c[i];
        ans = std::max(dp[i],ans);
    }
    printf("%d\n", ans);
    return 0;
}