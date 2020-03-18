#include <cstdio>
#include <cstring>
#include <iostream>
#define N 15
#define MAXC 100050

int n, C, sum, year;
int c[N], v[N], dp[MAXC << 3];

inline void init() {
    for(int i = 0; i <= C; i++)
        dp[i] = 0;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &C, &year);
        sum = C;
        C /= 1000;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &c[i], &v[i]);
            c[i] /= 1000;
        }
        while(year--) {
            init();
            for(int i = 1; i <= n; i++)
                for(int j = c[i]; j <= C; j++)
                    dp[j] = std::max(dp[j], dp[j - c[i]] + v[i]);
            sum += dp[C];
            C = sum / 1000;
        }
        printf("%d\n", sum);
    }

    return 0;
}