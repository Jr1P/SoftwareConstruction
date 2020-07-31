#include <cstdio>
typedef long long ll;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

inline ll exgcd(ll a, ll b, ll &x0, ll &y0) {
    if(!b) {
        x0 = 1, y0 = 0;
        return a;
    }
    ll gcd = exgcd(b, a % b, x0, y0);
    ll tmp = y0; 
    y0 = x0 - a / b * y0;
    x0 = tmp;
    return gcd;
}

int main() {
    ll x, y, m, n, l;
    while(~scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l)) {
        ll a = m - n, b = y - x;
        if(a == 0) {
            puts("Impossible");
            continue;
        }
        if(a < 0) a = -a, b = -b;
        while(b < 0) b += l;
        if(b % gcd(a, l) != 0) {
            puts("Impossible");
            continue;
        }
        ll x0, y0, t = b / gcd(a, l);
        ll mod = l / gcd(a, l);
        // a /= t; l /= t;
        exgcd(a, l, x0, y0);
        x0 *= t;
        x0 = (x0 % mod + mod) % mod;
        printf("%lld\n", x0);
    }
    return 0;
}