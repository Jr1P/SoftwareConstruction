#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll M = 1e18;
#define N 300050

ll day[N];
ll a, b, c, l, r, t;

inline ll max(ll x, ll y) {
    return x>y?x:y;
}

inline ll gsc(ll a, ll b) {
    ll ans = 0;
    while(b) {
        if(b&1) ans = ans+a;
        if(ans > r || ans < 0) return -1;
        a = a+a;
        b >>= 1;
    }
    return ans;
}

inline ll qsm(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(a < 0) return -1;
        if(b&1) ans = gsc(ans, a);
        if(ans == -1) return -1;
        a = gsc(a, a);
        b >>= 1;
    }
    return ans;
}

int main() {
    int cnt = 0;
    scanf("%lld", &t);
    while(t--) {
        cnt = 0;
        scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &l, &r);
        for(int i = 0; i <= 60; i++) {
            ll A = qsm(a, i);
            if(A == -1) break;
            if(A == 1 && i == 1) break;
            for(int j = 0; j <= 60; j++) {
                ll B = qsm(b, j);
                if(B == -1) break;
                if(B == 1 && j == 1) break;
                for(int k = 0; k <= 60; k++) {
                    ll C = qsm(c, k);
                    if(C == -1) break;
                    if(C == 1 && k == 1) break;
                    ll d = A+B+C;
                    if(d > r) break;
                    day[++cnt] = d;
                }
            }
        }
        sort(day+1, day+cnt+1);
        ll ans = 0;
        for(int i = 0; i <= cnt; i++) {
            if(day[i+1] <= l) continue;
            if(day[i] >= r) break;
            ll s = day[i+1]-day[i]-1;
            if(day[i] < l-1) s -= l-day[i]-1;
            if(day[i+1] > r+1) s -= day[i+1]-r;
            ans = max(ans, s);
        }
        printf("%lld\n", ans);
    }
    return 0;
}