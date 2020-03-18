#include <cstdio>
#include <algorithm>
using namespace std;
#define M 50

int dp[M][M][M][M];
int num[5], v[500];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for(int i = 1; i <= m; i++) {
		int a;
		scanf("%d", &a);
		num[a]++;
	}
	for(int i = 0; i <= num[1]; i++)
		for(int j = 0; j <= num[2]; j++)
			for(int k = 0; k <= num[3]; k++)
				for(int l = 0; l <= num[4]; l++){
					int d = 0;
					if(i >= 1) d = max(d, dp[i-1][j][k][l]);
					if(j >= 1) d = max(d, dp[i][j-1][k][l]);
					if(k >= 1) d = max(d, dp[i][j][k-1][l]);
					if(l >= 1) d = max(d, dp[i][j][k][l-1]);
					dp[i][j][k][l] = d+v[i*1+j*2+k*3+l*4+1];
				}
	printf("%d\n", dp[num[1]][num[2]][num[3]][num[4]]);
	return 0;
}