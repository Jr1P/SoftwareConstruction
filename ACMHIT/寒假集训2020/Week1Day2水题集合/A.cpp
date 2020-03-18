#include <cstdio>
#define N 50050

long long sum[N];
long long n, l, len;

int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        long long a;
        scanf("%lld", &a);
        sum[i] = sum[i - 1] + a;
    }
    int q;
    scanf("%d", &q);
    while(q--) {
        scanf("%lld%lld", &l, &len);
        printf("%lld\n", sum[l + len - 1] - sum[l - 1]);
    }

    return 0;
}