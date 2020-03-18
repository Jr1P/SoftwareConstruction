#include <cstdio>

typedef long long ll;
ll n;

int prime[20] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int cnt[100];

int main()
{
	while(1)
	{
		for(int i = 1; i <= 100; i++)
			cnt[i] = 1;
		ll ans = 1;
		scanf("%lld", &n);
		if (n == 0)
			break;
		int i = 1;
		for(; i < 20 && n >= prime[i] && n != 1; i++)
			while(n%prime[i] == 0) {
				cnt[prime[i]]++;
				n = n / prime[i];
			}
		for(i = 1; i < 20; i++)
			ans *= cnt[prime[i]];
		printf("%lld\n", ans);
	}
	return 0;
}