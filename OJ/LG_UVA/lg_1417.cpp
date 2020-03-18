#include <cstdio>
#define N 55
#define T 100005

int a[N], b[N], c[N], dp[];
int n, t;

int main()
{
	scanf("%d%d", &t, &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", a+i);
	for(int i = 1; i <= n; i++)
		scanf("%d", b+i);
	for(int i = 1; i <= n; i++)
		scanf("%d", c+i);

	return 0;
}