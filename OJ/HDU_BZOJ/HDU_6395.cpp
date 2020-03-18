#include <cstdio>
#include <cmath>
const int MAXN = 100000000+1;
const int MOD = 1e9+7;

int n, t, a, b, c, d, p;

struct Mat
{
	int m[3][3];
}res, inn, e, f;

void init()
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(i == j)
				e.m[i][j] = 1;
			else
				e.m[i][j] = 0;
	inn.m[0][0] = d, inn.m[0][1] = c, inn.m[0][2] = p;
	inn.m[1][0] = 1, inn.m[1][1] = 0; inn.m[1][2] = 0;
	inn.m[2][0] = 0, inn.m[2][1] = 0; inn.m[2][2] = 1;
	f.m[0][0] = b, f.m[1][0] = a, f.m[2][0] = 1;
}

Mat Mul(Mat x, Mat y)
{
	Mat tmp;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			tmp.m[i][j] = 0;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			for(int k = 0; k < 3; k++)
				tmp.m[i][j] = (tmp.m[i][j]%MOD + x.m[i][k]*y.m[k][j]%MOD)%MOD;
	return tmp;
}

Mat quickPower(Mat &x, int y)
{
	Mat ans = e;
	while (y)
	{
		if(y&1)
			ans = Mul(ans, x);
		x = Mul(x, x);
		y >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &p, &n);
		init();
		if (n == 1)
			printf("%d\n", a);
		else if (n == 2)
			printf("%d\n", b);
		else 
		{
			res = quickPower(inn, n-2);
			res = Mul(res, f);
		}
		printf("%d\n", res.m[0][0]);
	}
	return 0;
}