#include <cstdio>
#include <cstdlib>
#define N 15

int n, sum, cnt = 0, ans = 0;
bool vis[N];
int C[N][N], num[N];

void init()
{
	C[1][1] = 1;
	for(int i = 1; i <= n; i++)
		C[i][0] = 1;
	vis[1] = false;
	for(int i = 2; i <= n; i++)
	{
		vis[i] = false;
		for(int j = 1; j <= i; j++)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
}
/*
inline int calc()
{
	int ans = 0;
	int l = n>>1;
	for(int i = 0; i < l; i++)
		ans += C[n-1][i]*(num[i+1]+num[n-i]);
	if(n & 1)
		ans += C[n-1][l]*num[l+1];
	return ans;
}*/

inline bool pr()
{
	int l = n>>1;
	for(int i = 1; i <= l; i++)
		if (num[i] > num[n-i+1])
			return true;
	return false;
}

void dfs()
{
	if (ans > sum)
		return ;
	if (cnt == n && pr())
		return ;
	if(cnt == n && ans == sum)
	{
		for(int i = 1; i <= n; i++)
			printf("%d ", num[i]);
		printf("\n");
		exit(0);
	}
	for(int i = 1; i <= n; i++)
		if(!vis[i])
		{
			vis[i] = true;
			num[++cnt] = i;
			ans += C[n-1][cnt-1]*i;
			dfs();
			vis[i] = false;
			cnt--;
			ans -= C[n-1][cnt]*i;
		}
}

int main()
{
	scanf("%d%d", &n, &sum);
	if(n == 1)
		printf("1\n");
	else
	{
		init();
		dfs();
	}
	return 0;
}