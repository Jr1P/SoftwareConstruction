#include <cstdio>
#include <cstring>
#include <iostream>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define drep(i, n, a) for(int i = n; i >= a; i--)
#define mid (l + r) >> 1
#define ls ((k) << 1)
#define rs ((k) << 1 | 1)
const int N = 1e6+5;

struct Node {
    int l, r, maxp, minp, lazy, now;
    Node() {}
    Node(int _l, int _r, int _maxp, int _minp, int now, int _lazy = 0) : l(_l), r(_r), maxp(_maxp), minp(_minp), lazy(_lazy), now(_now) {}
    inline int length() { return r - l + 1; }
    inline int midd() { return (l + r) >> 1; }
}node[N << 2];

int n, m, pos;
int a[N];

inline int read() {
    int x = 0, f;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void push(int k) {
    node[ls].lazy += node[k].lazy;
    node[rs].lazy += node[k].lazy;
    node[k].lazy = 0;
}

void build(int l, int r, int k) {
    if(l == r) {
        node[k] = Node(l, r, l, l, l);
        return ;
    }
    node[k].l = l; node[k].r = r;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    // update(k);
}

inline void mov(int k) {
    if(node[k].l == node[k].r) {
        node[k].minp = node[k].now = 1;
        return ;
    }
    if(pos <= node[k].midd())
        mov(ls);
    else mov(rs);
}

void modi(int k) {

}

inline void query(int k) {
    int ans = 0;
    if(node[k].l == node[k].r) {
        printf("%d %d\n", node[k].minp, node[k].maxp);
        return ;
    }
    if(pos <= node[k].midd())
        query(ls);
    else query(rs);
}

int main() {
    n = read(), m = read();
    build(1, n, 1);
    rep(i, 1, m) {
        int p = read();
        mov(1);

    }
    rep(i, 1, n) {
        pos = i;
        query(1);
    }
    return 0;
}