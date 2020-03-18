#include <cstdio>

typedef long long ll;
int n;
ll sum;

int main()
{
	scanf("%d", &n);
	sum = 1LL*(n+1)*n/2;
	ll x = 2;
	while(sum % x != 0)
	{
		x++;
	}
	printf("%lld\n", sum/x);
	return 0;
}