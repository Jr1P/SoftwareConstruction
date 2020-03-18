#include <cstdio>
#include <algorithm>
using namespace std;
#define N 4050

int a[N], b[N], c[N], d[N], A[N * N], C[N * N];
int n;
long long cnt;

int main() {
    while(scanf("%d", &n) != EOF) {
        cnt = 0;
        for(int i = 0; i < n; i++)
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                A[i * n + j] = a[i] + b[j];
                C[i * n + j] = -(c[i] + d[j]);
            }
        sort(A, A + n * n);
        // sort(C + 1, C + n * n + 1);
        for(int i = 0; i < n * n; i++) {
            if(!binary_search(A, A + n * n, C[i]))
                continue;
            cnt += upper_bound(A, A + n * n, C[i]) - lower_bound(A, A + n * n, C[i]);
        }
        printf("%lld\n", cnt);
    }
    return 0;
}