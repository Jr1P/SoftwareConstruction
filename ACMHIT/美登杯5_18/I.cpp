#include <cstdio>

int n, a, b, c, d, ans = 0;
int v[110];

int main()
{
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &v[i]);
		ans += v[i];
	}
	if (b > d)
	{
		int tmp = b;
		b = d;
		d = tmp;
		tmp = a;
		a = c;
		c = tmp;
	}
	if (ans >= c)
		ans -= d;
	else if(ans >= a)
		ans -= b;
	printf("%d\n", ans);
	return 0;
}