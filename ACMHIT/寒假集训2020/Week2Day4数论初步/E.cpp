#include <cstdio>

typedef long long ll;
const ll MOD = 9973;
ll n, b;
int t;

inline ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%lld%lld", &n, &b);
        printf("%lld\n", n * qpow(b, MOD - 2) % MOD);
    }
    return 0;
}