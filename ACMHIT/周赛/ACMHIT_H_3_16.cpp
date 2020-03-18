#include <stdio.h>
#include <string.h>
//#include <algorithm>
using namespace std;
const int MAXN = 10000 + 5;
const int MAXM = 5000 + 5;
const int MAX = 0x6effffff;

int a[MAXN], dp[MAXM][MAXN], s[MAXM][MAXN];

inline int square(int x)
{
	return x*x;
}
inline void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void qsort(int l, int r)
{
	int mid = a[(l + r) >> 1], i = l, j = r;
	do {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j)
		{
			swap(&a[i], &a[j]);
			i++;
			j--;
		}

	} while (i <= j);
	if (i < r) qsort(i, r);
	if (j > l) qsort(l, j);
}

int main()
{
	int t, n, m, temp, cas = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &m);
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[j]);
		qsort(1, n);
		memset(dp, 127, sizeof(dp));
		for (int i = 0; i <= m; i++)
		{
			dp[i][i] = 0;
			s[i][i] = i;
		}
		for (int i = m+1; i <= n; i++) s[m+1][i] = i;
		for (int len = 1; len < n; len++)
			for (int i = 1; i <= m; i++)
			{
				int j = i + len;
				if (j > n) break;
				for (int k = s[i][j-1]; k <= s[i+1][j]; k++)
				{
					temp = dp[i-1][k-1] + square(a[j] - a[k]);
					if (temp < dp[i][j])
					{
						dp[i][j] = temp;
						s[i][j] = k;
					}
				}
			}
		printf("Case %d: %d\n", ++cas, dp[m][n]);
	}
	return 0;
}