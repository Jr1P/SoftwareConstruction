#include <cstdio>
const int N = 1e4+5;

int n, fa[N], m, deg[N];

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
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            deg[i] = 0;
        }
        while(m--) {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++, deg[v]++;
            _union(u, v);
        }
        int ans = 0, dd = 0;
        for(int i = 1; i <= n; i++) {
            if(fa[i] == i) ans++;
            if(deg[i] & 1) dd++;
        }
        if(ans == 1 && dd == 0) puts("1");
        else puts("0");
    }
    return 0;
}