#include <cstdio>
#include <cmath>
#include <algorithm>
const int N = 105;

struct Node {
    double x, y;
    int id;
    Node() {}
    Node(double _x, double _y) : x(_x), y(_y) {}
}node[N];

int t, n, cnt, fa[N];

inline double dist(int a, int b) {
    double dx = node[a].x - node[b].x, dy = node[a].y - node[b].y;
    return a == b ? 0.0 : sqrt(dx * dx + dy * dy);
}

inline int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

struct Seg {
    int l, r; // 左右端点
    double len;
    Seg() {}
    Seg(int _l, int _r) : l(_l), r(_r) {
        len = dist(l, r);
    }
    bool operator < (const Seg o) const {
        return len < o.len;
    }
}seg[N * N];

inline bool _union(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return false;
    if(fx < fy) fa[fy] = fx;
    else fa[fx] = fy;
    return true;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            scanf("%lf%lf", &node[i].x, &node[i].y);
        }
        cnt = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                seg[cnt++] = Seg(i, j);
        std::sort(seg, seg + cnt);
        double MST = 0.0;
        for(int i = 0; i < cnt; i++) {
            if(_union(seg[i].l, seg[i].r))
                MST += seg[i].len;
        }
        int M = round(MST);
        printf("%d\n\n", M);
    }

    return 0;
}