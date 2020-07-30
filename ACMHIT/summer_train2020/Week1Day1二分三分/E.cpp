#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll;
const int N = 5e4 + 5;

ll n, k;
ll a[N], b[N], maxA, maxB, minA, minB;

inline bool check(ll ans) {
    ll cnt = 0;
    for(int i = 1; i <= n; i++) {
        ll ti = ans / a[i];
        if(ans % a[i] == 0)
            cnt += std::lower_bound(b + 1, b + 1 + n, ti) - (b + 1);
        else cnt += std::upper_bound(b + 1, b + 1 + n, ti) - (b + 1);
    }
    return cnt <= k;
}

int main() {
    scanf("%lld%lld", &n, &k);
    k = n * n - k;
    for(int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
        maxA = std::max(maxA, a[i]);
        maxB = std::max(maxB, b[i]);
        minA = std::min(minA, a[i]);
        minB = std::min(minB, b[i]);
    }
    std::sort(a + 1, a + n + 1);
    std::sort(b + 1, b + n + 1);
    // printf("%d\n", std::lower_bound(a + 1, a + 1 + n, 12) - (a + 1));
    ll l = minA * minB, r = maxA * maxB, ans;
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