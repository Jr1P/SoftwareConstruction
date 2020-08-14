#include <cstdio>
const int N = 1e3 + 5;

int n, fa[N], m;

inline int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void _union(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx < fy) fa[fy] = fx;
    else if(fx > fy) fa[fx] = fy;
}

int main() {
    while(~scanf("%d", &n) && n) {
        scanf("%d", &m);
        for(int i = 1; i <= n; i++) fa[i] = i;
        while(m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            _union(u, v);
        }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(fa[i] == i) ans++;
        printf("%d\n", ans - 1);
    }
    return 0;
}