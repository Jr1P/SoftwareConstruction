#include <cstdio>
#include <iostream>
const int N = 5e4+5;
typedef long long ll;

int n, m, d, tot;
int prime[N >> 1], mu[N];
ll sum[N];
bool check[N];

inline int min(int x, int y) { return x < y ? x : y; }

void get_mu(int n) {
    mu[1] = 1; check[1] = true;
    for(int i = 2; i <= n; i++) {
        if(!check[i])
            prime[++tot] = i, mu[i] = -1;
        for(int j = 1; j <= tot && i * prime[j] <= n; j++) {
			check[i * prime[j]] = 1;
            if(i % prime[j]) mu[i * prime[j]] = -mu[i];
            else {
                mu[i * prime[j]] = 0;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + mu[i];
}

ll calc() {
    ll res = 0;
    for(int l = 1, r = 0; l <= n; l = r + 1) {
        r = min((n / (n / l)), (m / (m / l)));
        res += (sum[r] -  sum[l - 1]) * (n / l) * (m / l);
    }
    return res;
}

int main() {
    int t; scanf("%d", &t);
    get_mu(N - 5);
    while(t--) {
        scanf("%d%d%d", &n, &m, &d);
        if(n > m) std::swap(n, m);
        n /= d, m /= d;
        printf("%lld\n", calc());
    }
    return 0;
}