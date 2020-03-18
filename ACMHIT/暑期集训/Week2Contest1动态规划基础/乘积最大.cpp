#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

int k, n;
char str[50];
ll dp[50][10], c[50][50];

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", str);
	dp[1][0] = str[0]-'0';
	for(int i = 2; i <= n; i++)
		dp[i][0] = dp[i-1][0]*10+str[i-1]-'0';
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			for(int l = i; l <= j; l++)
				c[i][j] = c[i][j]*10+str[l-1]-'0';
	for(int j = 1; j <= k; j++)
		for(int i = j+1; i <= n; i++)
			for(int q = j+1; q <= i; q++)
				dp[i][j] = max(dp[i][j], dp[q-1][j-1]*c[q][i]);
	printf("%lld\n", dp[n][k]);
	return 0;
}