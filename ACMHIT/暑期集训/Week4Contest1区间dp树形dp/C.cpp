#include <cstdio>
#include <cstring>
#define N 205

int dp[N][N];
int n;
char s[N];

inline int max(int x, int y) {
    return x>y?x:y;
}

int main() {
    s[1] = 'a';
    while(s[1] != 'e') {
        for(int i = 1; i <= 100; i++) s[i] = '\0';
        scanf("%s", s+1);
        if(s[1] == 'e') break;
        memset(dp, 0 ,sizeof(dp));
        n = strlen(s+1);
        for(int len = 1; len <= n; len++) {
            for(int i = 1; i+len-1 <= n; i++) {
                int j = i+len-1;
                if ((s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']'))
                    dp[i][j] = dp[i+1][j-1]+2;
                for(int k = i; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}