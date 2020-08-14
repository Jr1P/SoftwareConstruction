#include <cstdio>
const int N = 2e5+5;

int fa[N], n, k;

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void _unino(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx < fy) fa[fy] = fx;
    else if(fx > fy) fa[fx] = fy;
}

int main() {
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for(int i = 1; i <= n*3; i++) fa[i] = i;
    for(int i = 1; i <= k; i++) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if(x > n || y > n) cnt++;
        else if(d == 1) {
            if(find(x) == find(y+n) || find(y) == find(x+n) || find(x) == find(y+n*2) || find(y) == find(x+n*2)) cnt++;
            else _unino(x, y), _unino(x+n, y+n), _unino(x+2*n, y+2*n);
        } else if(d == 2) {
            if(x == y || find(x) == find(y) || find(x) == find(y+n) || find(y) == find(x+2*n)) cnt++;
            else _unino(x+n, y), _unino(x, y+2*n), _unino(x+2*n, y+n);
        }
    }
    printf("%d\n", cnt);
    return 0;
}