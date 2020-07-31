#include <cstdio>
typedef long long ll;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;

ll x[N], y[N], sum[N];
char ch[N];
int n, q;

inline ll pow(ll a, ll b) {
    ll ans = 1ll;
    while(b) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d%d%s", &n, &q, ch + 1);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (ch[i] == '0');
    while(q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%lld\n", ((pow(2ll, r - l + 1) - pow(2ll, sum[r] - sum[l - 1])) % mod + mod) % mod);
    }
    return 0;
}