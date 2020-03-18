#include <cstdio>
#include <iostream>
#define N 1050

long long n;

int main() {
    scanf("%d", &n);
    while(n--) {
        long long c, sum;
        scanf("%lld%lld", &c, &sum);
        long long cc = sum / c;
        long long rem = sum - cc * c;
        long long ans = rem * (cc+1)*(cc+1) + (c-rem)*cc*cc;
        std::cout << ans << std::endl;
    }    
    return 0;
}