#include <cstdio>
#include <cstring>

char s[1010];
int n, ans;

int main()
{
	scanf("%d%s", &n, s);
	for(int i = 0; i < strlen(s); i++)
		ans = (ans*10+s[i]-'0')%n;
	if (ans == 0) ans = n;
	printf("%d\n", ans);
	return 0;
}