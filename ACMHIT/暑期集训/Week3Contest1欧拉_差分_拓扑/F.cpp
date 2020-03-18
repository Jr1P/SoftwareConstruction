#include <cstdio>
#include <cstring>
#define N 550 

int tot[N][N];
int f[N];
int n;

inline int max(int x, int y) {
    return x > y? x: y;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        memset(tot, 0, sizeof tot);
        memset(f, 0, sizeof f);
        for(int i = 1; i <= n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            if(a+b >= n) continue;
            tot[a][b]++;
            if(tot[a][b] > n-a-b) tot[a][b] = n-a-b;
        }

        for(int i = 1; i <= n; i++)
            for(int j = 0; j <= i; j++)
                f[i] = max(f[i], f[j]+tot[j][n-i]);
        printf("%d\n", f[n]);
    }
    return 0;
}