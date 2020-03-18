#include <cstdio>
#define N 100005

int a[N];
int l, r, cnt, n, m, ans;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a+i);
		r += a[i];
		l = (l < a[i])? a[i]: l;
	}
	while (l < r)
	{
		if (l == r-1)
		{	
			int s = 0;
			cnt = 1;
			ans = l;
			for(int i = 1; i <= n; i++)
			{
				if (s+a[i]>ans)
				{
					cnt++;
					s = 0;
				}
				s += a[i];
			}
			if (cnt > m)
				ans = r;
			else
				ans = l;
			break;
		}
		int s = 0;
		cnt = 1;
		ans = (l+r)>>1;
		for(int i = 1; i <= n; i++)
		{
			if (s+a[i]>ans)
			{
				cnt++;
				s = 0;
			}
			s += a[i];
		}
		if (cnt > m)
			l = ans;
		else
			r = ans;
	}
	if (l == r)
		ans = l;
	printf("%d\n", ans);
	return 0;
}