#include <cstdio>
#include <cstring>
typedef long long ll;
const ll INF = 1e12;

int n;
ll dp[505][505];
inline ll min(ll x, ll y) { return x < y ? x : y; }

int main() {
    scanf("%d", &n);
    for(int len = 3; len <= n; len++)
        for(int i = 1; i <= n+1-len; i++) {
            int j = i+len-1;
            dp[i][j] = INF;
            for(int k = i+1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+1ll*i*k*j);
        }
    printf("%lld\n", dp[1][n]);
    return 0;
}