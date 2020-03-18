#include <cstdio>
#define N 1050

int father[N], n, m;

inline void init() {
    for(int i = 0; i <= n; i++) {
        father[i] = i;
    }
}

inline int find(int x) {
    if (x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

inline void _union(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if (f1 < f2) {
        father[f2] = f1;
    }
    else if(f1 > f2) {
        father[f1] = f2;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        init();
        while(m--) {
            int x, y;
            scanf("%d%d", &x, &y);
            _union(x, y);
        }
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(father[i] == i) cnt++;
        }   
        printf("%d\n", cnt);
    }
    return 0;
}