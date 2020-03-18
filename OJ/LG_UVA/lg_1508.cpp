#include <cstdio>
#define N 205
#define K 3
const int dx[K] = {-1, -1, -1};
const int dy[K] = {-1, 0, 1};

int grid[N][N], dp[N][N];
int n, m, ans;

inline int max(int x, int y)
{
	return (x > y)? x: y;
}

int dfs(int x, int y)
{
	int t = 0;
	if (dp[x][y])
		return dp[x][y];
	for(int i = 0; i < K; i++)
	{
		int nx = x+dx[i], ny = y+dy[i];
		if (nx > 0 && ny > 0 && ny <= m)
		{
			int tmp = dfs(nx, ny)+grid[x][y];
			t = max(t, tmp);
		}
	}
	dp[x][y] = t;
	return t;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &grid[i][j]);
	for(int i = 1; i <= m; i++)
		dp[1][i] = grid[1][i];
	dfs(n+1, m/2+1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans = max(ans, dp[i][j]);
	printf("%d\n", ans);
	return 0;
}