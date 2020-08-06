#include <cstdio>
#include <algorithm>

int n;
int a[105];
bool f[105], flag;

bool dfs(int len, int tt, int x) {
	if(len == 0 && x == 0) return true;
	if(len == 0 && x != 0) return dfs(tt, tt, x);
	if(len != 0 && x == 0) return false;
	int last = -1;
	for (int i = n; i; i--) {
		if (last == a[i]) continue;
		if (!f[i] && len >= a[i]) {
			f[i] = true;
			if(dfs(len - a[i], tt, x - 1)) return true;
			else last = a[i];
			f[i] = false;
			if (len == tt) break;
		}
	}
	return false;
}

int main() {
	while(1) {
		scanf("%d", &n);
		if(n == 0) break;
		int sum = 0;
		for(int i = 1; i <= n; i++) f[i] = false;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int ans = sum;
		std::sort(a + 1, a + n + 1);
		for(int i = 1; i <= sum ; i++) {
			if(sum % i || a[n] > i) continue;
			for(int j = 1; j <= n; j++) f[j] = false;
			if(dfs(i, i, n)) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}