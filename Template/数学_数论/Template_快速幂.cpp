#include <cstdio>
//快速幂 && 快速乘
//#define M 
typedef long long ll;

inline ll fastM(ll a, ll b)
{
	ll ans = 0;
	while(b) {
		if(b&1) ans = (ans+a);
		a = a+a;
		b >>= 1;
	}
}

inline ll fastPower(ll a, ll b)
{
	ll ans = 1;
	while (b) {
		if (b & 1) 
			ans = fastM(ans, a);
		a = a*a;
		b >>= 1; 
	}
	return ans;
}

int main()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);
	printf("%lld\n", fastPower(a, b));
	return 0;
}