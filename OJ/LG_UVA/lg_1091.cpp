#include <iostream>
using namespace std;
const int MAXN = 105;
int dp[2][MAXN], n, height[MAXN], ans = 0;

inline int max(int x, int y)
{
	return (x>y)?x:y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> height[i];
	height[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			if (height[j] < height[i])
				dp[0][i] = max(dp[0][j]+1, dp[0][i]);
	height[n+1] = 0;
	for(int i = n; i >= 1; i--)
		for(int j = n+1; j > i; j--)
			if (height[j] < height[i])
				dp[1][i] = max(dp[1][j]+1, dp[1][i]);
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp[0][i]+dp[1][i]-1);
	cout << n - ans;
	return 0;
}