#include <cstdio>
const int N = 2e5+5;
const int M = 4e5+5;

struct E {
    int u, v;
} e[M];

int n, fa[N], cnt, m;
int ansx[N], ansy[N];

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool _union(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return false;
    fa[fy] = fx;
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i =1; i <= n; i++) fa[i] = i;
    int s, t, ds, dt, sp;
    for(int i = 1; i <= m; i++) {
        scanf("%d%d", &e[i].u, &e[i].v);
        if((e[i].u == s && e[i].v == t) || (e[i].u == t && e[i].v == s))
            sp = i;
    }
    scanf("%d%d%d%d", &s, &t, &ds, &dt);
    for(int i = 1; i <= m; i++) {
        if(i == sp) continue;
        if(_union(e[i].x, e[i].y)) {
            cnt++;
            ansx[cnt] = e[i].x;
            ansy[cnt] = e[i].y;
        }
    }
    if(cnt)
    return 0;
}