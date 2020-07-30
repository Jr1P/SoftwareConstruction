#include <cstdio>
#include <cstring>
#include <iostream>
const int INF = 0x1fffffff;

int n;
int dp[10];
char c[100];

int main() {
    scanf("%d", &n);
    for(int i = 0; i <= 8; i++) dp[i] = INF;
    for(int i = 1; i <= n; i++) {
        int cost = 0, money;
        scanf("%d%s", &money, c);
        if(strstr(c, "A"))
            cost++;
        if(strstr(c, "B"))
            cost += 2;
        if(strstr(c, "C"))
            cost += 4;
        if(dp[cost] > money) dp[cost] = money;
    }
    dp[3] = std::min(dp[3], dp[1] + dp[2]);
    dp[5] = std::min(dp[5], dp[1] + dp[4]);
    dp[6] = std::min(dp[6], dp[2] + dp[4]);
    dp[7] = std::min(dp[7], dp[3] + dp[4]);
    dp[7] = std::min(dp[7], dp[5] + dp[2]);
    dp[7] = std::min(dp[7], dp[1] + dp[6]);
    dp[7] = std::min(dp[7], dp[3] + dp[5]);
    dp[7] = std::min(dp[7], dp[3] + dp[6]);
    dp[7] = std::min(dp[7], dp[5] + dp[6]);
    if(dp[7] >= INF) dp[7] = -1;
    printf("%d\n", dp[7]);
    return 0;
}