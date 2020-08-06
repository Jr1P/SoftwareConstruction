#include <cstdio>
#define ls (k << 1)
#define rs (k << 1 | 1)
const int N = 1e5 + 5;
const int mod = 10007;

int n, m, x, y, val, ans;

struct Node {
    int l, r, sum, sum2, sum3, la, lm, lc;
    inline int len() { return r - l + 1; }
    inline int mid() { return (r + l) >> 1; }

    Node() {}
    Node(int l, int r) : l(l), r(r) { sum = sum2 = sum3 = la = lc = 0; lm = 1; }
} node[N << 2];

inline void update(int k) {
    node[k].sum = (node[ls].sum + node[rs].sum) % mod;
    node[k].sum2 = (node[ls].sum2 + node[rs].sum2) % mod;
    node[k].sum3 = (node[ls].sum3 + node[rs].sum3) % mod;
}

inline void mul1(int k, int val) {
    node[k].sum3 = node[k].sum3 * val % mod * val % mod * val % mod;
    node[k].sum2 = node[k].sum2 * val % mod * val % mod;
    node[k].sum = node[k].sum * val % mod;

    node[k].lm = node[k].lm * val % mod;
    node[k].la = node[k].la * val % mod;
}

inline void add1(int k, int val) {
    node[k].sum3 = (node[k].sum3 + 3 * val * node[k].sum2 % mod +
            3 * val * val % mod * node[k].sum % mod +
            node[k].len() * val % mod * val % mod * val % mod) % mod;
    node[k].sum2 = (node[k].sum2 + 2 * val * node[k].sum % mod +
            node[k].len() * val % mod * val) % mod;
    node[k].sum = (node[k].sum + node[k].len() * val) % mod;

    node[k].la = (node[k].la + val) % mod;
}

inline void change1(int k, int val) {
    node[k].sum = val * node[k].len() % mod;
    node[k].sum2 = val * val % mod * node[k].len() % mod;
    node[k].sum3 = val * val % mod * val % mod * node[k].len() % mod;
    node[k].lc = val;
    node[k].la = 0;
    node[k].lm = 1;
}

inline void pushdown(int k) {
    if(node[k].la || node[k].lm != 1 || node[k].lc) {
        if(node[k].lc) {
            change1(ls, node[k].lc);
            change1(rs, node[k].lc);
            node[k].lc = 0;
        }

        mul1(ls, node[k].lm);
        mul1(rs, node[k].lm);
        node[k].lm = 1;

        add1(ls, node[k].la);
        add1(rs, node[k].la);
        node[k].la = 0;
    }
}

void build(int l, int r, int k) {
    node[k] = Node(l, r);
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void add(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        add1(k, val);
        return ;
    }
    pushdown(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) add(ls);
    if(y > mid) add(rs);
    update(k);
}

void mul(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        mul1(k, val);
        return ;
    }
    pushdown(k);
    int mid = node[k].mid();
    if(x <= mid) mul(ls);
    if(y > mid) mul(rs);
    update(k);
}

void modify(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        change1(k, val);
        return ;
    }
    pushdown(k);
    int mid = node[k].mid();
    if(x <= mid) modify(ls);
    if(y > mid) modify(rs);
    update(k);
}

void query(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        switch (val) {
        case 1:
            ans += node[k].sum;
            break;
        case 2:
            ans += node[k].sum2;
            break;
        case 3:
            ans += node[k].sum3;
            break;
        }
        ans %= mod;
        return ;
    }
    pushdown(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) query(ls);
    if(y > mid) query(rs);
}

int main() {
    while(~scanf("%d%d", &n, &m)) {
        if(!n && !m) break;
        build(1, n, 1);
        for(int i = 1; i <= m; i++) {
            int type;
            scanf("%d%d%d%d", &type, &x, &y, &val);
            switch(type) {
            case 1:
                add(1);
                break;
            case 2:
                mul(1);
                break;
            case 3:
                modify(1);
                break;
            case 4:
                ans = 0;
                query(1);
                printf("%d\n", ans % mod);
                break;
            }
        }
    }
    return 0;
} 