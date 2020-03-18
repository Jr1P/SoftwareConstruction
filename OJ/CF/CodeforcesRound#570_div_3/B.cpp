#include <cstdio>
#define N 110

int q, k, a[N], n, l, r;

inline int max(int x, int y)
{
	return (x > y)? x: y;
}

inline int min(int x, int y)
{
	return (x < y)? x: y;
}

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		int l = 0, r = 0xfffffff;
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			r = min(r, a[i]+k);
			l = max(l, a[i]-k);
		}
		if (l > r)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n", r);
	}
	
	return 0;
}