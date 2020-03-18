#include <cstdio>

int d, e, n;
int ans = 1e9;

inline int min(int x, int y) { return x < y ? x : y; }

int main() {
    scanf("%d%d%d", &n, &d, &e);
    int a = d;
    int b = e*5;
    for(int y = 0; b*y <= n; y++) {
        ans = min((n-b*y)%a, ans);
    }
    printf("%d\n", ans);
    return 0;
}