#include <cstdio>

int n, l, r;

int main() {
    scanf("%d%d%d", &n, &l, &r);
    int min = n-l+(1<<l)-1;
    int max = (n-r)*(1<<(r-1))+(1<<r)-1;
    printf("%d %d\n", min, max);
    return 0;
}