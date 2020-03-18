#include <cstdio>
const char NR[] = " no response";

char r[4][5] = {"1113", "2133", "2243", "2444"};
int n, m;

int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(n%4 == 0 && m%4 == 0)
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= m/4; j++)
					printf("%s", r[(i-1)%4]);
				printf("\n");
			}
		else
			printf("%s", NR);
	}
	return 0;
}