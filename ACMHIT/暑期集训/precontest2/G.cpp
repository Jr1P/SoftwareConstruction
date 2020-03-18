#include <cstdio>
#include <cstring>
#define N 100050
#define MOD 1000000007

typedef long long ll;

char c[N];
int t;

int main()
{
	int cnt = 0;
	scanf("%d", &t);
	while(t--)
	{
		ll ans = 0, len;
		scanf("%lld%s", &len, c);
		for(ll i = 0; i < len; i++)
		{
			ll r = len-i-1;
			ll sum = (i+1)*(r+1)+(r+1)*(i*(i+1)/2)+(i+1)*(r*(r+1)/2);
			sum %= MOD;
			ans = ans+sum*c[i]%MOD;
			ans %= MOD;
		}
		printf("Case %d: %lld\n", ++cnt, ans);
	}
	return 0;
}