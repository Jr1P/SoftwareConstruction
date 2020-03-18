#include <cstdio>
#include <cmath>
#define N 10050

int dp[N][20], f[N];
int n, k, ans;

inline int max(int x, int y) {
	return (x > y) ? x: y;
}

inline int min(int x, int y) {
    return (x < y) ? x: y;
}

void ST() {
	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 1; i+(1<<j)-1 <= n; i++)
			dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);	
}

inline int RMQ(int l, int r) {
	int k = log2(r-l+1);
	return max(dp[l][k], dp[r-(1<<k)+1][k]);
}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &dp[i][0]);
    ST();
    f[1] = dp[1][0];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k && j <= i; j++)
            f[i] = max(f[i-j]+RMQ(i-j+1, i)*j, f[i]);
    printf("%d\n", f[n]);
    return 0;
}