#include <cstdio>
using namespace std;

typedef long long ll;

void quickPower(ll &a, ll &b)
{
	ll ans = 1;
	while(b)
	{
		if(b&1) ans = ans*a%10;
		a = a*a%10;
		b >>= 1;
	}
	a = ans%10;
}

int main()
{
	ll a, b;
	while (scanf("%lld %lld", &a, &b) != EOF)
	{
		a %= 10;
		quickPower(a, b);
		printf("%lld\n", a);
	}
	return 0;
}