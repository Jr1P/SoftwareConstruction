#include <iostream>
//#include <cstring>
const int MOD = 1000000007; //以题目情况为准
const int MAXN = 100+1;
using namespace std;
typedef long long ll;
struct Mat {
	ll m[MAXN][MAXN];
}a, e;
//矩阵快速幂
ll n, b;

Mat Mul(Mat x, Mat y) {
	Mat c;
	for(int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c.m[i][j] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				c.m[i][j] = x.m[i][k]*y.m[k][j] % MOD + c.m[i][j] % MOD;
	return c;
}

Mat matrixFastPower(Mat a, ll b) {
	Mat ans = e;
	while (b) {
		if (b & 1)
			ans = Mul(ans, a);
		a = Mul(a, a);
		b >>= 1; 
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	// 如果题目给定输入矩阵, 则输入,如果输入矩阵是选手通过递推关系式得到的, 则直接赋值
	cin >> n >> b;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a.m[i][j];
	for(int i = 1; i <= n; i++)
		e.m[i][i] = 1;
	Mat ans = matrixFastPower(a, b);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			cout << ans.m[i][j] % MOD << ' ';
		cout << '\n';
	}
	return 0;
}

