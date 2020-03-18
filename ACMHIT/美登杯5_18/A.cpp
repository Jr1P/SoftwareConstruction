#include <cstdio>
#include <cstring>
#define N 10010

int n, q, l, r;
char str[N];

int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", str);
	for(int i = 1; i <= q; i++)
	{
		scanf("%d%d", &l, &r);
		int ans = (r-l+2)*(r-l+1)/2;
		printf("%d\n", ans);
	}
	return 0;
}