#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;

const int N = 5e5 + 5;
int n, m;
ll a[N], b[N], c[N];
ll sum1[N], sum2[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    for(int i = 1; i < n; i++) {
        ll max = b[i];
        ll re = max;
        int j = i + 1;
        while(j <= n) {
            re -= c[j];
            if(re <= 0) break;
            if(re >= b[j]) {
                re -= b[j];
                max -= re;
                break;
            }
            j++;
        }
        sum1[i] = max;
    }
    for(int i = n; i > 1; i--) {
        ll max = a[i];
        ll re = max;
        int j = i - 1;
        while(j >= 1) {
            re -= c[j];
            if(re <= 0L) break;
            if(re >= a[j]) {
                re -= a[j];
                max -= re;
                break;
            }
            j--;
        }
        sum2[i] = max;
    }
    ll ans = 0L;
    for(int i = 1; i <= n; i++)
        ans = std::max(c[i] + sum1[i] + sum2[i], ans);
    printf("%lld\n", ans);
    return 0;
}