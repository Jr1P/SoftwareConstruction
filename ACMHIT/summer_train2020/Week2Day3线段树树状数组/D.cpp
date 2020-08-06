#include <cstdio>
#include <cstring>
#include <algorithm>
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int mod = 9901;

int c[N], a[N], b[N];;
int n, d, siz;

inline int lowbit(int x) { return x & (-x); }

inline void insert(int x, int val) {
    for(int i = x; i <= siz; i += lowbit(i))
        c[i] = (c[i] + val) % mod;
}

inline int sum(int k) {
    int ans = 0;
    for(int i = k; i; i -= lowbit(i))
        ans = (ans + c[i]) % mod;
    return ans;
}

int main() {
    while(~scanf("%d%d", &n, &d)) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        memset(c, 0, sizeof(c));
        std::sort(b, b + n);
        siz = std::unique(b, b + n) - b;
        b[siz++] = INF;
        for(int i = 0; i < n; i++) {
            int x = std::lower_bound(b, b + siz, a[i]) - b + 1;
            int l = std::lower_bound (b, b + siz, a[i] - d) - b;
            int r = std::upper_bound(b, b + siz, a[i] + d) - b;
            int tmp = ((sum(r) - sum(l) + 1) % mod + mod) % mod;
            insert(x, tmp);
        }
        int ans = ((sum(siz) - n) % mod + mod) % mod;
        printf("%d\n", ans);
    }
    return 0;
}