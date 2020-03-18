#include <cstdio>
#include <cstring>
const int MAXL = 100000+1;

int main()
{
	long long ans = 0;
	int l, r;
	//int l[MAXL], r[MAXL];
	char s[MAXL];
	int m;
	while(scanf("%s%d", s, &m)!= EOF)
	{	
		ans = 0;
		int len = strlen(s);
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d%d", &l, &r);
			ans += len-(r-l+1);
		}
		if(ans & 1)
			printf("Alice\n");
		else
			printf("Bob\n");
	}
	return 0;
}