//#include "pch.h"
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#define M 300005
#define N 50001
using namespace std;

int n, m, tot = 0;
int pos[N][16];
string str[N], dp[N][16];

void ST()
{
	for (int j = 1; (1<<j) <= n; j++)
		for (int i = 1; i+(1<<j)-1 <= n; i++)
			if (dp[i][j-1] <= dp[i+(1<<(j-1))][j-1])
			{
				dp[i][j] = dp[i+(1<<(j-1))][j-1];
				pos[i][j] = pos[i+(1<<(j-1))][j-1];
			}
			else
			{
				dp[i][j] = dp[i][j-1];
				pos[i][j] = pos[i][j-1];
			}
}

inline int RMQ(int l, int r)
{
	int k = log2((double)(r-l+1));
	if (k == 0)
		return l;
	if (dp[l][k-1] <= dp[r-(1<<k)+1][k])
		return pos[r-(1<<k)+1][k];
	else
		return pos[l][k];
}

int main()
{
	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
		for (unsigned j = 0; j < str[i].length(); j++)
			if (str[i][j] < 'a')
				dp[i][0] += (str[i][j]+32);
			else
				dp[i][0] += str[i][j];
		pos[i][0] = i;
	}
	ST();
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		int p = RMQ(l, r);
		cout << str[p] << '\n';
	}
	return 0;
}