#include <cstdio>
#include <algorithm>
#define eps 1e-7
typedef long long ll;
const int N = 2025;

struct xie {
    double v;
    int p;
    bool operator < (const xie &b) const { return v<b.v; }
} k[4050];

ll ans, an;
int n, sy, y[N];
double x[N], x0[N], sx;
bool f[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf%d", x+i, x0+i, y+i);
        if(x[i] > x0[i]) std::swap(x[i], x0[i]);
        x[i] -= eps; x0[i] += eps;
    }
    for(int i = 1; i <= n; i++)
        for(int l = 0; l < 2; l++) {
            int tot = 0;
            sx = (l)? x[i]: x0[i]; sy = y[i];
            ans = std::max(ans, an=x0[i]-x[i]);
            for(int j = 1; j <= n; j++) {
                if(sy == y[j]) continue;
                k[tot++] = {(sx-x[j])/(sy-y[j]), j};
                k[tot++] = {(sx-x0[j])/(sy-y[j]), j};
            }
            std::sort(k, k+tot);
            for(int j = 0; j < tot; j++) {
                double tmp = x0[k[j].p]-x[k[j].p];
                f[k[j].p]^=1;
                an += f[k[j].p] ? tmp: -tmp+eps*3;
                ans = std::max(ans, an);
            }
        }
    printf("%lld\n", ans);
    return 0;
}