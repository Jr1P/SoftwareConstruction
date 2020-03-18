#include <cstdio>
#define N 3000300
//lg_3811

typedef long long ll;
ll inv[N];
ll n, p;

int main()
{
	scanf("%lld%lld", &n, &p);
	inv[1] = 1;
	printf("1\n");
	for (ll i = 2; i <= n; ++i)
	{
		inv[i] = (p-p/i)*inv[p%i]%p;
		printf("%lld\n", inv[i]);
	}
	return 0;
}