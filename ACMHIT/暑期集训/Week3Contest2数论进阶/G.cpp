#include <cstdio>
typedef long long ll;
#define N 10000000

ll prime[N/20], f[N+5], frac[N+5];
bool check[N+5];
ll n, m, tot, R;
int t;

ll qsm(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b&1) ans = ans*a%R;
        a = a*a%R;
        b >>= 1;
    }
    return ans;
}

void shai(){
    check[1] = true;
    for(ll i = 2; i <= N; i++) {
        if(!check[i])
            prime[++tot] = i;
        for(int j = 1; j <= tot && i*prime[j] <= N; j++) {
            check[i*prime[j]] = true;
            if(i%prime[j] == 0)
                break;
        }
    }
    f[0] = 1; frac[0] = 1;
    for(ll i = 1; i <= N; i++) {
        f[i] = f[i-1]*(check[i]? i: i-1)%R;
        frac[i] = frac[i-1]*i%R;
    }
}

int main() {
    scanf("%d%lld", &t, &R);
    shai();
    while(t--) {
        scanf("%lld%lld", &n, &m);
        ll ans = (f[m]*frac[n]%R)*qsm(frac[m], R-2)%R;
        printf("%lld\n", ans);
    }

    return 0;
}