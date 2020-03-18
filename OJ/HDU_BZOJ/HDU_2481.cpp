#include <cstdio>
#include <algorithm>
#define ls (k << 1)
#define rs (ls | 1)
const int N = 1e5 + 5;

struct Seg {
    int l, r, id;
    Seg() {}
    Seg(int l, int r, int id) : l(l), r(r), id(id) {}
    inline bool operator < (const Seg& a) const {
        return l == a.l ? r > a.r : l < a.l;
    }
}seg[N];

int n, right;
int tree[N], ans[N];

inline int lowbit(int k) { return k & (-k); }

inline void update(int k) {
    for(int i = k; i <= right; i += lowbit(i))
        tree[i] += 1;
}

inline int sum(int l) {
    int ans = 0;
    for(int i = l; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}

int main() {
    while(1) {
        scanf("%d", &n);
        if(!n) break;
        int l, r;
        right = 0;
        for(int i = 1; i <= n; i++) {
            tree[i] = ans[i] = 0;
            scanf("%d%d", &l, &r);
            seg[i] = Seg(l, r, i);
            if(right < r) right = r;
        }
        std::sort(seg + 1, seg + n + 1);
        ans[seg[1].id] = 0;
        update(seg[1].r);
        for(int i = 2; i <= n; i++) {
            if(seg[i - 1].l == seg[i].l && seg[i - 1].r == seg[i].r)
                ans[seg[i].id] = ans[seg[i - 1].id];
            else ans[seg[i].id] = sum(right) - sum(seg[i].r - 1);
            update(seg[i].r);
        }
        printf("%d", ans[1]);
        for(int i = 2; i <= n; i++)
            printf(" %d", ans[i]);
        puts("");
    }
    return 0;
}