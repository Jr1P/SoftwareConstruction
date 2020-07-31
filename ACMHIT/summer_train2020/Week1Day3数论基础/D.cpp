#include <cstdio>
#include <vector>
typedef long long ll;
std::vector<ll> prime;

void fenjie(ll n) {
    for(ll i = 2; i * i <= n; i++)
        if(n % i == 0) {
            prime.push_back(i);
            while(n % i == 0) n /= i;
        }
    if(n != 1) prime.push_back(n);
}

ll calc(ll x) {
    ll ans = 0;
    for(int i = 1; i < (1 << prime.size()); i++) {
        ll q = 1, f = 0;
        for(int j = 1, pos = 0; j <= i; j <<= 1, pos++) {
            if(i & j) {
                q *= prime[pos];
                f++;
            }
        }
        if(f & 1) ans += x / q;
        else ans -= x / q;
    }
    return x - ans;
}

int main() {
    int t, kase = 1;
    scanf("%d", &t);
    while(t--) {
        ll a, b, n;
        scanf("%lld%lld%lld", &a, &b, &n);
        prime.clear();
        fenjie(n);
        printf("Case #%d: %lld\n", kase++, calc(b) - calc(a - 1));
    }
    return 0;
}