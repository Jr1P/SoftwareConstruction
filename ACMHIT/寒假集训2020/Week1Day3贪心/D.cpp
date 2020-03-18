#include <cstdio>
#define N 105

int n, m, k, t;
int h[N];

inline int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    scanf("%d", &t);
    bool f = false;
    while(t--) {
        f = false;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        for(int i = 1; i < n; i++) {
            int tmp = h[i] - h[i + 1];
            m += min(tmp + k, h[i]);
            if(m < 0) {
                puts("NO");
                f = true;
                break;
            }
        }
        if(f) continue;
        puts("YES");
    }
    return 0;
}