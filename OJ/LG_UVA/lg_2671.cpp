#include <cstdio>
// #include <vector>
// #include <algorithm>
using namespace std;
#define N 100050
#define MOD 10007

int n, m;
long long ans;
int number[N], col[N], cnt[2][N], sum[2][N];

inline int read()
{
	int x = 0;
	char c = getchar();
	bool flag = 0;
	while(c < '0' || c > '9')
	{
		if(c == '-')
			flag = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = (x<<3)+(x<<1)+(c^48);
		c = getchar();
	}
	return flag? -x: x;
}

int main()
{
	int n = read(), m = read();
	for(int i = 1; i <= n; i++)
	{
		number[i] = read();
		number[i] %= MOD;
	}
	for(int i = 1; i <= n; i++)
	{
		col[i] = read();
		sum[i%2][col[i]] += number[i];
		sum[i%2][col[i]] %= MOD;
		cnt[i%2][col[i]]++;
	}
	for(long long i = 1; i <= n; i++)
	{
		ans += (i%MOD)*sum[i%2][col[i]]%MOD;
		ans	+= (i%MOD)*((cnt[i%2][col[i]]-2)%MOD*number[i]+MOD)%MOD;
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}