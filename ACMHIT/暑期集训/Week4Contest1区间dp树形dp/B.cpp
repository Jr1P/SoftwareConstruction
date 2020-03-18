#include <cstdio>
#include <cstring>
#define N 205

int n, t;
int color[N], dp[N][N], cnt[N], dup[N], nxt[N];

inline int max(int x, int y) {
    return x>y?x:y;
}

inline int sqr(int x) {
    return x*x;
}

int main() {
    scanf("%d", &t);
    int kase = 0;
    while(t--) {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++) {
            cnt[i] = dup[i] = nxt[i] = 0;
            dp[i][i] = 1;
        }
        for(int i = 1; i <= n; i++) {
            scanf("%d", color+i);
            if(color[i] == color[i-1]) {
                cnt[i] = cnt[i-1]+1;
                dup[i] = dup[i-1]+1; 
            } else {
                cnt[i] = 1;
                dup[i] = 1;
            }
        }
        nxt[n] = n;
        for(int i = n; i > 1; i--)
            if(color[i] == color[i-1])
                nxt[i-1] = nxt[i];
            else nxt[i-1] = i;
        for(int len = 1; len <= n; len++) {
            for(int i = 1; i+len-1 <= len; i++) {
                int j = i+len-1;
                for(int k = 1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k-cnt[k]+1]+dp[nxt[k]][j]+sqr(dup[k]));
            }
        }
        printf("Case %d: %d\n", ++kase, dp[1][n]);
    }
    return 0;
}