#include <cstdio>

int m;

bool check(int x)
{
	for(int i = 2; i*i <= x; i++)
		if(x%i == 0)
			return false;
	return true;
}

int main()
{
	while(scanf("%d", &m) != EOF)
	{
		int mid = m / 2;
		while(!check(mid) || !check(m-mid))
			mid--;
		printf("%d %d\n", mid, m-mid);
	}
	return 0;
}