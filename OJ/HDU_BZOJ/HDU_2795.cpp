#include <cstdio>
#define ls (k << 1)
#define rs (ls | 1)

const int N = 2e5 + 5;
int h, w, n, width;

struct Node {
    int l, r, ma;
}node[N << 2];

inline int max(int x, int y) { return x > y ? x : y; }

inline void update(int k) {
    node[k].ma = max(node[ls].ma, node[rs].ma);
}

void build(int l, int r, int k) {
    node[k].l = l; node[k].r = r;
    if(l == r) {
        node[k].ma = w;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
    update(k);
}

void query(int l, int r, int k) {
    if(l == r) {
        node[k].ma -= width;
        printf("%d\n", l);
        return ;
    }
    int mid = (l + r) >> 1;
    if(node[ls].ma >= width)
        query(l, mid, ls);
    else if(node[rs].ma >= width)
        query(mid + 1, r, rs);
    update(k);
}


int main() {
    while(~scanf("%d%d%d", &h, &w, &n)) {
        if(h > n) h = n;
        build(1, h, 1);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &width);
            if(width > node[1].ma) {
                puts("-1");
                continue;
            }
            query(1, h, 1);
        }
    }
    return 0;
}