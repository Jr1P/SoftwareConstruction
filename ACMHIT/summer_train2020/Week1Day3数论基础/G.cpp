#include <cstdio>
typedef long long ll;

bool check(ll q) {
    for(ll i = 3; i * i <= q; i += 2)
        if(q % i == 0) return false;
    return true;
}

inline ll mul(ll a, ll b, ll p) {
    ll ans = 0;
    while(b) {
        if(b & 1) ans = (ans + a) % p;
        a = (a + a) % p; b >>= 1;
    }
    return ans;
}

inline ll pow(ll a, ll b, ll p) {
    ll ans = 1LL;
    while(b) {
        if(b & 1) ans = mul(ans, a, p);
        a = mul(a, a, p); b >>= 1;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll p;
        scanf("%lld", &p);
        ll q = p - 2;
        for(; !check(q); q -= 2) ;
        ll fac = 1;
        for(ll i = q + 1; i < p - 1; i++)
            fac = mul(fac, i, p);
        printf("%lld\n", pow(fac, p - 2, p));
    }
}