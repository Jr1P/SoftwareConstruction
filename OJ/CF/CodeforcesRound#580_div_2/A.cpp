#include <cstdio>

int a[100], b[100];
bool f[300];
int n, m;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        f[a[i]] = 1;
    }
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        f[b[i]] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            if(!f[a[i]+b[j]]) {
                printf("%d %d\n", a[i], b[j]);
                return 0;
            }
        }
    return 0;
}