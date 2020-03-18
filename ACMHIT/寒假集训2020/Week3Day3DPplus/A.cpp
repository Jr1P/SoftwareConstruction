#include <cstdio>
#include <cstring>
#include <iostream>
const int N = 105;

int n, q, t;
int d[N], cost[N], dp[N][N];

int main() {
    while(~scanf("%d%d%d", &n, &t, &q)) {
        if(n == 0) break;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &cost[i], &d[i]);
        cost[0] = 0; d[0] = 1;
        int maxt = 100 / q;
        if(100 % q) maxt++;
        for(int i = 1; i <= maxt; i++)
            for(int j = 0; j <= n; j++)
                for(int k = t; k <= std::min(100 - cost[j] + t, 100); k++) {
                    dp[i][k] = std::max(dp[i][k], dp[i - 1][k + cost[j] - t] + d[j]);
                }
        bool f = false;
        for(int i = 1; i <= maxt; i++) {
            for(int k = 0; k <= 100; k++)
                if(dp[i][k] >= 100) {
                    f = true;
                    break;
                }
            if(f) {
                printf("%d\n", i);
                break;
            }
        }
        if(!f) puts("My god");
    }
    return 0;
}