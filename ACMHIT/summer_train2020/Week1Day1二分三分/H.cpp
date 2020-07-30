#include <cstdio>
const int N = 1e5;

int pos[N], d[N], n, L, m;

inline bool check(int ans) {
    int l = 0, cnt = 0;
    while(l < n) {
        int i = l + 1, tmp = d[i];
        while(tmp < ans) {
            tmp += d[++i];
            cnt++;
        }
        l = i;
    }
    if(l == n && d[n + 1] < ans) cnt++;
    return cnt <= m;
}

int main() {
    scanf("%d%d%d", &L, &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &pos[i]);
        d[i] = pos[i] - pos[i - 1];
    }
    d[n + 1] = L - pos[n];
    int l = 0, r = L, ans;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d\n", ans);
    return 0;
}