#include <cstdio>
#define N 1000050
bool check[N];
int prime[N >> 1];
int phi[N], mu[N];
int tot, n, m;

int main() {
	// freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	phi[1] = 1;
	check[1] = true;
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!check[i]) {
			prime[++tot] = i;
			phi[i] = i - 1;
			mu[i] = -1;
		}
		for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
			check[i * prime[j]] = 1;
			if (i % prime[j]) {
				mu[i * prime[j]] = -mu[i];
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
			} else {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
		}
	}
	for (int i = 1; i <= 100; i++)
		printf("%d\n", i - phi[i]);
	return 0;
}