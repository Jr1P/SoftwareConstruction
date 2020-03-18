#include <cstdio>
#define N 1005

int n;
int dp[N][N], num[N][N], ans;

inline int max(int x, int y)
{
	return (x > y)? x: y;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d", &num[i][j]);
	dp[1][1] = num[1][1];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+num[i][j];
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[n][i]);
	printf("%d", ans);
	return 0;
}