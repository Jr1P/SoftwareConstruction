#include <cstdio>
typedef long long ll;
const ll L = 1e9;
const ll R = 1e14;

int t;
ll p, q, ans;

inline bool check(ll x)
{
	for(ll i = 3; i*i <= x; i += 2) //
		if(x % i == 0) return false;
	return true;
}

inline ll QM(ll a, ll b) {
	ll ans = 0;
	while(b) {
		if(b&1) ans = (ans+a)%p;
		a = (a+a)%p;
		b >>= 1;
	}
	return ans;
}

inline ll quickP(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if (b&1) ans = QM(ans, a);
		a = QM(a, a);
		b >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &p);
		ll pos = p-2;
		while(1) {
			if(check(pos))
				break;
			pos -= 2;
		}
		//ll ans = p-1;
		ll tt = 1;
		for(ll i = pos+1; i < p-1; i++)
			tt = QM(tt, i);
		ll ni = quickP(tt, p-2);
		/*for(ll i = p-1; i > pos; i--) {
			ll ni = quickP(i, p-2);
			ans = QM(ans, ni)%p;
		}*/
		printf("%lld\n", ni);
	}
	return 0;
}