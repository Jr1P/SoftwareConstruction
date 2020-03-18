#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long p;
int t;

int check(long long b) {
    long long f = b * b *(long long)3 + b * (long long)3 + (long long)1;
    if(f == p) return -1;
    if(f > p) return 0;
    return 1;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        int f = 0;
        scanf("%lld", &p);
        long long l = 1, r = (long long)sqrt(p);
        while(l < r) {
            long long mid = (l + r) >> 1;
            int d = check(mid);
            if(d == -1) {
                f = 1;
                puts("YES");
                break;
            }
            if(d == 0) r = mid - 1;
            else l = mid + 1;
        }
        if(f == 1) continue;
        if(check(l) != -1) puts("NO");
        else puts("YES");
    }
    return 0;
}