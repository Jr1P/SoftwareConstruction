#include <cstdio>
#include <cstring>
const int N = 105;

int n, m;
int dp[N][N];
char s[N];

inline int max(int x, int y) { return x > y ? x : y; }

int main() {
    while(~scanf("%s", s+1)) {
        memset(dp, 0, sizeof(dp));
        if(s[1] == 'e') break;
        n = strlen(s+1);
        for(int i = n-1; i; i--)
            for(int j = i+1; j <= n; j++) {
                dp[i][j] = dp[i+1][j];
                for(int k = i+1; k <= j; k++) {
                    if((s[i] == '(' && s[k] == ')') || (s[i] == '[' && s[k] == ']'))
                        dp[i][j] = max(dp[i][j], dp[i+1][k-1]+dp[k+1][j]+2);
                }
            }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}