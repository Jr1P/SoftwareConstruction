#include <cstdio>
#include <cmath>
#define N 100050

int n;

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		int ans = 0;
		for(int i = 2; i <= (int)sqrt(n); i++)
		{
			if(n % i == 0)
				ans++;
		}
		ans *= 2;
		ans++;
		if((int)sqrt(n)*(int)sqrt(n) == n)
			ans--;
		printf("%d\n", ans);
	}
	return 0;
}