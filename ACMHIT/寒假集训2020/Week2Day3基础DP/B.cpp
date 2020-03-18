#include <cstdio>
#include <iostream>
#define N 5050

int n, ans, cnt;
int a[N], f[N], m[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; i++) f[i] = m[i] = 1;
    for(int i = n; i >= 1; i--) {
        for(int j = i + 1; j <= n; j++) {
            if(a[i] > a[j]) {
                if(f[i] < f[j] + 1)
                    f[i] = f[j] + 1, m[i] = m[j];
                else if(f[i] == f[j] + 1)
                    m[i] += m[j];
            } else if(a[i] == a[j]) {
                if(f[i] == 1) m[i] = 0;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)
        ans = std::max(ans, f[i]);
    int ma = 0;
    for(int i = 1; i <= n; i++)
        if(f[i] == ans)
            ma += m[i];
    printf("%d %d\n", ans, ma);
    return 0;

}