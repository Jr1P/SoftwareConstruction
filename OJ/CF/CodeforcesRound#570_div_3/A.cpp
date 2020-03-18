#include <cstdio>

int a, n, sum;

int main()
{
	scanf("%d", &a);
	n = a;
	while(1)
	{
		a = n; sum = 0;
		while(a)
		{
			sum += a%10;
			a /= 10;
		}
		if(sum % 4 == 0)
			break;
		n++;
	}
	printf("%d\n", n);
	return 0;
}