#include <cstdio>
#include <cmath>
#include <iostream>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 100000 + 5;
typedef long long ll;

inline ll max(ll x, ll y) { return x > y ? x : y; }

int n, m, x, y;
ll ans = 0L;

struct Node {
    int l, r;
    ll _max, sum;
}node[N << 2];

inline void update(int k) {
    node[k]._max = max(node[ls]._max, node[rs]._max);
    node[k].sum = node[ls].sum + node[rs].sum;
}

void build(int l, int r, int k) {
    node[k].l = l; node[k].r = r;
    if(l == r) {
        scanf("%lld", &node[k]._max);
        node[k].sum = node[k]._max;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void fire(int k) {
    if(node[k]._max == 1L) return ;
    if(node[k].l == node[k].r) {
        node[k].sum = (ll)(sqrt(node[k].sum));
        node[k]._max = node[k].sum;
        return ;
    }
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) fire(ls);
    if(y > mid) fire(rs);
    update(k);
}

void query(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        ans += node[k].sum;
        return ;
    }
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) query(ls);
    if(y > mid) query(rs);
}

int main() {
    int kase = 0;
    while(~scanf("%d", &n)) {
        printf("Case #%d:\n", ++kase);
        build(1, n, 1);
        scanf("%d", &m);
        while(m--) {
            int type;
            scanf("%d%d%d", &type, &x, &y);
            if(x > y)
                std::swap(x, y);
            if(!type)
                fire(1);
            else {
                ans = 0L;
                query(1);
                printf("%lld\n", ans);
            }
        }
        puts("");
    }
    return 0;
}