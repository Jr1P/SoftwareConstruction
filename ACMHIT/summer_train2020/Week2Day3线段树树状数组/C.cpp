#include <cstdio>
#include <algorithm>
#define ls k << 1
#define rs k << 1 | 1
const int N = 1e5 + 50;

int n, q, x, y, add;
int c[N];

inline int lowbit(int x) { return x & (-x); }

inline void insert(int x, int val) {
    for(int i = x; i <= n; i += lowbit(i))
        c[i] += val;
}

inline int sum(int k) {
    int ans = 0;
    for(int i = k; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}


int main() {
    int T, kase = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) c[i] = 0;
        for(int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            insert(i, a);
        }
        printf("Case %d:\n", ++kase);
        while(1) {
            char type[10];
            getchar();
            scanf("%s", type);
            if(type[0] == 'Q') {
                scanf("%d%d", &x, &y);
                printf("%lld\n", sum(y) - sum(x - 1));
            } else if(type[0] == 'A') {
                scanf("%d%d", &x, &add);
                insert(x, add);
            } else if(type[0] == 'S') {
                scanf("%d%d", &x, &add);
                insert(x, -add);
            } else break;
        } 

    }
    return 0;
}
