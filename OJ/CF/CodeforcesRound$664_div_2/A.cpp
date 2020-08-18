#include <cstdio>
#include <cstring>
typedef long long ll;

int n, m;

bool check(ll a) {
    return a % 2 == 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        ll r, g, b, w;
        int cnt = 0;
        scanf("%lld%lld%lld%lld", &r, &g, &b, &w);
        if(check(r)) cnt++;
        if(check(g)) cnt++;
        if(check(b)) cnt++;
        if(check(w)) cnt++;
        if(cnt >= 3) {
            puts("Yes");
            continue;
        }
        if(cnt == 2) {
            puts("No");
            continue;
        }
        if(r == 0 || b == 0 || g == 0) {
            puts("No");
            continue;
        }
        puts("Yes");
        continue;

    }
    return 0;
}