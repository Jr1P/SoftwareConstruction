#include <cstdio>
#include <algorithm>
using namespace std;
#define N 5000
#define M 20000
//
int n, m;
int w[N], d[N];
int dp[M];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) 
		scanf("%d%d", &w[i], &d[i]);
	for(int i = 1; i <= n; i++)
		for(int j = m; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j-w[i]]+d[i]);
	printf("%d\n", dp[m]);
	return 0;
}