#include <stdio.h>
using namespace std;

typedef long long ll;

int main()
{
	int t, a, b, total;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &a, &b);
		total = a+b;
		if ((a == b)||(a == b-1)||(a == b+1))
			printf("Ok\n");
		else
		{
			a = (a+b)>>1;
			b = total - a;
			printf("%d %d\n", a, b);
		}
	}
	return 0;
}