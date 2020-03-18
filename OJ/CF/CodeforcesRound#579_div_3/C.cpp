#include <cstdio>
typedef long long ll;
#define N 500050

ll a, b;
int n, tot, prime[N];
bool check[N<<4+5];

inline ll gcd(ll x, ll y) {
    return x%y == 0? y: gcd(y, x%y);
}

int main() {
    scanf("%d", &n);
    ll g;
    if(n == 1) {
        scanf("%I64d", &a);
        g = a;
    } else {
        scanf("%I64d%I64d", &a, &b);
        g = gcd(a, b);
        for(int i = 1; i <= n-2; i++) {
            scanf("%I64d", &a);
            g = gcd(g, a);
            if(g == 1) {
                printf("1\n");
                return 0;
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i*i <= g; i++)
        if(g % i == 0 && i*i != g) ans += 2;
        else if(g%i == 0) ans++;
    
    printf("%I64d\n", ans);
    return 0;
}