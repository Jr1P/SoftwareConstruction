#include <cstdio>
#define N 65

int num[N];

int main()
{
	int n, k, len = 0, cnt = 0;
	scanf("%d%d", &n, &k);
	int nn = n;
	while(nn > 0)
	{
		num[++len] = (nn&1);
		nn >>= 1;
	}
	int i = len;
	while (cnt != k && i > 0)
	{
		if (num[i--] == 1)
		{
			cnt++;
			n -= (1<<i);
		}
	}
	if (n <= 0)
		printf("0\n");
	else
	{
		int ans = (1<<i)-n;
		printf("%d", ans);
	}
	return 0;
}