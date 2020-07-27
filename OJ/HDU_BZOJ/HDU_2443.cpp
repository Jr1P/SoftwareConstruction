#include <cstdio>
const int N = 1e5 + 5;

int t, a, n, s[N], sum[N], sorted[N];
long long ans;

void mergesort(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r)
        if(sum[i] < sum[j])
            ans += r - j + 1, sorted[k++] = sum[i++];
        else sorted[k++] = sum[j++];
    while(i <= mid) sorted[k++] = sum[i++];
    while(j <= r) sorted[k++] = sum[j++];
    for(int i = l; i <= r; i++) sum[i] = sorted[i];
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &a);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &s[i]);
            s[i] -= a;
            sum[i] = sum[i - 1] + s[i];
        }
        ans = 0;
        mergesort(0, n);
        printf("%lld\n", ans);
    }
    return 0;
}