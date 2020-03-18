#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200 //

int a[N][N], dp[N][N];
int m, n;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	dp[0][0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-1])+a[i][j];
	for(int i = 1; i <= n; i++)
		m = max(m, dp[n][i]);
	printf("%d\n", m);
	return 0;
}