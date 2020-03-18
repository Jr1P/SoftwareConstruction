#include <iostream>
using namespace std;
const int max = 1e6;

int gcd(int a, int b);

int main()
{
	int a, b, c = 0, n; //c!=b
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int j = b * 2; j < a; j = j + b)
			if (gcd(a, j) == b)
			{
				c = j;
				break;
			}
		cout << c << '\n';
	}
	return 0;
}

int gcd(int a, int b)
{
	int r;
	r = a % b;
	if (r == 0)
		return b;
	else return gcd(b, r);
}