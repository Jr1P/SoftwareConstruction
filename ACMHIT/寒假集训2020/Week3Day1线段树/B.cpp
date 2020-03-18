#include <algorithm>
#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
#define ls (k << 1)
#define rs (k << 1 | 1)
#define rep(i, a, n) for(int i = a; i <= n; i++)
const int N = 205;
 
struct Seg {
    double l, r, h;
    int d;
    Seg() {}
    Seg(double l, double r, double h, int d): l(l), r(r), h(h), d(d) {}
    bool operator < (const Seg& se) const {
        return h < se.h;
    }
} seg[N];

int n, L, R;
int cnt[N << 2];
double sum[N << 2], corx[N];

inline void update(int l, int r, int k) {
    if(cnt[k]) sum[k] = corx[r + 1] - corx[l];
    else if(l == r) sum[k] = 0;
    else sum[k] = sum[ls] + sum[rs];
}

void build(int d, int l, int r, int k) {
    if(L <= l && r <= R) {
        cnt[k] += d;
        update(l, r, k);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) build(d, l, mid, ls);
    if(R > mid) build(d, mid + 1, r, rs);
    update(l, r, k);
}
 
int main() {
    int kase = 0;
    while(~scanf("%d", &n)) {
        if(!n) break;
        rep(i, 1, n) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[i] = Seg(x1, x2, y1, 1);
            seg[i + n] = Seg(x1, x2, y2, -1);
            corx[i] = x1; corx[i + n] = x2;
        }
        n <<= 1;
        mem(cnt, 0); mem(sum, 0);
        std::sort(seg + 1, seg + 1 + n);
        std::sort(corx + 1, corx + 1 + n);
        int sz = std::unique(corx + 1, corx + 1 + n) - corx - 1;
        double ans = 0;
        rep(i, 1, n - 1) {
            int l = std::lower_bound(corx + 1, corx + 1 + sz, seg[i].l) - corx;
            int r = std::lower_bound(corx + 1, corx + 1 + sz, seg[i].r) - corx;
            L = l, R = r - 1;
            if(l < r) build(seg[i].d, 1, sz, 1);
            ans += sum[1] * (seg[i + 1].h - seg[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, ans);
    }
    return 0;
}