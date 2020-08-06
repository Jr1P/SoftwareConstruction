#include <cstdio>

int dp[31];

void calc() {
    for(int i = 2; i <= 30; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for(int j = i - 4; j >= 0; j -= 2)
            dp[i] += dp[j] * 2;
    }
}

int main() {
    dp[0] = 1;
    int n;
    calc();
    while(~scanf("%d", &n) && ~n)
        printf("%d\n", dp[n]);
    return 0;
}