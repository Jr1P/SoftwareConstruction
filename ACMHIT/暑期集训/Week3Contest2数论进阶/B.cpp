#include <cstdio>
typedef long long ll;

ll n, k;

int main() {
    scanf("%lld%lld", &n, &k);
    ll ans = 0;
    if(n > k) {
        ans = k*(n-k);
        n = k;
    }
    ll res = 0;
    for(int i = 1; i <= n; i = res+1) {
        ll cnt = k/i;
        res = k/cnt;
        if(res >= n) res = n;
        ans += (res-i+1)*k-(res-i+1)*(res+i)/2*cnt;
    }
    printf("%lld\n", ans);
    return 0;
}