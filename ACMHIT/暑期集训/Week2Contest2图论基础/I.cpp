#include <cstdio>
#define N 50050

int n, k, ans;
int father[N*3];

inline int find(int x) {
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

inline void _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
    if(f1 < f2)
        father[f2] = f1;
    else if(f1 > f2)
        father[f1] = f2;
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= 3*n; i++)
        father[i] = i;
    ans = 0;
    for(int i = 1; i <= k; i++) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);
        if(x > n || y > n) {
            ans++;
            continue;
        }
        if(d == 1) {
            if(find(x) == find(y+n) || find(x) == find(y+2*n) || find(x+n) == find(y) || find(y) == find(x+2*n)) {
                ans++;
                continue;
            }
            _union(x, y);
            _union(x+n, y+n);
            _union(x+2*n, y+2*n);
        } else {
            if(x == y || find(x) == find(y) || find(x) == find(y+n) || find(y) == find(x+2*n)) {
                ans++;
                continue;
            }
            _union(x+n, y);
            _union(x, y+2*n);
            _union(x+2*n, y+n);
        }
    }
    printf("%d\n", ans);
    return 0;
}