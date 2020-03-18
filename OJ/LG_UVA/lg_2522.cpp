#include <cstdio>
#include <iostream>
const int N = 5e4+5;
typedef long long ll;

int a, b, c, d, k, tot;
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

ll calc(int n, int m) {
    ll res = 0;
    if(n > m) std::swap(n, m);
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
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
        if(a > b) std::swap(a, b);
        if(c > d) std::swap(c, d);
        if(a % k) {
            a /= k;
            a++;
        } else a /= k;
        if(c % k) {
            c /= k;
            c++;
        } else c /= k;
        b /= k, d /= k;
        printf("%lld\n", calc(b, d) - calc(a - 1, d) - calc(b, c - 1) + calc(a - 1, c - 1));
    }
    return 0;
}