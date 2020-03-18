#include <cstdio>
const int MAXN = 1e6+1;

int f[MAXN], inn[MAXN];

int main()
{
	int n, max = 0, cnt = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (max < n)
			max = n;

		inn[cnt] = n;
		cnt++;

	}
	f[0] = 1; f[1] = 2;
	for(int i = 2; i <= max; i++)
		f[i] = (f[i-1]+f[i-2])%3;
	for(int i = 0; i < cnt; i++)
		if(f[inn[i]] == 0)
			printf("yes\n");
		else
			printf("no\n");
	return 0;
}