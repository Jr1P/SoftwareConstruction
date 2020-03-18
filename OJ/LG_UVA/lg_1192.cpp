#include <cstdio>
#define M 100003
#define N 100005

int f[N];
int n, k;

int main()
{
	scanf("%d%d", &n, &k);
	f[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k && (i-j) >= 0 ; j++)
		{
			f[i] += f[i-j];
			f[i] %= M;
		}
	printf("%d\n", f[n]%M);
	return 0;
}