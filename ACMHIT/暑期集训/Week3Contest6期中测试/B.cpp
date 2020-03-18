#include <cstdio>
typedef long long ll;
const ll MOD = (long long)998244353;
#define N 200050

ll v, n, w;
ll frac[N];
int t;

inline ll qsm(ll a, ll b) {
    ll ans = (long long)1;
    while(b) {
        if(b&(long long)1) ans = ans*a%MOD;
        a = a*a%MOD;
        b >>= (long long)1;
    }
    return ans;
}

inline ll C(ll n, ll m) {
    ll ans = (long long)1;
    ans = frac[n];
    ans = ans*qsm(frac[m]*frac[n-m]%MOD, MOD-2)%MOD;
    return ans;
}

int main() {
    scanf("%d", &t);
    frac[0] = (long long)1;
    for(ll i = 1; i < N; i++)
        frac[i] = frac[i-1]*i%MOD;
    while(t--) {
        scanf("%lld%lld%lld", &n, &v, &w);
        if((n-1)*v < w) {
           printf("0\n");
           continue;
        }
        ll ans = C(w+v-1, v-1), f = 1;
        for(ll k = 1; k <= w/n; k++) {
            ans = ((ans-(f*C(v, k)*C(w-k*n+v-1, v-1)%MOD)%MOD)+MOD)%MOD;
            f = -f;
        }
        ans = (ans+MOD)%MOD;
        printf("%lld\n", ans);
    }
    return 0;
}