#include <cstdio>
typedef long long ll;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;

ll fa[N], n, sum1[N], sum2[N], all1, all2, ans;

inline int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

inline void _unino(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == fy) return ;
    ans = (ans + mod - sum2[fx] * sum2[fy] % mod * (n - sum1[fx] - sum2[fx] - sum1[fy] - sum2[fy]) % mod) % mod;
    ans = (ans + mod - (sum2[fx] * sum1[fy] % mod + sum1[fx] * sum2[fy] % mod) % mod * (all2 - sum2[fx] - sum2[fy])) % mod;
    ans = (ans + mod) % mod;
    if(fx > fy) {
        fa[fx] = fy;
        sum1[fy] += sum1[fx];
        sum2[fy] += sum2[fx];
    }
    else if(fx < fy) {
        fa[fy] = fx;
        sum1[fx] += sum1[fy];
        sum2[fx] += sum2[fy];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);
        for(int i = 1; i <= n; i++) {
            fa[i] = i;
            sum1[i] = sum2[i] = 0;
            all1 = all2 = 0;
        }
        for(int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            if(a == 1) sum1[i] = 1, all1++;
            else sum2[i] = 1, all2++;
        }
        ans = 1ll * all2 * (all2 - 1) / 2 * all1 + 1ll * all2 * (all2 - 1) / 2 * (all2 - 2) / 3;
        ans %= mod;
        printf("%lld\n", ans);
        for(int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            _unino(u, v);
            printf("%lld\n", ans % mod);
        }
    }
    return 0;
}