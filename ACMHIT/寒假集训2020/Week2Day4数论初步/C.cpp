#include <cstdio>
#include <cstdlib>
typedef long long ll;

const ll MOD = 1e9+7;
ll n;

inline ll read() {
    ll x = 0;
    char c = getchar();
    if(c == -1) exit(0);
    bool flag = false;
    while(c < '0' || c > '9') {
        if(c == '-') flag = true;
   		c = getchar();
   	}
    while(c >= '0' && c <= '9') {
    	x = ((x << 3) + (x << 1) + (c ^ 48)) % (MOD - 1);
    	c = getchar();
    }
    if(!x)
        x = MOD - 2;
    else
        x--;
    return flag ? -x : x;
}

inline ll qpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int main() {
    while(1) {
        ll mi = read();
        ll ans = qpow(2, mi);
        printf("%lld\n", ans);
    }
    return 0;
}