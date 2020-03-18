#include<cstdio>

typedef long long ll;

int d, t;
ll x;

ll pow(ll a, ll b)
{
	ll ans = 1;
	while(b)
	{
		if(b&1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	int cnt = 0;
	while(t--)
	{
		scanf("%d%lld", &d, &x);
		ll s = pow(2, d);
		if(x == 0)
		{
			printf("Case %d: YES 0\n", ++cnt);
			continue;
		}
		if(s*2 <= x)
			printf("Case %d: NO\n", ++cnt);
		else
		{
			ll pos = 0;
			int step = 0;
			while(pos != x && s != 0)
			{
				if(pos < x)
					pos += s;
				else if(pos > x)
					pos -= s;
				s >>= 1;
				step++;
			}
			if(pos != x)
				printf("Case %d: NO\n", ++cnt);
			else
				printf("Case %d: YES %d\n", ++cnt, step);
		}
	}
	return 0;
}