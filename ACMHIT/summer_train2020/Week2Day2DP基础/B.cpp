#include <cstdio>
#include <queue>
const int N = 1e4 + 5;
typedef long long ll;

struct Int {
    int val;
    bool operator < (const Int o) const {
        return val > o.val;
    }
    Int(int val) : val(val) {}
};

int cost[N], s, y[N];
std::priority_queue<Int > q;

int main() {
    int n;
    ll ans = 0;
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i++) scanf("%d%d", &cost[i], &y[i]);
    q.push(Int(cost[1]));
    for(int i = 1; i <= n; i++) {
        Int mm = q.top();
        ans += 1ll * (mm.val + s * (i - 1)) * y[i];
        q.push(Int(cost[i + 1] - s * i));
    }
    printf("%lld\n", ans);
    return 0;
}