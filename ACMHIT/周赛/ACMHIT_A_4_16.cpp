#include <cstdio>

typedef long long ll;

int gcd(int a, int b)
{
	return (a%b == 0) ? b : gcd(b, a%b);
}

ll ksm(ll a, ll b)
{
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1) 
		ans *= a;
		a = a*a;
		b >>= 1; 
	}
	return ans;
}

int main()
{
	ll n, t;
	while (scanf("%lld%lld", &n, &t) != EOF)
	{
		ll ans1 = 0, ans2 = 0;
		for(int i = 1; i <= n; i++)
			ans1 += ksm(t, gcd(i, n));
		ans2 = ans1 / n;
		if((n&1) == 1)
		{
			ans1 += n*ksm(t, (n+1)/2);
		}
		else
		{
			ans1 += n/2*ksm(t, n/2+1);
			ans1 += n/2*ksm(t, n/2);
		}
		ans1 /= 2*n; 
		printf("%lld %lld\n", ans2, ans1);
	}
	return 0;
}