#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
#define N 200050

ll a[N], b[N];
ll n, c;

int main()
{
	while(scanf("%lld%lld", &n, &c))
	{
		ll cnt = 0;
		for(int i = 1; i <= 2*n-1; i++) {
			ll p;
			scanf("%lld", &p);
			if (i%2 == 1)
				a[(i+1)/2] += p;
			else
			{
				a[i/2] += p;
				a[i/2+1] += p;
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(a[i] < 0)
				continue;
			if(a[i] <= c)
			{
				cnt += a[i];
				a[i+1] -= a[i];
			}
			else
			{
				cnt += c;
				a[i+1] -= c;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}