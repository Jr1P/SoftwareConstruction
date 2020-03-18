#include <cstdio>
#define N 1050

int n, m, cnt;
int fa[N];
bool f[N];

inline int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

inline void _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
    if(f1 > f2)
		fa[f2] = f1;
    else if(f1 < f2)
        fa[f1] = f2;
}

int main() {
    while(scanf("%d", &n)) {
        if(n == 0) break;
        cnt = 0;
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            f[i] = false;
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            _union(u, v);
        }
        for(int i = 1; i <= n; i++)
            if(fa[i] == i)
                cnt++;
        printf("%d\n", cnt-1);
    }
    return 0;
}