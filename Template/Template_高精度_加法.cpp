#include <cstdio>
#include <cstring>
const int MAXL = 120;
char x1[MAXL], x2[MAXL];
int a[MAXL], b[MAXL], c[MAXL];

inline int max(int x, int y)
{
	return (x > y)?x:y;
}

int main()
{
	int t, cnt = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s%s", x1, x2);
		int add = 0, len1 = strlen(x1), len2 = strlen(x2), len;
		len = max(len1, len2);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(int i = 0; i < len1; ++i) a[i] = x1[len1-i-1]-'0';
		for(int i = 0; i < len2; ++i) b[i] = x2[len2-i-1]-'0';
		for(int i = 0; i < len; ++i)
		{
			c[i] = a[i]+b[i]+add;
			add = c[i]/10;
			c[i] %= 10;
		}
		if(add > 0)
		{
			c[len] = add;
			len++;
		}
		printf("Case %d:\n%s + %s = ", ++cnt, x1, x2);
		for(int i = len-1; i >= 0; --i)
			printf("%d", c[i]);
		printf("\n");
		if (t)
			printf("\n");
	}
	return 0;
}