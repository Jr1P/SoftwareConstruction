#include <cstdio>
#include <cstring>
const int N = 2005;

inline int min(int x, int y) { return x < y ? x : y; }
inline int max(int x, int y) { return x > y ? x : y; }

int n, m;
char a[N], b[N];
int dp[N][N];

int main() {
    scanf("%s%s", a+1, b+1);
    n = strlen(a+1);
    m = strlen(b+1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = 0x3fffffff;
    for(int i = 1; i <= max(n, m); i++)
        dp[i][0] = dp[0][i] = i;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i][j], min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1);
    }
    printf("%d\n", dp[n][m]);
    return 0;
}