#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define mem(a, b) memset(a, b, sizeof(a))
const int MAXN = 5e4+50;

int dp[MAXN][20], dp_m[MAXN][20];
int n, q;

void init() {
    mem(dp, 0);
    mem(dp_m, 127);
}

inline int max(int x, int y) {
	return (x > y) ? x: y;
}

inline int min(int x, int y) {
    return (x < y) ? x : y;
}

void ST() {
	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 1; i+(1<<j)-1 <= n; i++) {
			dp[i][j] = max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);	
            dp_m[i][j] = min(dp_m[i][j-1], dp_m[i+(1<<(j-1))][j-1]);
        }
}

inline int RMQ(int l, int r) {
	int k = log2(r-l+1);
	//while ((1<<(k+1)) <= r-l+1)
	//	k++;
	return max(dp[l][k], dp[r-(1<<k)+1][k]) - min(dp_m[l][k], dp_m[r-(1<<k)+1][k]);
}

int main() {
	while(scanf("%d%d", &n, &q) != EOF) {
        init();
        for(int i = 1; i <= n; i++) {
            scanf("%d", &dp[i][0]);
            dp_m[i][0] = dp[i][0];
        }
        ST();
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%d\n", RMQ(l, r));
        }
    }
	return 0;
}