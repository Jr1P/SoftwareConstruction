#include <cstdio>
#include <cstring>

int n, t;
char c[20];

int main()
{
	scanf("%d", &t);
	int cnt = 0;
	while(t--)
	{
		scanf("%s", c);
		int len = strlen(c);
		if(len == 1)
		{
			printf("Case %d: %s\n", ++cnt, c);
			continue;
		}
		printf("Case %d: %s", ++cnt, c);
		for(int i = len-2; i >= 0; i--)
			printf("%c", c[i]);
		printf("\n");
	}
	return 0;
}