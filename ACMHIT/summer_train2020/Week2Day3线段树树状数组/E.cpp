#include <cstdio>
#include <algorithm>
#define ls k << 1
#define rs k << 1 | 1
const int N = 3e5 + 50;
typedef long long ll;

struct Node {
    int l, r, w;
    Node() {}
    Node(int l, int r) : l(l), r(r) { w = 0; }

    inline int mid() { return (l + r) >> 1; }
} tree[N << 1];

int n, q, x, y, ans, add;

inline void update(int k) {
    tree[k].w = std::max(tree[ls].w, tree[rs].w);
}

void build(int l, int r, int k) {
    tree[k] = Node(l, r);
    if(l == r) {
        scanf("%d", &tree[k].w);
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void modify(int k) {
    if(tree[k].l == tree[k].r) {
        tree[k].w = y;
        return ;
    }
    int mid = tree[k].mid();
    if(x <= mid) modify(ls);
    else modify(rs);
    update(k);
}

void query(int k) {
    if(tree[k].l >= x && tree[k].r <= y) {
        ans = std::max(tree[k].w, ans);
        return ;
    }
    int mid = tree[k].mid();
    if(x <= mid) query(ls);
    if(y > mid) query(rs);
}

int main() {
    while(~scanf("%d%d", &n, &q)) {
        build(1, n, 1);
        while(q--) {
            char type = getchar();
            type = getchar();
            scanf("%d%d", &x, &y);
            if(type == 'Q') {
                ans = 0;
                query(1);
                printf("%d\n", ans);
            } else modify(1);
        }
    }
    return 0;
}