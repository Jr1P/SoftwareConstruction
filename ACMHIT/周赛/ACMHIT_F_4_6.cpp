#include <stdio.h>
using namespace std;
const int MAXL = 1e5+5;

int main()
{
	int n, num, min = 0x7fffffff, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		if ((num & 1) == 1 && (num < min))
			min = num;
		sum += num;
	}
	if (sum & 1) sum -= min;
	printf("%d\n", sum);	
	return 0;
}