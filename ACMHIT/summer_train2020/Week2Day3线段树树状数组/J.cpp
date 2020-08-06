#include <cstdio>
#include <algorithm>
#define ls (k << 1)
#define rs (k << 1 | 1)
const int N = 1e5 + 50;

struct Node {
    int l, r, lazy, w, mmin;

    inline int mid() { return (l + r) >> 1; }
    inline bool isLeaf() { return l == r; }
} tree[N << 2];

int n, q, x, y, ans;
int b[N];

inline int min(int x, int y) { return x < y ? x : y; }

inline void update(int k) {
    tree[k].w = tree[ls].w + tree[rs].w;
    tree[k].mmin = min(tree[ls].mmin, tree[rs].mmin);
}

inline void down(int k) {
    if(tree[k].lazy) {
        tree[ls].lazy += tree[k].lazy;
        tree[rs].lazy += tree[k].lazy;
        tree[ls].mmin -= tree[k].lazy;
        tree[rs].mmin -= tree[k].lazy;
        tree[k].lazy = 0;
    }
}

void build(int l, int r, int k) {
    tree[k].l = l, tree[k].r = r, tree[k].lazy = 0;
    if(l == r) {
        tree[k].mmin = b[l] - 1;
        tree[k].w = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void modify(int k) {
    if(tree[k].l >= x && tree[k].r <= y) {
        if(tree[k].mmin > 0) {
            tree[k].mmin--;
            tree[k].lazy++;
        } else {
            if(tree[k].isLeaf()) {
                tree[k].w++;
                tree[k].mmin = b[tree[k].l] - 1;
            } else {
                down(k);
                modify(ls);
                modify(rs);
                update(k);
            }
        }
        return ;
    }
    down(k);
    int mid = tree[k].mid();
    if(x <= mid) modify(ls);
    if(y > mid) modify(rs);
    update(k);
}

void query(int k) {
    if(tree[k].l >= x && tree[k].r <= y) {
        ans += tree[k].w;
        return ;
    }
    down(k);
    int mid = tree[k].mid();
    if(x <= mid) query(ls);
    if(y > mid) query(rs);
}

int main() {
    while(~scanf("%d%d", &n, &q)) {
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        build(1, n, 1);
        while(q--) {
            char type[10];
            scanf("%s%d%d", type, &x, &y);
            if(type[0] == 'q') {
                ans = 0;
                query(1);
                printf("%d\n", ans);
            } else if(type[0] == 'a') modify(1);
        }
    }
    return 0;
}
