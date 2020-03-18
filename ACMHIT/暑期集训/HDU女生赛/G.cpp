#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);

int n;
double ans;

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		ans = sin(PI*2/n)*n/2;
		ans += sin(PI/n)*(1-cos(PI/n));
		printf("%.6f\n", ans);
	}
	return 0;
}