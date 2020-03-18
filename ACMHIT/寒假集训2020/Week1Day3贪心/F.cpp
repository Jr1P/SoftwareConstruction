#include <cstdio>
#include <algorithm>
#define N 105

int n;

struct Node {
    int l, r;
}a[N];

inline bool cmp(Node a, Node b) {
    return a.r < b.r;
}

int main() {
    while(1) {
        scanf("%d", &n);
        if(!n) break;
        for(int i = 1; i <= n; i++) {
            scanf("%d%d", &a[i].l, &a[i].r);
        }
        std::sort(a + 1, a + n + 1, cmp);
        int pos = a[1].r, ans = 1;
        for(int i = 2; i <= n; i++) {
            if(a[i].l >= pos) {
                ans++;
                pos = a[i].r;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}