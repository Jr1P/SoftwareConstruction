#include <cstdio>
//快速幂 && 快速乘
//#define M 
typedef long long ll;

inline ll fastM(ll a, ll b) { // 快速乘
	ll ans = 0;
	while(b) {
		if(b & 1) ans = (ans + a);
		a = a + a; b >>= 1;
	}
}

inline ll fastPower(ll a, ll b) { // 快速幂，没写模
	ll ans = 1;
	while (b) {
		if (b & 1) 
			ans = fastM(ans, a);
		a = a * a; b >>= 1; 
	}
	return ans;
}

inline int pow(int a, int b, int p) { // a^b % p, 常数小点
	int ans = 1;
	while(b) {
		if(b & 1) ans = 1ll * ans * a % p;
		a = 1ll * a * a % p; b >>= 1;
	}
	return ans;
}

int main() {
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", fastPower(a, b));
	return 0;
}