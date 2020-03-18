#include <cstdio>
#include <cstring>

char s[5000];

int main()
{
	while(1)
	{
		int sum = 0;
		scanf("%s", s);
		if(s[0] == '0')
			break;
		int len = strlen(s);
		for(int i = 0; i < len; ++i)
			sum += s[i] - '0';
		int ans = 0;
		while(1)
		{
			while(sum)
			{
				ans += sum%10;
				sum /= 10;
			}
			if(ans < 10)
				break;
			else
			{
				sum = ans;
				ans = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}