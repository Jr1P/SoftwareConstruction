#include <cstdio>
#include <algorithm>
#include <cmath>

#define N 1050
#define eps 1e-5
int n, k;

double sa, sb;
double a[N], b[N], c[N];

inline bool cmp(int a, int b) { return a > b; }

int main()
{
    while (scanf("%d%d", &n, &k) != EOF)
    {
        if (n == 0 && k == 0)
            break;
        for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%lf", &b[i]);

        double l = 0.0, r = 1.0;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            for (int i = 1; i <= n; i++)
                c[i] = a[i] - mid * b[i];
            std::sort(c + 1, c + n + 1, cmp);
            double ans = 0;
            for (int i = 1; i <= n - k; i++)
                ans += c[i];
            if (ans < 0) r = mid;
            else l = mid;
        }
        l = l * 100;
        int ans = round(l);
        printf("%d\n", ans);
    }
    return 0;
}