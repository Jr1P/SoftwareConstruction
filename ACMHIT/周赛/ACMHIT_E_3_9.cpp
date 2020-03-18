#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN = 300;
int t, n, num[MAXN], now = 0, ans = 0;
bool flag[MAXN];

inline void update(int x)
{
	if (x % n == 0)
	{
		flag[x+n] = 0;
		flag[x+n-1] = 0;
	}
	else
	{
		flag[x] = 0;
		flag[x+1] = 0;
		flag[x+n] = 0;
		flag[x+n+1] = 0;
	}
}

inline void unup(int x)
{
	if (x % n == 0)
	{
		flag[x+n] = 1;
		flag[x+n-1] = 1;
	}
	else
	{
		flag[x] = 1;
		flag[x+1] = 1;
		flag[x+n] = 1;
		flag[x+n+1] = 1;
	}
}

void dfs(int x)
{
	if(x > n * n)
		return ;
	update(x);
	now += num[x];
	if (now > ans) ans = now;
	if(flag[x+2]){
		dfs(x+2);
		unup(x+2);
		now -= num[x+2];
	}
	if(flag[x+3]){
		dfs(x+3);
		unup(x+3);
		now -= num[x+3];
	}
	if(flag[x+2+n]){
		dfs(x+2+n);
		unup(x+2+n);
		now -= num[x+2+n];
	}
	if(flag[x+3+n]){
		dfs(x+3+n);
		unup(x+3+n);
		now -= num[x+3+n];
	}
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		ans = 0;
		now = 0;
		scanf("%d", &n);

		for(int i = 1; i <= n*n; i++)
		{
			scanf("%d", &num[i]);
			flag[i] = 1;
		}
		dfs(1);
		now = 0;
		dfs(2);
		now = 0;
		dfs(1+n);
		now = 0;
		dfs(2+n);
		printf("%d\n", ans);
	}
	return 0;
}