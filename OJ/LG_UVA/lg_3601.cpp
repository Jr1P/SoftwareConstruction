#include <cstdio>
typedef long long ll;
const int N = 1e6 + 5;
const ll mod = 666623333;

ll cnt, prime[N >> 2];
ll phi[N], re[N];
ll l, r;
bool check[N];

void shai() {
    check[1] = true;
    for(int i = 2; i < N; i++) {
        if(!check[i]) {
            prime[++cnt] = i;
            for(ll j = 1ll * i * i; j < N; j += i)
                check[j] = true;
        }
    }
}

void work() {
    for(int i = 1; i <= cnt && prime[i] * prime[i] <= r; i++) {
        ll p = prime[i];
        ll begin = l;
        if(l % p) begin = l / p * p + p;
        for(ll j = begin; j <= r; j += p) {
            phi[j - l] = phi[j - l] / p * (p - 1);
            while(re[j - l] % p == 0) re[j - l] /= p;
        }
    }
}

int main() {
    shai();
    scanf("%lld%lld", &l, &r);
    for(ll i = l; i <= r; i++)
        phi[i - l] = re[i - l] = i;
    ll ans = 0;
    work();
    for(ll i = l; i <= r; i++) {
        if(re[i - l] > 1) phi[i - l] = phi[i - l] / re[i - l] * (re[i - l] - 1);
        ans = (ans + i - phi[i - l]) % mod;
    }
    ans %= mod;
    printf("%lld\n", ans);
    return 0;
}