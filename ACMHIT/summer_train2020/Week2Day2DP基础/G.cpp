#include <cstdio>
#include <iostream>
const int INF = 0x3f3f3f3f;
const int N = 505;
const int M = 1e4 + 5;

int w[N], v[N];
int dp[M];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int e, f, n, W;
        scanf("%d%d%d", &e, &f, &n); W = f - e;
        for(int i = 1; i <= W; i++) dp[i] = INF;
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &v[i], &w[i]);
        for(int i = 1; i <= n; i++)
            for(int j = w[i]; j <= W; j++)
                dp[j] = std::min(dp[j], dp[j - w[i]] + v[i]);
        // int mmin = INF;
            // mmin = std::min()
        if(dp[W] == INF)
            puts("This is impossible.");
        else {
            printf("The minimum amount of money in the piggy-bank is %d", dp[W]);
            puts(".");
        }

    }
    return 0;
}