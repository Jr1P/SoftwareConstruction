#include <cstdio>
#include <cstdlib>
#define N 105

int grid[N][N];
int n, m, l = 0, r, ans;

inline int min(int x, int y)
{
	return (x < y)? x: y;
}

bool check(int x, int y, int len)
{
	for(int i = x; i-x < len; i++)
		for(int j = y; j-y < len; j++)
			if (!grid[i][j])
				return false;
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			scanf("%d", &grid[i][j]);
			if (grid[i][j])
				l = 1;
		}
	if (l == 0)
	{
		printf("0\n");
		exit(0);
	}
	r = min(n, m);
	while(l < r)
	{
		bool flag = false;
		bool lr = false;
		ans = (l+r)>>1;
		if (l == r-1)
		{
			lr = true;
			ans = r;
		}
		for(int i = 1; i+ans-1 <= n; i++)
		{
			for(int j = 1; j+ans-1 <= m; j++)
			{
				if (!grid[i][j])
					continue;
				if (check(i, j, ans))
				{
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}
		if (!lr)
		{
			if (flag)
			{
				l = ans;
				ans = l;
			}
			else
			{
				r = ans-1;
				ans = l;
			}
		}
		else
		{
			if (flag)
				ans = r;
			else
				ans = l;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}