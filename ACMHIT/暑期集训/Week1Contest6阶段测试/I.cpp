#include <cstdio>
#include <algorithm>
using namespace std;

int t, n;
int a[1050];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		sort(a+1, a+n+1);
		if(n % 2 == 0) {
			for(int i = n; i > 2; i -= 2) {
				int x1 = a[1]+2*a[2]+a[i];
				int x2 = 2*a[1]+a[i]+a[i-1];
				ans += min(x1, x2);
			}
			ans += a[2];
		} else {
			for(int i = n; i > 3; i -= 2) {
				int x1 = a[1]+2*a[2]+a[i];
				int x2 = 2*a[1]+a[i]+a[i-1];
				ans += min(x1, x2);
			}
			ans += a[3]+a[1]+a[2];
		}
		printf("%d\n", ans);
	}
	return 0;
}