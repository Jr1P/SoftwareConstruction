#include <cstdio>
#include <algorithm>
#define ls k << 1
#define rs k << 1 | 1
const int N = 2e5 + 50;
typedef long long ll;

struct Node {
    int l, r;
    ll lazy, w;
    Node() {}
    Node(int l, int r) : l(l), r(r) { lazy = w = 0; }

    inline ll mid() { return (l + r) >> 1; }
    inline ll len() { return r - l + 1; }
} tree[N << 1];

int n, q, x, y;
ll ans, add;
// int c[N]; // 树状数组

inline void update(int k) {
    tree[k].w = tree[ls].w + tree[rs].w;
}

inline void down(int k) {
    if(tree[k].lazy) {
        tree[ls].lazy += tree[k].lazy;
        tree[rs].lazy += tree[k].lazy;
        tree[ls].w += tree[ls].len() * tree[k].lazy;
        tree[rs].w += tree[rs].len() * tree[k].lazy;
        tree[k].lazy = 0;
    }
    /*
    if(tree[k].lazy || tree[k].mul != 1) {
        tree[]
    }
    */
}

void build(int l, int r, int k) {
    tree[k] = Node(l, r);
    if(l == r) {
        scanf("%lld", &tree[k].w);
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void modify(int k) { // 修改[x, y], 本例为加add
    if(tree[k].l >= x && tree[k].r <= y) {
        tree[k].w += add * tree[k].len();
        tree[k].lazy += add;
        return ;
    }
    down(k);
    int mid = tree[k].mid();
    if(x <= mid) modify(ls);
    if(y > mid) modify(rs);
    update(k);
}

void query(int k) { // 查询[x,y]
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
    scanf("%d%d", &n, &q);
    build(1, n, 1);
    while(q--) {
        char type = getchar();
        type = getchar();
        scanf("%d%d", &x, &y);
        if(type == 'Q') {
            ans = 0;
            query(1);
            printf("%lld\n", ans);
        } else {
            scanf("%lld", &add);
            modify(1);
        }
    }
    return 0;
}

    // int a[N], b[N];
    // for(int i = 1; i <= n; i++)
    //     scanf("%d", &a[i]), b[i] = a[i];
    // std::sort(b + 1, b + n + 1);
    // int siz = std::unique(b + 1, b + n + 1) - (b + 1);
    // for(int i = 1; i <= n; i++)
    //     a[i] = std::lower_bound(b + 1, b + siz + 1, a[i]) - b;
    // for(int i = 1; i <= n; i++) {
    //     insert(a[i], 1);
    //     ans += i - sum(a[i]);
    // }
    // printf("%d\n", ans);
    // inline int lowbit(int x) { return x & (-x); }

// inline void insert(int x, int val) {
//     for(int i = x; i <= n; i += lowbit(i))
//         c[i] += val;
// }

// inline int sum(int k) {
//     int ans = 0;
//     for(int i = k; i; i -= lowbit(i))
//         ans += c[i];
//     return ans;
// }
