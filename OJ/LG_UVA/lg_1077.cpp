#include <cstdio>
#define N 110
#define MOD 1000007

int n, m;
int a[N], dp[N][N];

inline int min(int x, int y)
{
	return (x<y)?x:y;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= min(j, a[i]); k++)
				dp[i][j] = (dp[i][j]+dp[i-1][j-k])%MOD;
	printf("%d\n", dp[n][m]);
	return 0;
}