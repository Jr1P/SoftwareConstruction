#include <cstdio>
#define N 1000

int t, n;
int a[N];

int min(int a, int b) { return (a < b)? a: b; }

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		a[1] = 0;
		for(int i = 1; i <= n; i++) 
			scanf("%d", &a[i]);
		int dd1 = a[2] - a[1] - 1;
		int dd2 = a[n] - a[n-1] - 1;
		int ans = a[n] - a[1] - n + 1;
		ans -= min(dd1, dd2);
		printf("%d\n", ans);
	}
	return 0;
}