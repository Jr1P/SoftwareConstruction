#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t;
typedef long long ll;
ll n, a, b;

ll pr[5000];

bool check(ll x)
{
	for(ll i = 2; i*i <= x; i++)
		if(x % i == 0)
			return false;
	return true;
}

int main()
{
	int tim = 0;
	scanf("%d", &t);
	while(t--)
	{
		int cnt = 0;
		memset(pr, 0, sizeof(pr));
		scanf("%lld%lld%lld", &a, &b, &n);
		if(n == 1)
		{
			printf("Case #%d: %lld\n", ++tim, b-a+1);
			continue;
		}
		if(check(n))
			pr[++cnt] = n;
		for(ll i = 2; i*i <= n; i++) {
			if(n % i == 0) {
				if(check(i)) pr[++cnt] = i;
				if(check(n/i) && (n/i) != i) pr[++cnt] = n/i;
			}
		}
		sort(pr+1, pr+cnt+1);
		ll ans1 = 0, ans2 = 0;
		for(ll i = 1; i < ((long long)1 << cnt); i++)
		{
			ll p = i, h = 1, f = -1, m = 1;
			while(p) {
				if(p%2 == 1) {
					m = m*pr[h];
					f = -f;
				}
				h++;
				p >>= 1;
			}
			ans1 += f*(a-1)/m;
			ans2 += f*b/m;
		}
		ans1 = a-1-ans1;
		ans2 = b-ans2;
		printf("Case #%d: %lld\n", ++tim, ans2-ans1);
	}
	return 0;
}