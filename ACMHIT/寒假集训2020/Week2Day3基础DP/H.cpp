#include <cstdio>
#include <iostream>
#include <cstring>
#define N 105

int n, m;
int dp[N][N], a[N], b[N];

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        for(int i = 1; i <= m; i++) scanf("%d", b + i);
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= n; i++)
            for(int j = 2; j <= m; j++) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                if(a[i] != b[j]) {
                    int p1, p2;
                    for(p1 = i - 1; a[p1] != b[j] && p1 >= 1; p1--) ;
                    for(p2 = j - 1; b[p2] != a[i] && p2 >= 1; p2--) ;
                    if(p1 && p2)
                        dp[i][j] = std::max(dp[i][j], dp[p1 - 1][p2 - 1] + 2);
                }
            }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
