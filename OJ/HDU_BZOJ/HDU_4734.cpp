#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a)) 
#define rep(i, a, n) for(int i = (a); i <= (n); i++)
const int N = 5e3 + 5;

int fa;
int dp[10][N], num[10];

inline int f(int x) {
    int bas = 1, ans = 0;
    while(x) {
        int m = x % 10;
        ans += m * bas;
        bas <<= 1;
        x /= 10;
    }
    return ans;
}

int dfs(int pos, int sum, bool limit) {
    if(pos == -1) return sum <= fa;
    if(sum > fa) return 0;
    if(!limit && dp[pos][fa - sum] != -1) return dp[pos][fa - sum];
    int up = limit ? num[pos] : 9;
    int ans = 0;
    for(int i = 0; i <= up; i++)
        ans += dfs(pos - 1, sum + i * (1 << pos), limit && i == num[pos]);
    if(!limit) dp[pos][fa - sum] = ans;
    return ans;
}

int solve(int r) {
    int pos = 0;
    while(r) {
        num[pos++] = r % 10;
        r /= 10;
    }
    return dfs(pos - 1, 0, true);
}

int main() {
    int t;
    scanf("%d", &t);
    mem(dp, -1);
    rep(i, 1, t) {
        int a, r;
        scanf("%d%d", &a, &r);
        fa = f(a);
        printf("Case #%d: %d\n", i, solve(r));
    }
    return 0;
}