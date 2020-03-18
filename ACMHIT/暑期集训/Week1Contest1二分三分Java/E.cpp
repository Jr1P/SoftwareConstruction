#include <cstdio>
typedef long long ll;

ll n, k;

int main()
{
	while(scanf("%lld%lld", &n, &k) != EOF)
	{
		n--; k--;
		ll sum = k*(k+1)/2;
		if(sum < n)
			printf("-1\n");
		else if (sum == n)
			printf("%lld\n", k);
		else
		{
			ll now = 0, cnt = 0;
			ll l = 1, r = k;
			while(l <= r-1)
			{
				if(l == r-1)
					break;
				ll mid = (l+r)>>1;
				ll sum1 = (mid+1)*mid>>1;
				if(sum-sum1 < n)
					r = mid;
				else
					l = mid;
			}
			ll sum1 = (r+1)*r>>1;
			if(sum-sum1>=n)
				l = r;
			printf("%lld\n", k-l);
		}
	}
	return 0;
}