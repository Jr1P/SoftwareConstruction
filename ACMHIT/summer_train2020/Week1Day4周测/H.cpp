#include <cstdio>
#include <set>
#include <cmath>
const int N = 1e4 + 5;
const int mod = 1e6;
typedef long long ll;

std::set<ll > s, s2;

int main() {
    int n;
    ll ans = 0;
    s.clear(), s2.clear();
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        ll a, b;
        scanf("%lld%lld", &a, &b);
        if(a == 0) {
            if(s2.empty()) s.insert(b);
            else {
                std::set<ll>::iterator it = s2.lower_bound(b);
                if(it == s2.end()) it--;
                int d1 = abs(*it - b);
                if(it == s2.begin()) {
                    ans += d1; ans %= mod;
                    s2.erase(it);
                } else {
                    int d2 = abs(*--it - b);
                    if(d2 <= d1) {
                        ans += d2; ans %= mod;
                        // it--;
                        s2.erase(it);
                    } else {
                        ans += d1; ans %= mod;
                        ++it;
                        s2.erase(it);
                    }
                }
            }
        } else {
            if(s.empty()) s2.insert(b);
            else {
                std::set<ll>::iterator it = s.lower_bound(b);
                if(it == s.end()) it--;
                int d1 = abs(*it - b); 
                if(it == s.begin()) {
                    ans += d1; ans %= mod;
                    s.erase(it);
                } else {
                    int d2 = abs(*--it - b);
                    if(d2 <= d1) {
                        ans += d2; ans %= mod;
                        // it--;
                        s.erase(it);
                    } else {
                        ans += d1; ans %= mod;
                        ++it;
                        s.erase(it);
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}