#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;

ll n, ans = 1;


inline ll euler(ll x) {
    ll res = x;
    for(register ll i = 2; i*i <= x; i++)
        if(x % i == 0) {
             res = res / i * (i - 1);
             while(x % i == 0) x /= i;
        }
    if(x > 1) res = res / x * (x - 1);
    return res;
}

int main() {
    ans = 1;
    scanf("%lld", &n);

    printf("%lld\n", euler(n));
    return 0;
}