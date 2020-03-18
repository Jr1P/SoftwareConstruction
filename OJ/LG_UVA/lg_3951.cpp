#include <cstdio>

typedef long long ll;

int main()
{
	ll a, b;
	scanf("%lld%lld", &a, &b);
	ll ans = a*b-a-b;
	printf("%lld\n", ans);
	return 0;
}