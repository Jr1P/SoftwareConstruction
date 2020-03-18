#include <cstdio>
const int MOD = 200907; //以题目情况为准
const int MAXN = 4;
typedef long long ll;
struct Mat
{
	ll m[MAXN][MAXN];
}a, e;
//矩阵快速幂
ll n, b;

Mat Mul(Mat x, Mat y)
{
	Mat c;
	for(int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
			c.m[i][j] = 0;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			for(int k = 1; k <= 3; k++)
				c.m[i][j] = ((x.m[i][k]%MOD)*y.m[k][j] % MOD + c.m[i][j] % MOD)%MOD;
	return c;
}

Mat matrixFastPower(Mat a, ll b)
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
	a.m[1][1] = 1, a.m[1][2] = 2, a.m[1][3] = 1;
	a.m[2][1] = 1, a.m[2][2] = 0, a.m[2][3] = 0;
	a.m[3][1] = 0, a.m[3][2] = 0, a.m[3][3] = 1;
	while(1){
		scanf("%lld", &n);
		if(!n) break;
		if(n == 1)
		{
			puts("1");
			continue;
		}
		if(n == 2)
		{
			puts("2");
			continue;
		}
		for(int i = 1; i <= 3; i++)
			e.m[i][i] = 1;
		Mat ans = matrixFastPower(a, n-2);
		ll p = ans.m[1][1]*2+ans.m[1][2]+ans.m[1][3];
		p %= MOD;
		printf("%lld\n", p);
	}
	
	return 0;
}

