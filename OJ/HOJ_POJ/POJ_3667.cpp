#include <cstdio>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 5e4 + 5;

struct Node {
    int l, r, ma, lazy;
}node[N << 2];

int n, m, l, r, val;
int suf[N];

inline int max(int x, int y) { return x > y ? x : y; }
inline void update(int k) { node[k].ma = max(node[ls].ma, node[rs].ma); }

inline void push(int k) {
    if(node[k].lazy) {
        node[ls].lazy = node[rs].lazy = node[k].lazy;
        node[ls].ma = node[rs].ma = node[k].ma;
        node[k].lazy = 0;
    }
}

void build(int l, int r, int k) {
    node[k].l = l; node[k].r = r; node[k].lazy = 0;
    if(l == r) {
        node[k].ma = n - l + 1;
        suf[l] = node[k].ma;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

int checkin(int k) {
    if(node[k].ma < val)
        return 0;
    if(node[k].l == node[k].r) {
        node[k].ma = 0;
        return node[k].l;
    }
    if(node[ls].ma >= val)
        return checkin(ls);
    else return checkin(rs);
    update(k);
}

void checkout(int k) {
    if(node[k].l >= l && node[k].r <= r) {
        node[k].ma = val + suf[r];
        suf[node[k].l] = node[k].ma;
        node[k].lazy = 0;
        return ;
    }
    push(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(l <= mid) checkout(ls);
    if(r > mid) checkout(rs);
    update(k);
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        build(1, n, 1);
        while(m--) {
            int type;
            scanf("%d", &type);
            if(type == 1) {
                scanf("%d", &val);
                printf("%d\n", checkin(1));
            } else {
                scanf("%d%d", &l, &val);
                r = l + val - 1;
                checkout(1);
            }
        }
    }
    return 0;
}