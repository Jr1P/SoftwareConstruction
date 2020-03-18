#include <iostream>
#include <cstdio>
#define BAL 7500
#define N 25

int dp[N][(BAL << 1) + 1];
int n, g;
int c[N], w[N];

int main() {  
	scanf("%d%d", &n, &g);
	for(int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	for(int i = 1; i <= g; i++)
		scanf("%d", &w[i]);
 	dp[0][BAL] = 1;
  	for(int i = 1; i <= g; i++)
		for(int j = 0; j <= (BAL << 1); j++)
			if(dp[i - 1][j])
				for(int k = 1; k <= n; k++)
					dp[i][j + w[i] * c[k]] += dp[i - 1][j];
 	printf("%d\n", dp[g][BAL]);
	return 0;
}
