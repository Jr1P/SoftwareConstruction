#include <cstdio>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 1e5 + 5;

int n, x, y;

struct Node {
    int l, r, sum, lazy;
    inline int length() { return r - l + 1; }
}node[N << 2];

void build(int l, int r, int k) {
    node[k].l = l; node[k].r = r; node[k].lazy = 0;
    if(l == r) {
        node[k].sum = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls);
    build(mid + 1, r, rs);
}

inline void push(int k) {
    node[ls].lazy += node[k].lazy;
    node[rs].lazy += node[k].lazy;
    node[ls].sum += node[k].lazy;
    node[rs].sum += node[k].lazy;
    node[k].lazy = 0;
}

void work(int k) {
    if(node[k].l >= x && node[k].r <= y) {
        node[k].sum++;
        node[k].lazy++;
        return ;
    }
    if(node[k].lazy) push(k);
    int mid = (node[k].l + node[k].r) >> 1;
    if(x <= mid) work(ls);
    if(y > mid) work(rs);
}

void print(int k) {
    if(node[k].l == node[k].r) {
        if(node[k].l == n)
            printf("%d", node[k].sum);
        else
            printf("%d ", node[k].sum);
        return ;
    }
    if(node[k].lazy) push(k);
    print(ls);
    print(rs);
}

int main() {
    while(scanf("%d", &n)) {
        if(!n) break;
        build(1, n, 1);
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &x, &y);
            work(1);
        }
        print(1);
        puts("");
    }
    return 0;
}