#include <cstdio>
#define N 50005

long long m, n;
bool num[N];

int main()
{
	scanf("%lld%lld", &n, &m);
	long long cnt = n, p = 1;
	while(cnt > 0)
	{
		cnt--;
		long long s = cnt*(cnt-1)>>1;
		if (m <= s)
		{
			num[p] = true;
			printf("%d ", p++);	
		}
		else
		{
			printf("%lld ", p+m-s);
			num[p+m-s] = true;
			for(int i = n; i > 0; i--)
				if (!num[i])
					printf("%d ", i);
			break;
		}
	}
	return 0;
}