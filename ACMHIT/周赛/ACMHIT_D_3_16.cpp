#include <iostream>
using namespace std;
// MAXN = 1e18

int main()
{
	short T;
	unsigned long long n, sum, a, b, c, num;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
		cin >> n;
		if (n < 3)
			cout << '1' << '\n';
		else if (n < 6)
			cout << '2' << '\n';
		else
		{
			num = 2;
			a = 1; 
			b = 2;
			c = 3;
			sum = 3;
			while (n >= sum)
			{
				num++;
				sum += c;
				a = b;
				b = c;
				c = a + b;
			} 
			num--;
			cout << num << '\n';
		}
	}
	return 0;
}