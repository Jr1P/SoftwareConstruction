#include <cstdio>
#include <cstring>
// #define mem(a, b) memset(a, b, sizeof(a))

int a, b;
int dp[12][10], num[12];

inline int abs(int x) { return x >= 0 ? x : -x; }

int dfs(int pos, bool lead, int pre, bool limit) {
	if(pos == -1) return 1;
	if(!limit && !lead && dp[pos][pre] != -1) return dp[pos][pre];
	int up = limit ? num[pos] : 9;
	int ans = 0;
	for(int i = 0; i <= up; i++) {
		if(abs(pre - i) < 2 && !lead) continue;
		ans += dfs(pos - 1, lead && i == 0, i, limit && i == num[pos]);
	}
	if(!limit && !lead) dp[pos][pre] = ans;
	return ans;
}

int solve(int r) {
	int pos = 0;
	while(r) {
		num[pos++] = r % 10;
		r /= 10;
	}
	return dfs(pos - 1, true, 0, true);
}

int main() {
	memset(dp, -1, sizeof(dp));
	while(~scanf("%d%d", &a, &b)) {
		printf("%d\n", solve(b) - solve(a - 1));
	}
	return 0;
}
