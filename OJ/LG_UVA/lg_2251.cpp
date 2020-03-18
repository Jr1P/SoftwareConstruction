#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 1e6+5;
//RMQ区间最值查询问题的ST算法实现, 本质DP, 本模板以最大值为例
//dp[i][j]表示从第i个数开始(包括i)的长度为2^j的区间内的最大值
//因区间长度一定为偶数, 状态转移方程为 dp[i][j] = max(dp[i][j-1], dp[i+2^(j-1)][j-1]);
//**本模板仅适用于静态区间的最值查询

int dp[MAXN][20], num[MAXN], n, m; //dp的第二维的大小只要保证2^(第二维大小) > n;

inline int min(int x, int y)
{
	return (x < y) ? x: y;
}

void ST()
{
	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 1; i+(1<<j)-1 <= n; i++)
			dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);	
}

inline int RMQ(int l, int r)
{
	int k = log2(r-l+1);
	//while ((1<<(k+1)) <= r-l+1)
	//	k++;
	return min(dp[l][k], dp[r-(1<<k)+1][k]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &dp[i][0]);
	ST();
	for (int i = 1; i <= n-m+1; i++)
		printf("%d\n", RMQ(i, i+m-1));
	return 0;
}