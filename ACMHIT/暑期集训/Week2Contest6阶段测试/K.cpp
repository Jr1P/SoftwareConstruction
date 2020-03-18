#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 150050
typedef long long ll;

int n;
ll x, y;
ll tree[N], a[N], b[N];

inline ll lowbit(ll k) {return k&(-k);}
inline ll min(ll x, ll y) {return x>y?y:x;}

inline void modify(ll x, ll add) {
    for(ll i = x; i <= n; i += lowbit(i))
        tree[i] += add;
}

inline ll getSum(ll x) {
    ll ans = 0;
    for(ll i = x; i; i -= lowbit(i))
        ans += tree[i];
    return ans;
}

int main() {
    ll cnt = 0;
    while(scanf("%d%lld%lld", &n, &x, &y) != EOF) {
        cnt = 0;
        memset(tree, 0, sizeof tree);
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for(int i = 1; i <= n; i++) {
            scanf("%lld", a+i);
            b[i] = a[i];
        }
        sort(a+1, a+n+1);
        ll sz = unique(a+1, a+n+1)-a-1;
        for(int i = 1; i <= n; i++) {
            b[i] = lower_bound(a+1, a+sz+1, b[i])-a;
            modify(b[i], 1);
            cnt += i-getSum(b[i]);
        }
        printf("%lld\n", cnt*min(x, y));
    }
    return 0;
}