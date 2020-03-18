#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define N 105
#define S 210050
#define INF 0x7fffffff

map<int , int> mp;
int a[N], b[N];
int n, k, zsum, fsum, ans;
int dp[N][S];

inline int max(int x, int y) {
	return x>y?x:y;
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		b[i] = a[i]-k*b[i];
	}
	int m = n*1000;
	memset(dp, 128, sizeof(dp));
	dp[0][m] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = m*2; j >= b[i]; j--)
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-b[i]]+a[i]);
	if(dp[n][m] > 0) printf("%d\n", dp[n][m]);
	else printf("-1\n");
	return 0;
}