#include <cstdio>
#include <iostream>
typedef long long ll;
int t;

inline ll gcd(ll a, ll b) {
    return (a % b == 0) ? b: gcd(b, a % b);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        ll r, b, k;
        std::cin >> r >> b >> k;
        if(r < b) std::swap(r, b);
        ll g = gcd(r, b);
        ll lcm = r * b / g, cn = r / b;
        ll lcnb = lcm / b, lcnr = lcm / r;
        lcnb--;
        if(r % b == 0) cn--;
        if(cn >= k) puts("REBEL");
        else if(lcnb / lcnr >= k) puts("REBEL");
        else if(lcnb / lcnr == k-1 && lcnb % lcnr) puts("REBEL");
        else puts("OBEY");
    }
    return 0;
}