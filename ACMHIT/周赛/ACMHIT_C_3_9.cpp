#include <stdio.h>
using namespace std;
const int MAXN = 20 + 5;

int main()
{
	int t, n, p[MAXN], cnt;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		cnt = 0;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &p[i]);
			if (p[i] > 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}