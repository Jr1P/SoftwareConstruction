#include <cstdio>
#define N 100010

typedef long long ll;
struct Node {
    ll l, r, sum, la_s, la_m;
} node[N << 2];

ll n, m, p, x, y, add, ans;
int op;

inline ll len(int k) //返回k节点的区间长度
{
    return node[k].r - node[k].l + 1;
}

void build(int l, int r, int k) {
    node[k].l = l;
    node[k].r = r;
    node[k].la_m = 1;
    if (l == r)
    {
        scanf("%lld", &node[k].sum);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, k << 1);
    build(mid + 1, r, k << 1 | 1);
    node[k].sum = (node[k << 1].sum + node[k << 1 | 1].sum) % p;
}

inline void down(int k) {
    int ls = k << 1, rs = k << 1 | 1;
    node[ls].la_m = node[ls].la_m * node[k].la_m % p;
    node[rs].la_m = node[rs].la_m * node[k].la_m % p;
    node[ls].la_s = node[ls].la_s * node[k].la_m % p;
    node[rs].la_s = node[rs].la_s * node[k].la_m % p;
    node[ls].sum = node[ls].sum * node[k].la_m % p;
    node[rs].sum = node[rs].sum * node[k].la_m % p;
    node[k].la_m = 1;
    node[ls].la_s = (node[ls].la_s + node[k].la_s) % p;
    node[rs].la_s = (node[rs].la_s + node[k].la_s) % p;
    node[ls].sum = (node[ls].sum + node[k].la_s * len(ls)) % p;
    node[rs].sum = (node[rs].sum + node[k].la_s * len(rs)) % p;
    node[k].la_s = 0;
}

void Sum(int k) {
    if (node[k].l >= x && node[k].r <= y) {
        node[k].sum = (node[k].sum + add * len(k)) % p;
        node[k].la_s = (node[k].la_s + add) % p;
        return;
    }
    if (node[k].la_s || node[k].la_m != 1)
        down(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if (x <= mid) Sum(k << 1);
    if (y > mid) Sum(k << 1 | 1);
    node[k].sum = (node[k << 1].sum + node[k << 1 | 1].sum) % p;
}

void Mul(int k) {
    if (node[k].l >= x && node[k].r <= y) {
        node[k].sum = add * node[k].sum % p;
        node[k].la_m = node[k].la_m * add % p;
        node[k].la_s = node[k].la_s * add % p;
        return;
    }
    if (node[k].la_s || node[k].la_m != 1)
        down(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if (x <= mid) Mul(k << 1);
    if (y > mid) Mul(k << 1 | 1);
    node[k].sum = (node[k << 1].sum + node[k << 1 | 1].sum) % p;
}

void inquiry(int k) {
    if (node[k].l >= x && node[k].r <= y) {
        ans = (ans + node[k].sum) % p;
        return;
    }
    if (node[k].la_s || node[k].la_m != 1)
        down(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if (x <= mid) inquiry(k << 1);
    if (y > mid) inquiry(k << 1 | 1);
}

int main() {
    scanf("%lld%lld", &n, &p);
    build(1, n, 1);
    scanf("%lld", &m);
    while (m--) {
        scanf("%d%lld%lld", &op, &x, &y);
        if (op == 1) {
            scanf("%lld", &add);
            Mul(1);
        }
        else if (op == 2) {
            scanf("%lld", &add);
            Sum(1);
        }
        else {
            ans = 0L;
            inquiry(1);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
