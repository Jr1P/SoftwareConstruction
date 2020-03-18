#include <cstdio>
#define ls k<<1
#define rs k<<1|1
#define L 1000050
#define Q 100050

struct Node{
    int l, r, lazy, color;
}node[L<<2];

int q, len;
int l, r, color, ans;

inline void _swap(int& x, int& y) {
    int t = x;
    x = y;
    y = t;
}

inline void calc(int x) {
    int pos = 1;
    while((x&1) == 0) {
        x >>= 1;
        pos++;
    }
    printf("%d", pos);
    x >>= 1; pos++;
    while(x) {
        if(x&1)
            printf(" %d", pos);
        x >>= 1;
        pos++;
    }
    printf("\n");
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
    node[k].color = 2; node[k].lazy = 0;
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
    while(1) {
        scanf("%d%d", &len, &q);
        if(len == 0 && q == 0) break;
        build(1, len, 1);
        for(int i = 1; i <= q; i++) {
            char c = getchar();
            c = getchar();
            if(c == 'P') {
                scanf("%d%d%d", &l, &r, &color);
                if(l > r) _swap(l, r);
                modify(1);
            } else {
                ans = 0;
                scanf("%d%d", &l, &r);
                if(l > r) _swap(l, r);
                query(1);
                calc(ans);
            }
        }
    }
    return 0;
}