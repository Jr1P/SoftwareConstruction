#include <cstdio>
#include <cstring>
const int MAXN = 105;

int num[MAXN], dp[MAXN][MAXN];// num[]

inline int max(int a, int b)
{
	return (a>b)?a:b;
}

int main()
{
	int t, n ,k, a, b;
	scanf("%d", &t);
	while (t--)
	{
		int ans = 0;
		memset(dp, 0, sizeof(dp));
		scanf("%d%d%d%d", &n, &a, &b, &k);
		for(int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		dp[0][0] = num[0];
		if(n-1 <= a*k)
			for(int i = 0; i < n; i += a)
				ans += num[i];
		for(int i = 0; i < n; i++)
			for(int j = 1; j <= k; j++)
				for(int l = a; l <= b; l++)
					if(dp[i-l][j-1] && i >= l)
						dp[i][j] = max(dp[i][j], dp[i-l][j-1]+num[i]);
		for(int i = 1; i <= k; i++)
			ans = max(ans, dp[n-1][i]);
		printf("%d\n", ans);
	}
	return 0;
}