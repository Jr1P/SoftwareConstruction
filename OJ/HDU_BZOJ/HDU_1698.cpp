#include <cstdio>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 1e5 + 5;

int n, q, l, r, val;

struct Node {
    int l, r, sum, lazy;
    inline int length() { return r - l + 1; }
}node[N << 2];

inline void update(int k) {
    node[k].sum = node[ls].sum + node[rs].sum;
}

inline void push(int k) {
    node[ls].lazy = node[rs].lazy = node[k].lazy;
    node[ls].sum = node[k].lazy * node[ls].length();
    node[rs].sum = node[k].lazy * node[rs].length();
    node[k].lazy = 0;
}

void build(int l, int r, int k) {
    node[k].l = l; node[k].r = r; node[k].lazy = 0;
    if(l == r) {
        node[k].sum = 1;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void modify(int k) {
    if(node[k].l >= l && node[k].r <= r) {
        node[k].lazy = val;
        node[k].sum = val * node[k].length();
        return ;
    }
    if(node[k].lazy) push(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(l <= mid) modify(ls);
    if(r > mid) modify(rs);
    update(k);
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        build(1, n, 1);
        while(q--) {
            scanf("%d%d%d", &l, &r, &val);
            modify(1);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++kase, node[1].sum);
    }
    return 0;
}