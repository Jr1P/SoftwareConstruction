#include <cstdio>
#define N 100010

const char c1[] = "First";
const char c2[] = "Second";

int n, q, cnt = 0;
int a[N<<1];
bool f[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", a+i);
		a[n+i] = a[i];
	}
	
	for(int i = 1; i<= n; i++)
	{
		if (a[i] != 1)
			cnt = 0;
		else
		{
			if (cnt != 0)
				cnt--;
			while(a[i+cnt] == 1 && cnt < n-1)
				cnt++;
		}
		if (cnt & 1)
			printf("%s\n", c2);
		else
			printf("%s\n", c1);
	}
	return 0;
}