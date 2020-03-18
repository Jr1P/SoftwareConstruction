#include <stdio.h>
using namespace std;

typedef long long ll;

inline long long max(long long x, long long y)
{
	return (x > y) ? x : y; 
}

int main()
{
	int t, f = -1;
	ll ans = 0, n;
	scanf("%lld", &t);
	while(t--)
	{
		ans = 0;
		scanf("%d", &n);  	
		if (n % 6 != 0 && n % 3 != 0 && n % 4 !=0)
		{
			printf("%d\n", f);
			continue;
		}
		if (n % 6 == 0){	
			ans = max(ans, n/2*n/3*n/6);
		}
		if (n % 3 == 0){
			ans = max(ans, n/3*n/3*n/3);
		}
		if (n % 4 == 0){
			ans = max(ans, n/4*n/4*n/2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}