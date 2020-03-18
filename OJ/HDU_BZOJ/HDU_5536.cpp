#include <cstdio>
#define N 1005

int n, t;
int s[N];

inline int max(int x, int y) { return x > y ? x : y; }

int main() {
    scanf("%d", &t);
    while(t--) {
        int ans = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &s[i]);
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                for(int k = 1; k <= n; k++) {
                    if(k == i || k == j) continue;
                    ans = max(ans, (s[i] + s[j]) ^ s[k]);
                }
        printf("%d\n", ans);
    }
    return 0;
}