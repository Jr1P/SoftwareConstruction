#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000050
typedef long long ll;

ll n, k;
ll a[N];

inline ll read()
{
    ll x = 0;
    char c = getchar();
    bool flag = 0;
    while(c < '0' || c > '9')
    {
   		if(c == '-')
   			flag = 1;
   		c = getchar();
   	}
    while(c >= '0' && c <= '9')
    {
    	x = (x << 3) + (x << 1) + (c ^ 48);
    	c = getchar();
    }
    return flag ? -x : x;
}


int main()
{
	while(scanf("%lld", &n) != EOF)
	{
		for(int i = 1; i <= n; i++)
			a[i] = read();
		sort(a+1, a+n+1);
		k = (n*(n-1)>>1)+1;
		k >>= 1;
		ll l = 0, r = a[n];
		int cnt = 0;
		while(l < r)
		{
			if(l == r-1)
				break;
			cnt = 0;
			ll mid = (l+r)>>1;
			for(int i = 2; i <= n; i++)
			{
				if (a[i]-mid <= 0)
					cnt = cnt+(i-1);
				else
					cnt = cnt+i-(lower_bound(a+1, a+1+n, a[i]-mid)-a);
			}
			if (cnt >= k)
				r = mid;
			else 
				l = mid;
		}
		cnt = 0;
		for(int i = 2; i <= n; i++)
		{
			if (a[i]-l <= 0)
				cnt += i-1;
			else
				cnt = cnt+i-(lower_bound(a+1, a+1+n, a[i]-l)-a);
		}
		if(cnt < k)
			l = r;
		printf("%lld\n", l);
	}
	return 0;
}