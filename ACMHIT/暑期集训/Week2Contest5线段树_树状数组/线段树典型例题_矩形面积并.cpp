#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
const int N = 205, INF = 0x7fffffff;
 
struct Seg {
    double l, r, h;
    int d;
    Seg() {}
    Seg(double l, double r, double h, int d): l(l), r(r), h(h), d(d) {}
    bool operator < (const Seg& a) const {
        return h < a.h;
    }
}a[N];
int n;
int cnt[N << 2];
double sum[N << 2], corx[N];

void push_up(int l, int r, int rt) {
    if(cnt[rt]) sum[rt] = corx[r+1]-corx[l];
    else if(l == r) sum[rt] = 0;
    else sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        cnt[rt] += v;
        push_up(l, r, rt);
        return;
    }
    int mid = (l+r)>>1;
    if(L <= mid) build(L, R, v, lson);
    if(R > mid) build(L, R, v, rson);
    push_up(l, r, rt);
}
 
int main() {
    int kase = 0;
    while(scanf("%d", &n) != EOF) {
        if(!n) break;
        for(int i = 1; i <= n; ++i) {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            a[i] = Seg(x1, x2, y1, 1);
            a[i+n] = Seg(x1, x2, y2, -1);
            corx[i] = x1; corx[i+n] = x2;
        }
        n <<= 1;
        sort(a+1, a+1+n);
        sort(corx+1, corx+1+n);
        int sz = unique(corx+1, corx+1+n)-corx-1;
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        double ans = 0;
        for(int i = 1; i < n; ++i) {
            int l = lower_bound(corx+1, corx+1+sz, a[i].l)-corx;
            int r = lower_bound(corx+1, corx+1+sz, a[i].r)-corx;
            if(l < r) build(l, r-1, a[i].d, 1, sz, 1);
            ans += sum[1]*(a[i+1].h-a[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, ans);
    }
    return 0;
}