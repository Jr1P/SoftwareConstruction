#include <cstdio>
#include <cstring>
#include <cmath>
const int N = 2005;
const int INF = 0x3fffffff;

int n, m, k;
char a[N], b[N];
int dp[N][N];

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
    scanf("%s%s%d", a+1, b+1, &k);
    n = strlen(a+1);
    m = strlen(b+1);
    for(int i = 1; i <= m; i++)
        dp[0][i] = k * i;
    for(int i = 1; i <= n; i++)
        dp[i][0] = k * i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = INF;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = min(dp[i][j], 
                min(min(dp[i][j-1], dp[i-1][j]) + k, dp[i-1][j-1]+abs(a[i]-b[j])));
    printf("%d\n", dp[n][m]);
    return 0;
}