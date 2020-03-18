#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 100500
#define eps 1e-7

double ans, l = 0.01, r, ma = 0.0, sum = 0.0;
double len[N];
int n, k;

bool check(double ans) {
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        cnt += (int) (len[i] / ans);
    if(cnt >= k) return true;
    return false;
}

int main() {
    while(~scanf("%d%d", &n, &k)) {
        sum = 0.0;
        for(int i = 1; i <= n; i++) {
            scanf("%lf", &len[i]);
            // ma = std::max(ma, len[i]);
            sum += len[i];
        }

        if(sum < k * 0.01) {
            printf("0.00\n");
            continue;
        }
        double mid;
        std::sort(len + 1, len + n + 1);
        r = len[n];
        l = 0.01;
        for(int i = 0; i < 200; i++) {
            mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        printf("%.2f\n", floor(l * 100) / 100.0);
    }
    return 0;
}