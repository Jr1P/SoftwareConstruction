#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const int N = 1e5 + 2;

long long int a[N], r_a[N];
int t, n, k;

int main()
{
	scanf("%d", &t);
	for(int e = 1; e <= t; e++)
	{
		int tot = 0, r_tot = 0;
		long long ans = 0;
		scanf("%d %d", &n, &k);
		for(int i = 1; i <= n; i++)
		{
			long long int x; 
			scanf("%lld", &x);
			if(x > 0) a[++tot] = x;
			if(x == 0) continue;
			if(x < 0) r_a[++r_tot] = -x;
		}
		sort(a + 1, a + 1 + tot);
		sort(r_a + 1, r_a + 1 + r_tot);
		if(a[tot] >= r_a[r_tot])
		{
			ans += a[tot];

			int h = 0;
			long long maxn = 0;
			for(int i = r_tot; i > 0; i--)
			{
				if(h == 0) maxn = r_a[i];
				h++;
				if(h == k)
				{
					ans += maxn * 2;
					h = 0;
				}
			}
			if(h != 0) ans += maxn * 2;

			h = 0, maxn = 0;
			for(int i = tot - k; i > 0; i--)
			{
				if(h == 0) maxn = a[i];
				h++;
				if(h == k)
				{
					ans += maxn * 2;
					h = 0;
				}
			}
			if(h != 0) ans += maxn * 2;

			printf("%lld\n", ans);
		}
		else
		{
			ans += r_a[r_tot];
			int h = 0, maxn = 0;
			for(int i = tot; i > 0; i--)
			{
				if(h == 0) maxn = a[i];
				h++;
				if(h == k)
				{
					ans += maxn * 2;
					h = 0;
				}
			}
			if(h != 0) ans += maxn * 2;

			h = 0, maxn = 0;
			for(int i = r_tot - k; i > 0; i--)
			{
				if(h == 0) maxn = r_a[i];
				h++;
				if(h == k)
				{
					ans += maxn * 2;
					h = 0;
				}
			}
			if(h != 0) ans += maxn * 2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}