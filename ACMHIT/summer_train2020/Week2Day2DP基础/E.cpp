#include <cstdio>
#include <iostream>
#include <cstring>
const int N = 5e3+ 5;

int n, a, b;
int dp[N], suf[N][N];
char ch[N];

int main() {
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", ch + 1);
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            suf[i][j] = ch[i] == ch[j] ? suf[i - 1][j - 1] + 1 : 0;
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + a;
        for(int j = 1; j < i; j++) {
            int tmp = std::min(i - j, suf[j][i]);
            if(tmp) dp[i] = std::min(dp[i], dp[i - tmp] + b);
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}