#include <cstdio>
int n;

int main() {
    long long ans = 0L;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        ans += n / i;
    printf("%lld\n", ans);
}