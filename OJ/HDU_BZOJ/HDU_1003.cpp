#include <cstdio>
const int MAXN = 1e5+5;

int a[MAXN];

int main()
{
	int t, n, cnt = 0;
	scanf("%d", &t);
	while(t--)
	{
		int l = 1, r = 1, max = 0x80000000, sum = 0, ll = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		for(int i = 1; i <= n; ++i)
		{
			if(sum < 0)
			{
				sum = a[i];
				ll = i;
			}
			else
				sum += a[i];
			if(sum > max)
			{
				max = sum;
				r = i;
				if(ll)
					l = ll;
			}
		}
		cnt++;
		printf("Case %d:\n%d %d %d\n", cnt, max, l, r);
		if (t)
			printf("\n");
	}
	return 0;
}