#include <cstdio>
#define N 100050

int n;
int h[N], m[N];

inline int max(int x, int y) { return x > y ? x : y; }

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &h[i], &m[i]);
    }
    int cnt = 1, ans = 1;
    for(int i = 1; i < n; i++) {
        if(h[i + 1] == h[i] && m[i + 1] == m[i]) {
            cnt++; 
            ans = max(cnt, ans);
        } else {
            cnt = 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}