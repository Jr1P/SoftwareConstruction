#include <cstdio>
#include <algorithm>
#define N 10050

int n;
double a[N], b[N], c[N];

double max(double x, double y) { return x > y ? x : y; }

int main() {
    scanf("%d", &n);
    for(int i = 0; i <= n; i++)
        scanf("%lf%lf", &a[i], &b[i]);
    for(int i = 1; i <= n; i++) {
        c[i] = a[i] / (b[i] / b[i - 1]);
    }
    std::sort(c + 1, c + n + 1);
    double ma = 0.0F, tmp = 1.0F;
    for(int i = 1; i <= n; i++) {
        tmp *= c[i];
        ma = max(ma, tmp);
    }
    printf("%f\n", ma);
    return 0;
}