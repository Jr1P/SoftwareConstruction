#include <cstdio>
#define N 1050

int n, a, c, b, d, t;

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
		int sum = a+b+c+d;
		if(n % 2 == 0)
			n++;
		if(sum < (n+1)/2)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}