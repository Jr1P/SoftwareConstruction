#include <cstdio>

int n;

int main() {
    scanf("%d", &n);
    int ans = 0;
    for(int i = 3; i <= n; i++)
        ans += (i-1)*i;
    printf("%d\n", ans);
    return 0;
}