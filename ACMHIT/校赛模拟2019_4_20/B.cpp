#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double eps = 1e-6;

int t;
double a, b;

int main()
{
	double pi = 3.1415926535;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		int f = 1;
		cin >> a >> b;
		while (b - a >= 2)
			b -=2;
		double ans = 0.0;
		for(double i = a; b - i > eps; i += eps)
			ans += sin(sin(i*pi))*eps;
		if (ans < 0 && ans+0.00005 > eps)
			ans = 0.0000;
		cout << fixed << setprecision(4) << ans << '\n';
	}

	return 0;
}