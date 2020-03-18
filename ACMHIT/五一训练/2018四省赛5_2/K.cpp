#include <cstdio>

int h, r, ans;

int main()
{
	scanf("%d%d", &h, &r);
	int ans = 3*h*r*r+4*r*r*r;
	printf("%d", ans);
	return 0;
}