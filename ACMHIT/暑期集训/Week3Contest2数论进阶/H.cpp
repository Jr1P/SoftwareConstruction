#include <cstdio>
typedef long long ll;

ll a, b, c, k;
ll x, y;

ll exgcd(ll a, ll b, ll& x, ll& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a%b, x, y);
	ll x2 = x, y2 = y;
	x = y2;
	y = x2-(a/b)*y2;
	return gcd;
}

int main() {
    while(1) {
        scanf("%lld%lld%lld%lld", &a, &b, &c, &k);
        if(a == 0 && b == 0 && c == 0 && k == 0) break;
        k = (long long)1<<k;
        ll p = b-a;
        //if(p < 0) p += k;
        if(p == 0) {
            puts("0");
            continue;
        }
        ll gcd = exgcd(c, k, x, y);
        if(p % gcd == 0) {
            x = x*p/gcd%k;
            x = (x%(k/gcd)+k/gcd)%(k/gcd);
            printf("%lld\n", x);
        } else printf("FOREVER\n");
    }
    return 0;
}