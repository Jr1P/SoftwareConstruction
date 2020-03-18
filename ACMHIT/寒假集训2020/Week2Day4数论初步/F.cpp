#include <cstdio>
#include <cstring>
#define N 100050
typedef long long ll;
const ll MOD = 1e9 + 7;

ll sum0[N], sum1[N];
int n, q;
char str[N];

inline ll qpow(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", str + 1);
	ll len = strlen(str + 1);
	for(ll i = 1; i <= len; i++) {
		if(str[i] == '0') {
			sum0[i] = sum0[i - 1] + 1;
			sum1[i] = sum1[i - 1];
		} else {
			sum0[i] = sum0[i - 1];
			sum1[i] = sum1[i - 1] + 1;
		}
	}
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		ll ans = ((qpow(2L, sum1[r] - sum1[l - 1]) - 1)
            * qpow(2L, sum0[r] - sum0[l - 1])) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}