#include <cstdio>
#include <algorithm>
const int N = 2e4+5;
const int M = 1e5+5;

int n, m, r, fa[N];

struct Edge {
    int u, v, w;
    bool operator < (const Edge o) const {
        return w < o.w;
    }
}e[M];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

bool _unino(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return false;
    if(fx < fy) fa[fy] = fx;
    else if(fx > fy) fa[fx] = fy;
    return true;
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &n, &m, &r);
        for(int i = 1; i <= n+m; i++) fa[i] = i;
        int ans = (n+m)*10000;
        for(int i = 1; i <= r; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            e[i] = (Edge){u, v+n, -w};
        }
        std::sort(e+1, e+r+1);
        for(int i = 1; i <= r; i++) {
            if(_unino(e[i].u, e[i].v))
                ans += e[i].w;
        }
        printf("%d\n", ans);
    }

    return 0;
}