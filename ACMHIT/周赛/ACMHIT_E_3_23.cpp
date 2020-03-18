#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 100000 + 30;

int main()
{
	int id, n, m, flag[MAXN], a[MAXN], cnt[MAXN], f[MAXN], maxf = 0;
	memset(cnt, 0, sizeof(cnt));
	memset(f, 0, sizeof(f));
	memset(flag, 0, sizeof(flag));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] <= m) cnt[a[i]]++;
	}
	for(int i = 1; i <= n; i++)
	{
		if ((a[i] <= m) && (!flag[a[i]]))
			for(int j = a[i]; j <= m; j += a[i])
			{
			  	 f[j] += cnt[a[i]];
				 if(maxf < f[j])
				 {
				 	maxf = f[j];
				 	id = j;
				 }
			}
		if (a[i] <= m) flag[a[i]] = 1;
	}
	printf("%d %d\n", id, f[id]);
	for(int j = 1; j <= n; j++)
		if (id % a[j] == 0)
			printf("%d ", j);
	return 0;
}