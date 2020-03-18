#include <cstdio>
#include <algorithm>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 1e4 + 5;

struct Seg {
    int l, r, h, d;
    Seg() {}
    Seg(int l, int r, int h, int d) : l(l), r(r), h(h), d(d) {}
    inline bool operator < (const Seg& a) const {
        return h < a.h;
    }
}seg[N];

struct Node {
    int l, r, sum, cnt, num;
    bool li, ri;
    Node() {}
    Node(int l, int r, int sum=0, int cnt=0, int num=0, bool li=false, bool ri=false)
        : l(l), r(r), sum(sum), cnt(cnt), num(num), li(li), ri(ri) {}
    inline bool leaf() { return l == r; }
}node[N << 2];

inline int abs(int x) { return x >= 0 ? x : -x; }

int n, d, x, y;
int corx[N];

void update(int k) {
    if(node[k].cnt) {
        node[k].sum = corx[node[k].r + 1] - corx[node[k].l];
        node[k].li = node[k].ri = true;
        node[k].num = 1;
    } else if(node[k].leaf()) {
        node[k].sum = node[k].num = 0;
        node[k].li = node[k].ri = false;
    }
    else {
        node[k].sum = node[ls].sum + node[rs].sum;
        node[k].li = node[ls].li; node[k].ri = node[rs].ri;
        node[k].num = node[ls].num + node[rs].num - (node[ls].ri && node[rs].li);
    }
}

void build(int l, int r, int k) {
    node[k] = Node(l, r);
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
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
    while(~scanf("%d", &n)) {
        for(int i = 1; i <= n; i++) {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            seg[i] = Seg(x1, x2, y1, 1);
            seg[i + n] = Seg(x1, x2, y2, -1);
            corx[i] = x1; corx[i + n] = x2;
        }
        n <<= 1;
        std::sort(corx + 1, corx + n + 1);
        std::sort(seg + 1, seg + n + 1);
        int sz = std::unique(corx + 1, corx + n + 1) - corx - 1;
        int ans = 0, last = 0;
        seg[n + 1].h = seg[n].h;
        build(1, sz, 1);
        for(int i = 1; i <= n; i++) {
            x = std::lower_bound(corx + 1, corx + sz + 1, seg[i].l) - corx;
            y = std::lower_bound(corx + 1, corx + sz + 1, seg[i].r) - corx - 1;
            d = seg[i].d;
            work(1);
            ans += node[1].num * 2 * (seg[i + 1].h - seg[i].h) + abs(node[1].sum - last);
            last = node[1].sum;
        }
        printf("%d\n", ans);
    }
    return 0;
}