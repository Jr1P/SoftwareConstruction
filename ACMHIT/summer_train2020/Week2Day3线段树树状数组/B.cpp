// #include <cstdio>
// #include <algorithm>
// #define ls k << 1
// #define rs k << 1 | 1
// const int N = 1e3 + 50;

// struct Node {
//     int l, r, w, lazy;
//     Node() {}
//     Node(int l, int r) : l(l), r(r) { lazy = w = 0; }

//     inline int mid() { return (l + r) >> 1; }
// } tree[N][N << 1];

// int n, q, x, y, x0, y0, ans;

// inline void down(int i, int k) {
//     if(tree[i][k].lazy) {
//         tree[i][ls].lazy += tree[i][k].lazy;
//         tree[i][rs].lazy += tree[i][k].lazy;
//         tree[i][ls].w += tree[i][k].lazy;
//         tree[i][rs].w += tree[i][k].lazy;
//         tree[i][k].lazy = 0;
//     }
// }

// void build(int l, int r, int k, int i) {
//     tree[i][k] = Node(l, r);
//     if(l == r) return ;
//     int mid = (l + r) >> 1;
//     build(l, mid, ls, i);
//     build(mid + 1, r, rs, i);
// }

// void modify(int i, int k) {
//     if(tree[i][k].l >= x && tree[i][k].r <= x0) {
//         for(int j = i; j <= y0; j++) {
//             tree[j][k].lazy++;
//             tree[j][k].w++;
//         }
//         return ;
//     }
//     // down(i, k);
//     int mid = tree[i][k].mid();
//     if(x <= mid) modify(i, ls);
//     if(x0 > mid) modify(i, rs);
// }

// void query(int k) {
//     if(tree[y][k].l == tree[y][k].r) {
//         printf("%d\n", tree[y][k].w & 1);
//         return ;
//     }
//     down(y, k);
//     int mid = tree[y][k].mid();
//     if(x <= mid) query(ls);
//     else query(rs);
// }

// int main() {
//     int T;
//     scanf("%d", &T);
//     while(T--) {
//         scanf("%d%d", &n, &q);
//         for(int i = 1; i <= n; i++) build(1, n, 1, i);
//         while(q--) {
//             char type = getchar();
//             type = getchar();
//             if(type == 'C') {
//                 scanf("%d%d%d%d", &x, &y, &x0, &y0);
//                 // for(int i = y; i <= y0; i++)
//                 modify(y, 1);
//             } else {
//                 scanf("%d%d", &x, &y);
//                 query(1);
//             }
//         }
//         if(T) puts("");
//     }
//     return 0;
// }

#include <cstdio>
#include <algorithm>
const int N = 1e3 + 50;

int c[N][N];
int x, x0, y, y0, n, q;

inline int lowbit(int x) { return x & (-x); }

inline void insert(int posx, int posy, int val) {
    for(int i = posx; i <= n; i += lowbit(i))
        for(int j = posy; j <= n; j += lowbit(j))
            c[i][j] += val;
}

inline int sum(int posx, int posy) {
    int ans = 0;
    for(int i = posx; i; i -= lowbit(i))
        for(int j = posy; j; j -= lowbit(j))
            ans += c[i][j];
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &q);
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++) c[i][j] = 0;
        while(q--) {
            char type = getchar();
            type = getchar();
            if(type == 'C') {
                scanf("%d%d%d%d", &x, &y, &x0, &y0);
                insert(x, y, 1);
                insert(x, y0 + 1, -1); insert(x0 + 1, y, - 1);
                insert(x0 + 1, y0 + 1, 1);
            } else {
                scanf("%d%d", &x, &y);
                int ans = sum(x, y);
                printf("%d\n", ans & 1);
            }
        }
        if(T) puts("");
    }
    return 0;
}