#include <cstdio>
#include <algorithm>
#define ls k << 1
#define rs k << 1 | 1
const int N = 1e5 + 50;
typedef long long ll;

struct Node {
    int l, r;
    ll mmin, sum, lastT;
    bool vis, f;
    Node() {}
    Node(int l, int r) : l(l), r(r) { lastT = sum = mmin = 0; vis = false; f = true; }

    inline int mid() { return (l + r) >> 1; }
    inline bool isLeaf() { return l == r; }
} tree[N * 3];

inline ll min(ll x, ll y) { return x < y ? x : y; }
inline ll max(ll x, ll y) { return x > y ? x : y; }

int n, q, x, y;
ll ans, s[N], dt, mm[N], R[N];

inline void down(int k) {
    if(tree[k].vis)
        tree[ls].vis = tree[rs].vis = true;
    if(tree[k].lastT > tree[rs].lastT)
        tree[rs].lastT = tree[k].lastT;
    if(tree[k].lastT > tree[ls].lastT)
        tree[ls].lastT = tree[k].lastT;
}

inline void update(int k) {
    tree[k].sum = tree[ls].sum + tree[rs].sum;
    tree[k].mmin = min(tree[ls].mmin, tree[rs].mmin);
}

void build(int l, int r, int k) {
    tree[k] = Node(l, r);
    if(l == r) {
        scanf("%lld%lld%lld", &s[l], &mm[l], &R[l]);
        tree[k].mmin = mm[l] / R[l]; tree[k].sum = R[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void query(int k) { // 查询[x,y]
    if(tree[k].l >= x && tree[k].r <= y) {
        if(!tree[k].vis) {
            for(int i = tree[k].l; i <= tree[k].r; i++)
                ans += min(s[i] + dt * R[i], mm[i]);
            tree[k].vis = true;
            tree[k].lastT = dt;
        } else {
            ll tt = dt - tree[k].lastT;
            if(tree[k].isLeaf())
                ans += min(tree[k].sum * tt, mm[tree[k].l]), tree[k].lastT = dt;
            else if(tree[k].f && tree[k].mmin >= tt)
                ans += tt * tree[k].sum, tree[k].lastT = dt;
            else {
                down(k);
                query(ls);
                query(rs);
                tree[k].f = tree[ls].lastT == tree[rs].lastT;
            }
        }
        return ;
    }
    down(k);
    int mid = tree[k].mid();
    if(x <= mid) query(ls);
    if(y > mid) query(rs);
}

int main() {
    while(~scanf("%d", &n)) {
        s[0] = 0;
        build(1, n, 1);
        scanf("%d", &q);
        ans = dt = 0;
        ll T = 0;
        while(q--) {
            scanf("%lld%d%d", &dt, &x, &y);
            query(1);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
