#include <cstdio>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 1e5 + 5;
const int mod = 10007;

int n, m, x, y, val, ans;

struct Node {
    int l, r, sum, sum2, sum3, la, lm, lc;
    inline int length() { return r - l + 1; }
}node[N << 2];

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
            node[k].length() * val % mod * val % mod * val % mod) % mod;
    node[k].sum2 = (node[k].sum2 + 2 * val * node[k].sum % mod +
            node[k].length() * val % mod * val) % mod;
    node[k].sum = (node[k].sum + node[k].length() * val) % mod;

    node[k].la = (node[k].la + val) % mod;
}

inline void change1(int k, int val) {
    node[k].sum = val * node[k].length() % mod;
    node[k].sum2 = val * val % mod * node[k].length() % mod;
    node[k].sum3 = val * val % mod * val % mod * node[k].length() % mod;
    node[k].lc = val;
    node[k].la = 0;
    node[k].lm = 1;
}

inline void push(int k) {
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
    node[k].l = l; node[k].r = r; node[k].la = node[k].lc = 0; node[k].lm = 1;
    if(l == r) {
        node[k].sum = node[k].sum2 = node[k].sum3 = 0;
        return ;
    }
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
    push(k);
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
    push(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) mul(ls);
    if(y > mid) mul(rs);
    update(k);
}

void change(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        change1(k, val);
        return ;
    }
    push(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) change(ls);
    if(y > mid) change(rs);
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
    push(k);
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
                change(1);
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