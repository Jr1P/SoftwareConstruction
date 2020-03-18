#include <cstdio>
#include <algorithm>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 20005;

struct Node {
    int l, r, sum, cnt;
    Node() {}
    Node(int l, int r, int sum=0, int cnt=0) : l(l), r(r), sum(sum), cnt(cnt) {}
    inline bool leaf() { return l == r; }
}node[N << 2];

struct Seg {
    int l, r, h, d;
    Seg() {}
    Seg(int l, int r, int h, int d) : l(l), r(r), h(h), d(d){}
    inline bool operator < (const Seg &a) const {
        return h < a.h;
    }
}seg[N];

int corx[N];
int n, x, y, d;

inline void update(int k) {
    if(node[k].cnt) node[k].sum = corx[node[k].r + 1] - corx[node[k].l];
    else if(node[k].leaf()) node[k].sum = 0;
    else node[k].sum = node[ls].sum + node[rs].sum;
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
    bool f = false;
    while(1) {
        int x1, x2, y1, y2;
        n = 0;
        while(scanf("%d%d%d%d", &x1, &y1, &x2, &y2)) {
            if(x1 < 0) {
                if(x1 == -2)
                    f = true;
                break;
            }
            if(x1 > x2) std::swap(x1, x2);
            if(y1 > y2) std::swap(y1, y2);
            seg[++n] = Seg(x1, x2, y1, 1);
            corx[n] = x1;
            seg[++n] = Seg(x1, x2, y2, -1);
            corx[n] = x2;
        }
        std::sort(corx + 1, corx + n + 1);
        std::sort(seg + 1, seg + n + 1);
        int sz = std::unique(corx + 1, corx + n + 1) - corx - 1;
        int ans = 0;
        build(1, sz - 1, 1);
        for(int i = 1; i < n; i++) {
            x = std::lower_bound(corx + 1, corx + sz + 1, seg[i].l) - corx;
            y = std::lower_bound(corx + 1, corx + sz + 1, seg[i].r) - corx - 1;
            d = seg[i].d;
            work(1);
            ans += (seg[i + 1].h - seg[i].h) * node[1].sum;
        }
        printf("%d\n", ans);
        if(f) break;
    }
    return 0;
}
