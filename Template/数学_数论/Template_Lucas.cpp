#include <cstdio>
#define N 100010
//lg_3807
typedef long long ll;

int t;
ll n, m, p;

inline ll power(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if (b&1)
			ans = ans*(a%p)%p;
		a = (a%p)*(a%p);
		b >>= 1;
	}
	
	return ans;
}

inline ll inv(ll x) // x在模p意义下的乘法逆元
{
	return power(x, p-2);
}

ll C(ll a, ll b)
{
	if (a < b) return 0;
	ll up = 1, down = 1;
	for(int i = 1; i <= b; i++)
	{
		down = down*i%p;
		up = up*(a-i+1)%p;
	}
	return up*inv(down)%p;
}

inline ll Lucas(ll n, ll m)
{
	if (m == 0) return 1;
	return C(n%p, m%p)*Lucas(n/p, m/p)%p;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld%lld", &n, &m, &p);
		ll min = m;
		if (m > n)
			min = n;
		printf("%lld\n", Lucas(n+m, min));
	}
	return 0;
}