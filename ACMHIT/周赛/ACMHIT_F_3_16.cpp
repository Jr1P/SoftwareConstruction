#include <stdio.h>
using namespace std;
const int MAXN = 1e5;

int main()
{
	short T;
	int n, num[MAXN];
	bool flag1, flag2;
	scanf("%hd\n", &T);
	while (T--)
	{
		flag1 = false;
		flag2 = false;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
			if (num[i] == 0)
				flag1 = true;
			if (num[i] == 1)
				flag2 = true;
		}
		if (flag2 && flag1)
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}