#include <cstdio>
#define ls k<<1
#define rs k<<1|1
#define L 100050
#define Q 100050

struct Node{
    int l, r, lazy, color;
}node[L<<2];

int q, len, t;
int l, r, color, ans;

inline void _swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

inline int calc(int x) {
    int res = 0;
    while(x) {
        if(x&1) res++;
        x >>= 1;
    }
    return res;
}

inline void pushup(int k) {
    node[k].color = node[ls].color|node[rs].color;
}

inline void down(int k) {
    node[ls].color = node[rs].color = 1<<(node[k].lazy-1);
    node[ls].lazy = node[rs].lazy = node[k].lazy;
    node[k].lazy = 0; 
}

void build(int l, int r, int k) {
    node[k].l = l; node[k].r = r;
    node[k].color = 1;
    if(l == r)
        return ;
    int mid = (l+r)>>1;
    build(l, mid, ls);
    build(mid+1, r, rs);
}

void modify(int k) {
    if(node[k].l >= l && node[k].r <= r) {
        node[k].color = 1<<(color-1);
        node[k].lazy = color;
        return ;
    }
    if(node[k].lazy) down(k);
    int mid = (node[k].l+node[k].r)>>1;
    if(l <= mid) modify(ls);
    if(r > mid) modify(rs);
    pushup(k);
}

void query(int k) {
    if(node[k].l >= l && node[k].r <= r) {
        ans |= node[k].color;
        return ;
    }
    if(node[k].lazy) down(k);
    int mid = (node[k].l+node[k].r)>>1;
    if(l <= mid) query(ls);
    if(r > mid) query(rs);
    pushup(k);
}

int main() {
    scanf("%d%d%d", &len, &t, &q);
    build(1, len, 1);
    for(int i = 1; i <= q; i++) {
        char c = getchar();
        c = getchar();
        if(c == 'C') {
            scanf("%d%d%d", &l, &r, &color);
            if(l > r) _swap(l, r);
            modify(1);
        } else {
            ans = 0;
            scanf("%d%d", &l, &r);
            if(l > r) _swap(l, r);
            query(1);
            printf("%d\n", calc(ans));
        }
    }
    return 0;
}