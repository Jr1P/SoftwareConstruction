#include <cstdio>
typedef long long ll;
#define N 100050

int T, n;
ll dp[N][2], k, t[N];

inline int min(int x, int y) {
	return x<y?x:y;
}

inline int max(int x, int y) {
	return x>y?x:y;
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d%lld", &n, &k);
		for(int i = 1; i <= n; i++)
			scanf("%lld", &t[i]);
		for(int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 0;
		dp[1][0] = k;
		dp[1][1] = k+t[1];
		for(int i = 2; i <= n; i++) {
			dp[i][0] = min(dp[i-1][0]+k, dp[i-1][1]+k);
			dp[i][1] = max(dp[i-1][1], dp[i][0])+t[i]; 
		}
		printf("%lld\n", dp[n][1]);
	}
	return 0;
}