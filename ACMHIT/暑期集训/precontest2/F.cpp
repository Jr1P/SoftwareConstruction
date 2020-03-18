#include <cstdio>
#define N 1000000

int t, n, cnt = 0;
bool f[N+50]; //f[i] == 0表示i是素数
int g[N+50], su[N];

inline int gcd(int x, int y)
{
	return (x%y==0)? y : gcd(y, x%y);
}

int main()
{
	f[2] = 0; g[1] = 1; 
	for(int i = 2; i <= N; i++)
		if(!f[i])
		{
			su[++cnt] = i;
			g[i] = 1;
			for(int j = i+i; j <= N; j += i)
				f[j] = 1;
		}
	for(int i = 1; i <= cnt; i++)
		for(int j = i; j <= cnt; j++)
			if((long long)1*su[i]*su[j] <= N)
				g[su[i]*su[j]] = 1;
			else
				break;
	for(int i = 2; i <= N; i++)
		g[i] += g[i-1];
	scanf("%d", &t);
	int cc = 0;
	while(t--)
	{
		scanf("%d", &n);
		int gg = gcd(n, g[n]);
		printf("Case %d: %d/%d\n", ++cc, g[n]/gg, n/gg);
	}
	return 0;
}