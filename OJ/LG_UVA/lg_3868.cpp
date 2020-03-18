#include <cstdio>
#define N 20

typedef long long ll;

ll k, x, Mul = 1, ans, y;
ll m[N], a[N], M[N];

ll exgcd(ll a, ll b)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a%b);
	ll x2 = x, y2 = y;
	x = y2;
	y = x2-(a/b)*y2;
	return gcd;
}

ll quickMul(ll a, ll b, ll mod)//快速乘
{
	ll ans = 0;
	while(b)
	{
		if(b&1)
			ans = (ans+a)%mod;
		a = (a+a)%mod;
		b >>= 1;
	}
	return ans;
}

/*ll Power(ll a, ll b, ll mod)
{
	ll ans = 1;
	while(b)
	{
		if (b&1)
			ans = ans*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return ans;
}*/

/*ll getphi(ll x)
{
	ll phi = x;
	for(int i = 2; i*i <= x; i++)
		if (x%i == 0)
		{
			phi = phi/i*(i-1);
			while(x%i == 0)
				x /= i;
		}
	if (x > 1)
		phi = phi/x*(x-1);
	return phi;
}*/

int main()
{
	scanf("%lld", &k);
	for(int i = 1; i <= k; i++)
		scanf("%lld", a+i);
	for(int i = 1; i <= k; i++)
	{
		scanf("%lld", m+i);
		Mul *= m[i];
	}
	for(int i = 1; i <= k; i++)
	{
		if (a[i] < 0)
			a[i] += m[i];
		M[i] = Mul/m[i];
	}
	for(int i = 1; i <= k; i++)
	{
		exgcd(M[i], m[i]);
		if (x < 0) x += m[i];
		ans = (ans+quickMul(quickMul(a[i], M[i], Mul), x, Mul))%Mul;
	}
	if (ans < 0)
		ans += Mul;
	printf("%lld\n", ans);
	return 0;
}
