#include <cstdio>
typedef long long ll;
const ll N = 1e10 + 5;

ll n, k, a, b, nk;
ll mmax = 0, mmin = N;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

inline void work(ll l) {
    if(l <= 0) return ;
    ll g = gcd(l, nk);
    ll ans = nk / g;
    if(ans > mmax) mmax = ans;
    if(ans < mmin) mmin = ans;
}

int main() {
    scanf("%lld%lld%lld%lld", &n, &k, &a, &b);
    ll f1 = a + b, f2 = b - a;
    nk = n * k;
    if(a == b) mmin = 1;
    for(int i = 0; i <= n; i++) {
        ll tmp = k * i;
        work(tmp + f2);
        work(tmp - f2);
        work(tmp + f1);
        work(tmp - f1);
    }
    printf("%lld %lld\n", mmin, mmax);
    return 0;
}