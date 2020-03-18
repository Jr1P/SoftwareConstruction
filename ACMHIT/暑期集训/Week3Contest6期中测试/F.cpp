#include <cstdio>
#include <cstring>
#define N 1050
#define INF 0x3f3f3f3fffffffff
typedef long long ll;

ll c[N], ans = 0;
int n, a, b, k;
ll dp[N][N];

inline ll max(ll x, ll y) {
    return x>y?x:y;
}

inline ll calc(int x) {
    ll ans = 0;
    int cnt = 0, day = k;
    while(day) {
        if(x&1) {
            cnt++;
            ans += c[day];
        } else ans -= c[day];
        day--;
        x >>= 1;
    }
    if(cnt >= a && cnt <= b) return ans;
    return -INF;
}

inline bool check(int x) {
    int cnt = 0, tot = 0;
    while(tot < k) {
        if(x&1) cnt++;
        tot++;
        x >>= 1;
    }
    if(cnt >= a && cnt <= b) return true;
    return false;
}

int main() {
    scanf("%d%d%d%d", &n, &k, &a, &b);
    for(int i = 1; i <= n; i++)
        scanf("%lld", c+i);
    for(int i = 0; i < (1<<k); i++) {
        dp[k][i] = calc(i);
    }
    int s = (1<<k)-1;
    for(int i = k; i < n; i++) {
        for(int j = 0; j < (1<<k); j++) {
            if(check(j<<1|1))
                dp[i+1][(j<<1|1)&s] = max(dp[i+1][(j<<1|1)&s], dp[i][j]+c[i+1]);
            else dp[i+1][(j<<1|1)&s] = -INF;
            if(check(j<<1))
                dp[i+1][(j<<1)&s] = max(dp[i+1][(j<<1)&s], dp[i][j]-c[i+1]);
            else dp[i+1][(j<<1)&s] = -INF;
        }
    }
    ll res = 0;
    for(int i = 0; i < (1<<k); i++)
        if(check(i)) res = max(res, dp[n][i]);
    printf("%lld\n", res);
    return 0;
}