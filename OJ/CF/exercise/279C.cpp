#include <cstdio>
#define N 101050

int n, m;
int a[N], ans[N];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int i = 1;
	while(i < n) {
		int j = i;
		while(j < n && a[j] <= a[j+1]) j++;
		int k = j;
		while(k < n && a[k] >= a[k+1]) k++;
		for(; i < k; i++) ans[i] = k;
	}
	ans[n] = n;
	for(int i = 1; i <= m; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		if(ans[l] >= r) puts("Yes");
		else puts("No");
	}
	return 0;
}
