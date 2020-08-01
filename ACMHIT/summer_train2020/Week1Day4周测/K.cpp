#include <cstdio>
#include <iostream>
#include <algorithm>
const int N = 1e5 + 5;
const int INF = 0x7fffffff;

int n, sum;
int x[N];

bool check(int mid) {
    int cnt = 0;
    for(int i = 1; i < n; i++) {
        int t = x[i] + mid;
        int j = std::lower_bound(x + i + 1, x + n + 1, t) - (x + i + 1);
        cnt += j;
    }
    return cnt < sum;
}

int main() {
    while(~scanf("%d", &n)) {
        int mmin, mmax;
        sum = n * (n - 1) / 2;
        if(sum & 1) sum = sum / 2 + 1;
        else sum /= 2;
        for(int i = 1; i <= n; i++)
            scanf("%d", &x[i]);
        std::sort(x + 1, x + n + 1);
        mmax = x[n] - x[1];
        for(int i = 1; i < n; i++)
            mmin = std::min(mmin, x[i + 1] - x[i]);
        int l = mmin, r = mmax, ans;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(check(mid)) {
                l = mid + 1;
                ans = mid;
            } else r = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}