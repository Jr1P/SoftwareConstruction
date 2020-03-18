#include <cstdio>
const int MAXN = 1e6+1;
int a[MAXN];

int main()
{
	int n, t = 1, ans;
	scanf("%d", &n);
	while (n != 0)
	{
		ans = 0
		for (int i = 1; i<= n ;i++)
			scanf("%d", &a[i]);
		
		printf("Case %d: %d\n\n", t, ans);
		t++;
		scanf("%d", &n);
	}
	return 0;
}