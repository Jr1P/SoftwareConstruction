#include <cstdio>

int a, b, x, y;

int exgcd(int a, int b)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exgcd(b, a%b);
	int x2 = x, y2 = y;
	x = y2;
	y = x2-(a/b)*y2;
	return gcd;
}

int main()
{
	scanf("%d%d", &a, &b);
	exgcd(a, b);
	if (x <= 0)
		x += b;
	printf("%d\n", x);
	return 0;
}