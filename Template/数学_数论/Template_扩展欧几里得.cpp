#include <cstdio>
//扩展欧几里得算法求解方程 ax+by = gcd(a, b)
//用于求解不定方程、线性同余方程和乘法逆元

int a, b, x, y;

int exgcd(int a, int b) // 返回最大公约数
{
	if(!b)
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
	printf("gcd(a, b) = %d\n", exgcd(a, b));
	printf("x = %d, y = %d\n", x, y);
	return 0;
}