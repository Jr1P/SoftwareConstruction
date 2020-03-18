#include <cstdio>
#include <cstring>
#define mem(a, b) memset(a, b, sizeof(a))

int dp[65][130], num[65];
int a, b;

int dfs(int pos, int cha, bool limit, bool lead) {
	if(pos == -1) {
		if(!lead && cha >= 65) return 1;
		else return 0;
	}
	if(!lead && !limit && dp[pos][cha] != -1) return dp[pos][cha];
	int up = limit ? num[pos] : 1;
	int ans = 0;
	for(int i = 0; i <= up; i++) {
		if(lead && i == 0)
			ans += dfs(pos - 1, cha, limit && num[pos] == i, lead);
		else if(i == 0)
			ans += dfs(pos - 1, cha + 1, limit && num[pos] == i, lead);
		else
			ans += dfs(pos - 1, cha - 1, limit && num[pos] == i, false);
	}
	if(!limit && !lead) dp[pos][cha] = ans;
	return ans;
}

int solve(int r) {
	int pos = 0;
	while(r) {
		num[pos++] = r & 1;
		r >>= 1;
	}
	return dfs(pos - 1, 65, true, true);
}

int main() {
	mem(dp, -1);
	while(~scanf("%d%d", &a, &b))
		printf("%d\n", solve(b) - solve(a - 1));
	return 0;
}
