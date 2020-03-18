#include <stdio.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
	ull n, ans;
	scanf("%lld", &n);
	ans = (n + 1)*n/2 - n + 1;
	printf("%lld\n", ans);
	return 0;
}