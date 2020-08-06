#include <cstdio>
#include <algorithm>
const int N = 1e6 + 5;

int n, m, ans;
int num[N];
int dp[N][3][3];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        num[a]++;
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= m; i++)
        for(int l = 0; l < 3; l++)
            for(int j = 0; j < 3; j++)
                for(int k = 0; k < 3 && l + j + k <= num[i]; k++)
                    dp[i][j][k] = std::max(dp[i][j][k], dp[i - 1][l][j] + k + (num[i] - j - k - l) / 3);
    printf("%d\n", dp[m][0][0]);
    return 0;
}