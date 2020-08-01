#include <cstdio>
typedef long long ll;
const ll mod = 1e9 + 9;
const int K = 1e5 + 5;

// ll exgcd(ll a, ll b, ll &x, ll &y) {
//     if(!b) {
//         x = 1L; y = 0L;
//         return a;
//     }
//     ll gcd = exgcd(b, a % b, x, y);
//     ll tmp = y;
//     y = x - a / b * y;
//     x = tmp;
//     return gcd;
// }

inline ll pow(ll a, ll b) {
    ll ans = 1ll;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return (ans % mod + mod) % mod;;
}

ll inv(ll x) {
    // ll x0, y0;
    // ll gcd = exgcd(x, mod, x0, y0);
    return pow(x, mod - 2);
}

int main() {
    ll n, a, b, k;
    char ch[K];
    scanf("%lld%lld%lld%lld%s", &n, &a, &b, &k, ch);
    ll sum = 0;
    for(int i = 0; ch[i]; i++)
        sum = (sum + (ch[i] == '+' ? 1ll : -1ll) * (pow(a, n - i) * pow(b, i) % mod)) % mod;
    sum = (sum + mod) % mod;
    ll m = pow(b, k) * pow(inv(a), k) % mod;
    ll ans;
    if(m == 1)
        ans = sum * (n + 1) / k % mod;
    else
        ans = (sum * (pow(m, (n + 1) / k) - 1) % mod * inv(m - 1) % mod + mod) % mod;
    printf("%lld\n", ans);
    return 0;
}