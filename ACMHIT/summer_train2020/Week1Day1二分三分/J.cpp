#include <cstdio>
#include <iostream>
typedef long long ll;
const int N = 1e5 + 5;

ll n, m, ma, h[N];

inline bool check(ll ans) {
    ll cnt = 0;
    for(int i = 1; i <= n; i++)
        cnt += (h[i] > ans) ? h[i] - ans : 0;
    return cnt >= m;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &h[i]);
        ma = std::max(ma, h[i]);
    }
    ll l = 0, r = ma, ans;
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