#include <iostream>
#include <cmath>
using namespace std;
const double PI = acos(-1);
const double E = 2.71828182846;

int main()
{
	double n;
	long long digNum;
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n <= 3)
			cout << '1' << '\n';
		else
		{
			digNum = ceil((log10((PI+PI)*n))/2 + n*(log10(n)-log10(E)));
			cout << digNum << '\n';
		}
	}
	return 0;
}