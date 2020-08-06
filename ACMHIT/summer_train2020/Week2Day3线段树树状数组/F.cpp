#include <cstdio>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <algorithm>
typedef long long ll;
const int N = 3e4 + 55;
const int M = 1e6 + 5;

int n, m;
ll c[N], a[N];
std::unordered_map<ll, int > ma;

struct Query {
    int l, r, id;
    ll ans;
} q[M];

inline bool cmp1(Query x, Query y) { return x.r < y.r; }
inline bool cmp2(Query x, Query y) { return x.id < y.id; }

inline int lowbit(int x) { return x & (-x); }

inline void insert(int x, ll val) {
    for(int i = x; i <= n; i += lowbit(i)) c[i] += val;
}

inline ll sum(int k) {
    ll ans = 0;
    for(int i = k; i; i -= lowbit(i))
        ans += c[i];
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        ma.clear();
        for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        scanf("%d", &m);
        for(int i = 1; i <= m; i++) 
            scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
        int t = 1;
        std::sort(q + 1, q + m + 1, cmp1);
        for(int i = 1; i <= n; i++) {
            if(ma.count(a[i])) insert(ma[a[i]], -a[i]);
            insert(i, a[i]);
            ma[a[i]] = i;
            while(i == q[t].r)
                q[t].ans = sum(i) - sum(q[t].l - 1), t++;
        }
        std::sort(q + 1, q + m + 1, cmp2);
        for(int i = 1; i <= m; i++)
            printf("%lld\n", q[i].ans);
    }

    return 0;
}