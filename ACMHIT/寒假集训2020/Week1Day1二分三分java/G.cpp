#include <cstdio>
#include <algorithm>
#define N 1000050

int n, k;
int a[N];

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]); 
        std::sort(a + 1, a + n + 1);
        k = (n * (n - 1) >> 1) + 1;
        k >>= 1;
        int l = 0, r = a[n], cnt = 0, mid;
        while (l < r) {
            if (l == r - 1) break;
            cnt = 0;
            mid = (l + r) >> 1;
            for (int i = 2; i <= n; i++) {
                if (a[i] - mid <= 0)
                    cnt += (i - 1);
                else
                    cnt += i - (std::lower_bound(a + 1, a + 1 + n, a[i] - mid) - a);
            }
            if (cnt >= k) r = mid;
            else l = mid;
        }
        cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (a[i] - l <= 0)
                cnt += i - 1;
            else
                cnt += i - (std::lower_bound(a + 1, a + 1 + n, a[i] - l) - a);
        }
        if (cnt < k) l = r;
        printf("%d\n", l);
    }
    return 0;
}