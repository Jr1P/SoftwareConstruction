#include <cstdio>
#include <iostream>
typedef long long ll;
const int N = 5e5 + 5;

ll k;
int n, R;
ll sum[N], d[N], a[N];

inline bool check(ll mid) {
    ll add = 0, ans = 0;
    for(int i = 1; i <= n; i++) d[i] = 0;
    for(int i = 1; i <= n; i++) {
        ll tmp = mid - (sum[std::min(n, R + i)] - sum[std::max(0, i - R - 1)] + add + d[i]);
        if(tmp > 0) {
            d[i] += tmp;
            if(i + R * 2 + 1 <= n) d[i + R * 2 + 1] -= tmp;
            ans += tmp;
            if(ans > k) return false;
        }
        add += d[i]; 
    }
    return ans <= k;
}

int main() {
    scanf("%d%d%lld", &n, &R, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    ll l = 0, r = 2LL * 1e18, ans = 0;
    while(l <= r) {
        ll mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%lld\n", ans);
    return 0;
}