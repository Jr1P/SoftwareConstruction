#include <cstdio>
#include <cstring>
#include <iostream>
#define rep(i, a, n) for(int i = a; i <= n; i++)
#define drep(i, n, a) for(int i = n; i >= a; i--)
#define mid ((l + r) >> 1)
#define ls (k << 1)
#define rs (k << 1 | 1)
typedef long long ll;
const int N = 1e6+5;

struct Node {
    ll l, r, sum, lazy;
    Node() {}
    Node(ll _l, ll _r, ll _sum, ll _lazy = 0L) : l(_l), r(_r), sum(_sum), lazy(_lazy) {}
    inline ll length() { return r - l + 1; }
    inline ll mi() { return (l + r) >> 1; }
}node[N << 2];

ll n, m, l, r, addnum;

inline ll read() {
    ll x = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        ch = getchar();
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}

inline void update(int k) {
    node[k].sum = node[ls].sum + node[rs].sum;
}

inline void push(int k) {
    node[ls].lazy += node[k].lazy;
    node[rs].lazy += node[k].lazy;
    node[ls].sum += node[k].lazy * node[ls].length();
    node[rs].sum += node[k].lazy * node[rs].length();
    node[k].lazy = 0L;
}

void build(int l, int r, int k) {
    if(l == r) {
        ll a = read();
        node[k] = Node(l, r, a);
        return ;
    }
    node[k].l = l; node[k].r = r;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

inline void add(int k) {
    if(node[k].l >= l && node[k].r <= r) {
        node[k].sum += node[k].length() * addnum;
        node[k].lazy += addnum;
        return ;
    }
    if(node[k].lazy) push(k);
    if(r > node[k].mi()) add(rs);
    if(l <= node[k].mi()) add(ls);
    update(k);
}

inline ll query(int k) {
    if(node[k].l >= l && node[k].r <= r)
        return node[k].sum;
    ll ans = 0L;
    if(node[k].lazy) push(k);
    if(r > node[k].mi()) ans += query(rs);
    if(l <= node[k].mi()) ans += query(ls);
    return ans;
}

int main() {
    n = read(), m = read();
    build(1L, n, 1L);
    while(m--) {
        ll type;
        type = read(); l = read(), r = read();
        if(type == 2L) // 区间查询
            printf("%lld\n", query(1L));
        else if(type == 1L) { // 区间加
            addnum = read();
            add(1L);
        }
    }
    return 0;
}