#include <cstdio>
#include <algorithm>
const int N = 1e6 + 5;

int a[N], n, q;

int main() {
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while(q--) {
        int x;
        scanf("%d", &x);
        int j = std::lower_bound(a + 1, a + n + 1, x) - a;
        if(a[j] != x) j = -1;
        printf("%d ", j);
    }
    return 0;
}
