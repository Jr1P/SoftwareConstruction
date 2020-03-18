#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll M = 998244353;
const ll D = 1e6;
bool notprime[D+50];

int t, n, m;
ll cnt[D+50], a[D+50];
vector<ll> prime;

void esh(){
	for(ll i = 2; i <= D; i++) {
		if(!notprime[i])
			prime.push_back(i);
		for(ll j = 0; j < prime.size() && i*prime[j] <= D; j++) {
			notprime[i*prime[j]] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
}

int main()
{
	esh();
	scanf("%d", &t);
	while(t--) {
		ll l, r, k;
		scanf("%lld%lld%lld", &l, &r, &k);
		for(ll i = 0; i <= r-l; i++) {
			cnt[i] = 1;
			a[i] = i+l;
		}
		for(ll i : prime) {
			if (i*i > r) break;
			for(ll j = (l+i-1)/i*i; j <= r; j += i) {
				ll pos = j-l, tt = 0;
				while(a[pos] % i == 0) {
					tt++;
					a[pos] /= i;
				}
				cnt[pos] = cnt[pos]*(tt*k+1)%M;
			}
		}
		ll ans = 0;
		for(ll i = 0; i <= r-l; i++) {
			if(a[i] > 1)
				cnt[i] = (cnt[i]*(k+1))%M;
			ans = (ans+cnt[i])%M;
		}
		
		printf("%lld\n", ans);
	}
}