#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 300
const ll MOD = 1e9+7;

int n, k;
int a[N], p;
ll ans, f[N];

ll fast(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b&1) ans = ans*a%MOD;
		a = a*a%MOD;
		b >>= 1;
	}
	return ans;
}

ll C(ll n, ll m) {
	ll ans = 1;
	for(int i = 1; i <= m; i++)
		ans = ((ans*(n-i+1)%MOD)*fast(i, MOD-2))%MOD;
	ans %= MOD;
	return ans;
}

void getf() {
	f[0] = 1; f[1] = 1; f[2] = 2; 
	for(int i = 3; i <= n; i++) {
		f[i] = fast(2, i);
		if(i % 2 == 0)
			f[i] = (f[i]-C(i, i/2)/2+MOD) % MOD; 
		else
			f[i] = (f[i]-C(i, i/2)+MOD)%MOD;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if(n == 1) {
		printf("1\n");
		return 0;
	}
	ans = 1; p = 1;
	sort(a+1, a+n+1);
	getf();
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= )
		if(a[i]-a[p] <= k) continue;
		ans = (ans*f[i-p])%MOD;
		p = i;
	}
	//if(p == 1)
		//p--;
	ans = ans*f[n-p+1]%MOD;
	printf("%lld\n", ans);
	return 0;
}