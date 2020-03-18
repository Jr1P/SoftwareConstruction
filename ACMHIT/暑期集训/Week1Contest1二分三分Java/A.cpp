#include <cstdio>
#define N 100050
typedef long long ll;

int n;

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		if (n % 2 == 1)
			printf("Ehab\n");
		else
			printf("Mahmoud\n");
	}

	return 0;
}