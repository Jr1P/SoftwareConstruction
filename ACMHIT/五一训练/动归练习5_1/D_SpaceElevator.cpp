#include <cstdio>
const int MAXK = 401;
const int MAXC = 4001;
//h[i] <= 100, c[i] <= 10, a[i] <= 40000;
int h[MAXK], c[MAXK], a[MAXK], k, f[4001], sum_c = 0;

inline int max(int a, int b)
{
	return (a > b)?a:b;
}

int main()
{
	scanf("%d", &k);
	for(int i = 1; i <= k; ++i)
	{
		scanf("%d%d%d", &h[i], &a[i], &c[i]);
		sum_c += c[i];
	}
	int i, j, l;
	for(i = 1; i <= k; ++i)
		for(j = 1; j <= c[i]; ++j)
		{
			for(l = 1; l <= sum_c; ++l)
			{
				if(f[l] > a[i] || f[l-j]+h[i]*j > a[i] || l < j)
					break;
				f[l] = max(f[l], f[l-j]+h[i]*j);
			}
		}
	int ans = 0;
	for(i = 1; i <= sum_c; ++i)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}