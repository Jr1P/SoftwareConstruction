#include <cstdio>
#include <iostream>
const int N = 1e7 + 5;
typedef long long ll;

int tot;
int mu[N], prime[N >> 2];
ll g[N], sum[N];
bool check[N];

void get_mu(int n) {
    mu[1] = 1; check[1] = true;
    for(ll i = 2; i <= n; i++) {
        if(!check[i])
            mu[i] = -1, prime[++tot] = i;
        for(int j = 1; j <= tot && i * prime[j] <= n; j++) {
            check[i * prime[j]] = true;
            if(i % prime[j]) mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    for(int i = 1; i <= tot; i++)
        for(int j = 1; j * prime[i] <= n; j++)
            g[j * prime[i]] += (ll)mu[j];
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + g[i];
}

inline int min(int x, int y) { return x < y ? x : y; }

ll calc(int n, int m) {
    ll res = 0L;
    for(int l = 1, r = 0; l <= n; l = r + 1) {
        r = min(n / (n / l), m / (m / l));
        res += (sum[r] - sum[l - 1]) * (n / l) * (m / l);
    }
    return res;
}

int main() {
    get_mu(N - 5);
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if(n > m) std::swap(n, m);
        printf("%lld\n", calc(n, m));
    }
    return 0;
}