#include <cstdio>
#include <cstdlib>
#include <vector>
typedef long long ll;
std::vector<ll > factor;

ll n;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll mul(ll a, ll b, ll mod) {
    ll ans = 0;
    while(b) {
        if(b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod; b >>= 1;
    }
    return ans;
}

ll pow(ll a, ll b, ll mod) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = mul(ans, a, mod);
        a = mul(a, a, mod); b >>= 1;
    }
    return ans;
}

bool Miller_Robin(ll n, int S) {
    if(n == 2) return true;
    if(n < 2 || !(n & 1)) return false;
    ll a, x, y, k = n - 1;
    int t = 0;
    while((k & 1) == 0) t++, k >>= 1;
    for(int i = 0; i < S; i++) {
        a = 1ll * rand() * rand() % (n - 1) + 1;
        x = pow(a, k, n);
        for(int j = 1; j <= t; j++) {
            y = mul(x, x, n);
            if(y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if(x != 1) return false;
    }
    return true;
}

ll Pollard_Rho(ll n, ll r) {
    ll x = 1ll * rand() * rand() % n, y = x, d = 1, k = 2, i = 1;
    while(d == 1) {
        i++;
        x = (mul(x, x, n) + r) % n;
        d = gcd(abs(y - x), n);
        if(i == k) { y = x; k <<= 1; }
    }
    if(d == n) return Pollard_Rho(n, r + 1);
    return d;
}

void fenjie(ll n) {
    if(Miller_Robin(n, 50)) {
        for(ll f : factor) if(f == n) return ;
        factor.push_back(n);
        return ;
    }
    ll p = Pollard_Rho(n, 1ll * rand() * rand() % (n - 1) + 1);
    fenjie(p);
    fenjie(n / p);
}

ll solve() {
    ll ans = n - 1;
    int m = factor.size();
    for(int i = 0; i < (1 << m); i++) {
        ll flag = 0, tmp = 0;
        for(int j = 0; j < m; j++)
            if(i & (1 << j)) {
                tmp += (n - 1) / factor[j];
                flag++;
            }
        if(flag & 1) ans -= tmp;
        else ans += tmp;
    }
    return ans;
}

int main() {
    scanf("%lld", &n);
    fenjie(n);
    printf("%lld\n", solve());
    return 0;
}