#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ls (k << 1)
#define rs (ls | 1)

const int N = 2e4 + 5;

int n, x, y, ans;
int l[N], r[N], tree[N << 4], li[N * 3];
bool vis[N * 3];

inline void pushdown(int k) {
    tree[rs] = tree[ls] = tree[k];
    tree[k] = -1;
}

void update(int l, int r, int k, int id) {
    if(x <= l && y >= r) {
        tree[k] = id;
        return ;
    }
    if(tree[k] != -1) pushdown(k);
    int mid = (l + r) >> 1;
    if(x <= mid)
        update(l, mid, ls, id);
    if(y > mid)
        update(mid + 1, r, rs, id);
}

void query(int l, int r, int k) {
    if(tree[k] != -1) {
        if(!vis[tree[k]]) {
            ans++;
            vis[tree[k]] = true;
        }
        return ;
    }
    if(l == r) return ;
    int mid = (l + r) >> 1;
    query(l, mid, ls);
    query(mid + 1, r, rs);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        memset(tree, -1, sizeof(tree));
        memset(vis, false, sizeof(vis));
        int tot = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d%d", &l[i], &r[i]);
            li[tot++] = l[i];
            li[tot++] = r[i];
        }
        std::sort(li, li + tot);
        int sz = std::unique(li, li + tot) - li;
        int tmp = sz;
        for(int i = 1; i < tmp; i++)
            if(li[i] > li[i - 1] + 1)
                li[sz++] = li[i - 1] + 1;
        std::sort(li, li + sz);
        for(int i = 0; i < n; i++) {
            x = std::lower_bound(li, li + sz, l[i]) - li;
            y = std::lower_bound(li, li + sz, r[i]) - li;
            update(0, sz - 1, 1, i);
        }
        ans = 0;
        query(0, sz - 1, 1);
        printf("%d\n", ans);
    }
    return 0;
}