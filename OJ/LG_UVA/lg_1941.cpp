#include <cstdio>
#include <cmath>
#define N 10050
#define M 1050
#define INF 0x3fffffff

int n, m, k, ans, mi = INF;
int dp[N][M], bottom[N], top[N], x[N], y[N];
bool pip[N], flag = false;

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &x[i], &y[i]);
        top[i] = m + 1;
    }
    top[n] = m + 1;
    for(int i = 0; i < k; i++) {
        int p;
        scanf("%d", &p);
        pip[p] = true;
        scanf("%d%d", &bottom[p], &top[p]);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            dp[i][j] = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            if(j > bottom[i] && j < top[i] && dp[i][j] != INF) {
                if(j - y[i] > bottom[i + 1] && j - y[i] < top[i + 1])
                    dp[i + 1][j - y[i]] = min(dp[i][j], dp[i + 1][j - y[i]]);
                dp[i + 1][min(j + x[i], m)] = 
                    min(min(dp[i][j], dp[i + 1][j]) + 1, dp[i + 1][min(j + x[i], m)]);
            } else 
                dp[i + 1][min(j + x[i], m)] = min(dp[i + 1][j] + 1, dp[i + 1][min(j + x[i], m)]);
        }
    }
    for(int i = 0; i <= m; i++) mi = min(mi, dp[n][i]);
    if(mi != INF) printf("1\n%d\n", mi);
    else {
        puts("0");
        int i = n - 1;
        for(; i >= 0; i--) {
            for(int j = bottom[i] + 1; j < top[i]; j++)
                if(dp[i][j] != INF) {
                    flag = true;
                    break;
                }
            if(flag) break;
        }
        for(int j = 0; j <= i; j++)
            if(pip[j]) ans++;
        printf("%d\n", ans);
    }

    return 0;
}