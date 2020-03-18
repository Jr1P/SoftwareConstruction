#include <cstdio>
#include <algorithm>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 205;

struct Seg {
    double l, r, h;
    int d;
    Seg() {}
    Seg(double l, double r, double h, int d) : l(l), r(r), h(h), d(d) {}
    bool operator < (const Seg &a) const {
        return h < a.h;
    }
}seg[N];

struct Node {
    int l, r, cnt;
    double sum;
    Node() {}
    Node(int l, int r, int cnt=0, int sum=0) : l(l), r(r), cnt(cnt), sum(sum) {}
}node[N << 2];

int n, x, y, d;
double corx[N];

void build(int l, int r, int k) {
    node[k] = Node(l, r);
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
}

void update(int k) {
    if(node[k].cnt) node[k].sum = corx[node[k].r + 1] - corx[node[k].l];
    else if(node[k].l == node[k].r) node[k].sum = 0;
    else node[k].sum = node[ls].sum + node[rs].sum;
}

void work(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        node[k].cnt += d;
        update(k);
        return ;
    }
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) work(ls);
    if(y > mid) work(rs);
    update(k);
}

int main() {
    int kase = 0;
    while(~scanf("%d", &n)) {
        if(!n) break;
        for(int i = 1; i <= n; i++) {
            double x1, x2, y1, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            corx[i] = x1; corx[n + i] = x2;
            seg[i] = Seg(x1, x2, y1, 1);
            seg[i + n] = Seg(x1, x2, y2, -1);
        }
        n <<= 1;
        std::sort(corx + 1, corx + n + 1);
        std::sort(seg + 1, seg + n + 1);
        int sz = std::unique(corx + 1, corx + n + 1) - corx - 1;
        double ans = 0;
        build(1, sz - 1, 1);
        for(int i = 1; i < n; i++) {
            x = std::lower_bound(corx + 1, corx + sz + 1, seg[i].l) - corx;
            y = std::lower_bound(corx + 1, corx + sz + 1, seg[i].r) - corx - 1;
            d = seg[i].d;
            work(1);
            ans += (seg[i + 1].h - seg[i].h) * node[1].sum;
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", ++kase, ans);
    }
    return 0;
}