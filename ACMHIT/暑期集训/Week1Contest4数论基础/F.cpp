#include <cstdio>
#include <cstring>
#define N 100050
typedef long long ll;
const ll MOD = 1e9+7;

ll cnt0[N], cnt1[N];
int n, q;
char str[N];

inline ll fastp(ll a, ll b)
{
	ll ans = 1;
	while(b) {
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", str);
	ll len = strlen(str);
	for(ll i = 1; i <= len; i++) {
		if(str[i-1] == '0') {
			cnt0[i] = cnt0[i-1]+1;
			cnt1[i] = cnt1[i-1];
		} else {
			cnt0[i] = cnt0[i-1];
			cnt1[i] = cnt1[i-1]+1;
		}
	}
	while(q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		ll ans = ((fastp((long long)2, cnt1[r]-cnt1[l-1])-1)*fastp((long long)2, cnt0[r]-cnt0[l-1]))%MOD;
		printf("%lld\n", ans);
	}
	return 0;
}