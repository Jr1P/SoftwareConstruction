#include <cstdio>
#define N 30

int gcd(int a, int b)
{
	return (a%b == 0)? b: gcd(b, a%b);
}

int main()
{
	int n, ans;
	scanf("%d", &n);
	scanf("%d", &ans);
	for(int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		if (x<0)
			x = -x;
		if (x)
			ans = gcd(ans, x);
	}
	printf("%d\n", ans);
	return 0;
}