#include <cstdio>
#include <cstring>
#include <vector>
const int N = 1e5 + 5;
const int MOD = 1e5 + 5;
typedef long long ll;
int inv[N];

inline int gao(int n) {
    if(~inv[n]) return inv[n];
    return inv[n] = (MOD - MOD / n) * gao(MOD % n) % MOD;
}

inline ll power(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int x, y;

ll exgcd(ll a, ll b) {
    if(!b) {
        x = 1; y = 0;
        return a;
    }
    int gcd = exgcd(b, a % b);
    int x2 = x, y2 = y;
    x = y2;
    y = x2 - a / b * y2;
    return gcd;
}

bool check[N];
std::vector<ll> prime;

void ISS(int n) {
    check[1] = true;
    for(int i = 2; i <= n; i++) {
        if(!check[i]) {
            prime.push_back(i);
            for(ll j = i * i; j <= n; j += i)
                check[j] = true;
        }
    }
}

void OSS(int n) {
    
}

int main() {
    memset(inv, -1, sizeof(inv));
    inv[1] = 1;
    // printf("%d\n", gao());
    return 0;
}