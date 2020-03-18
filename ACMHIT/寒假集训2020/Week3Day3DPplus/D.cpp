#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 205;

int n, m, ans;
int a[N][N], sum[N][N], f[N];

int main() {
    while(~scanf("%d", &n)) {
        ans = 0;
        memset(sum, 0, sizeof(sum));
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
                sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + a[i][j];
            }
        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++) {
                int c[N];
                for(int k = 1; k <= n; k++)
                    c[k] = sum[j][k] - sum[i][k] - sum[j][k - 1] + sum[i][k - 1];
                memset(f, 0, sizeof(f));
                for(int i = 1; i <= n; i++) {
                    f[i] = max(c[i], f[i - 1] + c[i]);
                    ans = max(ans, f[i]);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}