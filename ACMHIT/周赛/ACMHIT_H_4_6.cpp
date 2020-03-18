#include <stdio.h>
#include <math.h>
using namespace std;
const int MAXN = 1e5+5;

typedef long long ll;

int a[MAXN];

int main()
{
	int n, num;
	float total;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		total += a[i];
	}
	num = ceil(total/5);
	printf("%d\n", num);

	return 0;
}