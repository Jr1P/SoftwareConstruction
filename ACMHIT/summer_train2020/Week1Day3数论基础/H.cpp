#include <cstdio>
typedef long long ll;
const int N = 25;
const ll mod = 1e9 + 7;

ll f[N], frac[N];
ll n, s;

ll pow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return ans;
}

ll C(ll n, ll m) {
    ll ans = 1;
    if(n < m || n < 0 || m < 0) return 0;
    // if(n % mod == 0 || m == 0) return 1;
    for(ll i = n; i >= n - m + 1; i--)
        ans = ans * (i % mod) % mod;
    return ans * pow(frac[m], mod - 2) % mod;
}

ll calc() {
    ll p = s + n - 1;
    ll ans = C(p, n - 1) % mod;
    for(int i = 1; i < (1 << n); i++) {
        ll sum = p, flag = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sum -= f[j + 1];
                flag++;
            }
        }
        if(flag & 1) ans = ((ans - C(sum - flag, n - 1)) % mod + mod) % mod;
        else ans = (ans + C(sum - flag, n - 1)) % mod;
    }
    return (ans + mod) % mod;
}

int main() {
    frac[0] = 1;
    for(ll i = 1; i <= 20; i++) frac[i] = frac[i - 1] * i % mod;
    scanf("%lld%lld", &n, &s);
    for(int i = 1; i <= n; i++)
        scanf("%lld", &f[i]);
    printf("%lld\n", calc());
    return 0;
}