#include <cstdio>
#include <algorithm>
using namespace std;
#define N 300050
int a[N];
int d[N];

int n, k;
int ans; // 

bool cmp(int x, int y) {
	return x > y;
}
int main() {
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		d[i-1] = a[i]-a[i-1];
	}
	sort(d+1, d+n, cmp);
	ans = a[n]-a[1];
	for(int i = 1; i < k; i++)
		ans -= d[i];
	printf("%d\n", ans);
	return 0;
}