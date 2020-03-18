#include <cstdio>

int n;
int v[30][30];
long long ans = 0, max = 0;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			scanf("%d", &v[i][j]);
	for(int i = 1; i <= (1 << (n-1)); i++) {
		ans = 0;
		int er[30];
		for(int i = 0; i <= 30; i++) er[i] = 0;
		int now = i, cnt = n ,p = 0;
		while(now) {
			er[n-p] = now % 2;
			now >>= 1;
			p++;
		}
		for(int j = 1; j <= cnt; j++) {
			int f = er[j];
			for(int k = j+1; k <= cnt; k++) {
				if(f != er[k])
					ans += v[j][k];
			}
		}
		if (ans > max)
			max = ans;
	}
	printf("%lld\n", max);
	return 0;
}