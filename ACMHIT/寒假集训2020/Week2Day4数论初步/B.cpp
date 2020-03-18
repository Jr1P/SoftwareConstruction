#include <cstdio>
#include <vector>
#include <cmath>

const int N = 1e6 + 5;
typedef long long ll;

bool check[N];
std::vector<ll> prime;

ll n;

void shai() {
    check[1] = false;
    for (ll i = 2; i < N; ++i)
        if (!check[i]) {
            prime.push_back(i);
            for (ll j = i * i; j <= n; j += i)
                check[j] = 1;
        }
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    shai();
    while(t--) {
        bool f = false;
        scanf("%lld", &n);
        int cnt;
        for(ll i : prime) {
            cnt = 0;
            if(n < i) break;
            while(n % i == 0) {
                n /= i;
                cnt++;
                if(cnt == 2) {
                    f = true;
                    break;
                }
            }
            if(f) break;
        }
        if(f) printf("Case %d: No\n", ++kase);
        else {
            if(n > 1) {
                ll tmp = sqrt(n);
                if(tmp * tmp == n)
                    printf("Case %d: No\n", ++kase);
                else
                    printf("Case %d: Yes\n", ++kase);
            }
            else printf("Case %d: Yes\n", ++kase);
        }
    }
	return 0;
}