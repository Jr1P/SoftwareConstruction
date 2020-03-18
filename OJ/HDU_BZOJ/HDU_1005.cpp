//#include "pch.h"
#include <iostream>
const int MOD = 7; //以题目情况为准
using namespace std;
typedef long long ll;
struct Mat
{
	ll m[2][2];
}e, m0;
ll n, a, b;

inline void init()
{
	m0.m[0][0] = a, m0.m[0][1] = b;
	m0.m[1][0] = 1, m0.m[1][1] = 0;
	e.m[0][0] = 1, e.m[1][1] = 1;
}

Mat Mul(Mat x, Mat y)
{
	Mat c;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			c.m[i][j] = 0;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			for (int k = 0; k < 2; k++)
				c.m[i][j] = (x.m[i][k] * y.m[k][j] % MOD + c.m[i][j] % MOD) % MOD;
	return c;
}

Mat quickPower(Mat a, ll b)
{
	Mat ans = e;
	while (b)
	{
		if (b & 1)
			ans = Mul(ans, a);
		a = Mul(a, a);
		b >>= 1;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	while (1)
	{
		cin >> a >> b >> n;
		if (a == 0 && b == 0 && n == 0)
			break;
		init();
		if (n == 1 || n == 2)
			cout << '1' << '\n';
		else
		{
			Mat ans = quickPower(m0, n - 2);
			cout << (ans.m[0][0] + ans.m[0][1]) % MOD << '\n';
		}
	}
	return 0;
}