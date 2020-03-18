#include <cstdio>
#include <cstring>
#include <iostream>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define drep(i, n, a) for(int i = n; i >= a; i--)

typedef long long ll;
ll a, b;
ll dp[20][163][163][2], num[20];

ll dfs(int pos, int sum, int val, int mod, bool limit) {
    if(pos == -1) return sum == 0 && val == 0;
    if(dp[pos][sum][val][limit] != -1) return dp[pos][sum][val][limit];
    int up = limit ? num[pos] : 9;
    ll ans = 0L;
    for(int i = 0; i <= up; i++) {
        if(sum - i < 0) break;
        ans += dfs(pos - 1, sum - i, (val * 10 + i) % mod, mod, limit && i == num[pos]);
    }
    return dp[pos][sum][val][limit] = ans;
}

ll solve(ll r) {
    int pos = 0;
    while(r) {
        num[pos++] = r % 10;
        r /= 10;
    }
    ll ans = 0L;
    for(int i = 1; i <= pos * 9; i++) {
        memset(dp, -1, sizeof(dp));
        ans += dfs(pos - 1, i, 0, i, true);
    }
    return ans;
}

int main() {
    while(~scanf("%lld%lld", &a, &b))
        printf("%lld\n", solve(b) - solve(a - 1));
    return 0;
}