#include <cstdio>

long long n;

int main()
{
	while(scanf("%lld", &n) != EOF)
	{
		long long ans = 0;
		ans = 1LL*(n+11)*n/2+7;
		printf("%lld\n", ans);
	}
	return 0;
}