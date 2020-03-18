#include <cstdio>
typedef long long ll;

ll n, m;

int main() {
    while(1) {
        scanf("%lld", &n);
        if(!n) break;
        ll ans = 1L, cnt = 0L;
        while(n % 2 == 0) {
            n >>= 1;
            cnt++;
        }
        ans *= cnt + 1;
        cnt = 0L;
        while(n % 3 == 0) {
            n /= 3;
            cnt++;
        }
        ans *= cnt + 1;
        cnt = 0L;
        while(n % 5 == 0) {
            n /= 5;
            cnt++;
        }
        ans *= cnt + 1;
        cnt = 0L;
        while(n % 7 == 0) {
            n /= 7;
            cnt++;
        }
        ans *= cnt + 1;
        printf("%lld\n", ans);
    }
    return 0;
}