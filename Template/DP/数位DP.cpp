// 数位DP板子题 hdu2089
#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))
const int M = 1000000;

int dp[10][2], num[10];

int dfs(int pos, int pre, int state, bool limit) {
	if(pos == -1) return 1;
	if(!limit && dp[pos][state] != -1) return dp[pos][state];
	int up = limit ? num[pos] : 9;
	int ans = 0;
	for(int i = 0; i <= up; i++) {
		if(pre == 6 && i == 2) continue;
		if(i == 4) continue;
		ans += dfs(pos - 1, i, i == 6, limit && i == num[pos]);
	}
	if(!limit) dp[pos][state] = ans;
	return ans;
}

int solve(int r) {
	int pos = 0;
	while(r) {
		num[pos++] = r % 10;
		r /= 10;
	}
	return dfs(pos - 1, -1, 0, true);
}

int main() {
	int l, r;
	mem(dp, -1);
	while(~scanf("%d%d", &l, &r)) {
		if(l == 0 && r == 0) break;
		printf("%d\n", solve(r) - solve(l - 1));
	}
	return 0;
}
