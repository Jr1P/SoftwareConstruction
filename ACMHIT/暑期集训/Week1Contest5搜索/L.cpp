#include <cstdio>
int n;

int main() {
	while(scanf("%d", &n)!= EOF) {
		long long ans = 0;
		for(int i = 1; i <= n; i++)
			ans += n/i;
		printf("%lld\n", ans);
	}
}