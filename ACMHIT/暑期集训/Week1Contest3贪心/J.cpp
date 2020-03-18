#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll a, b, d, k;

ll gcd(ll x, ll y)
{
	return x%y == 0? y: gcd(y, x%y);
}

int main()
{
	while(cin >> a >> b) // 
	{
		ll ans = 0;
		if (a < b) {
			ll t = a;
			a = b;
			b = t;
		}
		d = a-b;
		ll g = gcd(a, b);
		ll lcm = a*b/g;
		if(lcm == a || lcm == b || g == d) {
			cout << "0\n";
			continue;
		}
		else {
			for(int i = 1; i*i <= d; i++)
			{
				if(d % i == 0)
					k = i-b%i;
				ll l = (a+k)/gcd(d, b+k)*(b+k);
				if(l < lcm)
				{
					ans = k;
					lcm = l;
				}
				ll dd = d/i;
				k = dd-b%dd;
				l = (a+k)/gcd(d, b+k)*(b+k);
				if(l < lcm)
				{
					ans = k;
					lcm = l;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}