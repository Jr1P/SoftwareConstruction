#include <iostream>
using namespace std;
const int MAXN = 100+1;
const int MOD = 100;
int dp[MAXN<<1][MAXN]; //dp[i][j]表示前i个放, j个红色的方案数

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	dp[1][1] = 1;
	for(int i = 2; i <= (n<<1); i++)
	{
		for(int j = (i+1)>>1; j <= i; j++)
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
	}
	cout << dp[n<<1][n] % MOD;
	return 0;
}