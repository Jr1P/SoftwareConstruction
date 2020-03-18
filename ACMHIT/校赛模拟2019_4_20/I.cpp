#include <iostream>
using namespace std;
int x, y, n, t;
int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n >= 37)
			cout << "Yes" << '\n';
		else 
			cout << "No" << '\n';
	}
	return 0;
}