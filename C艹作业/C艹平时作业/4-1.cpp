#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define MAX 1e4

bool isPrime (int x);

int main()
{
	int num = 2, p = 1;
	cout << "The prime numbers from 1 to 10000 are:" << '\n';
	cout << setw(5) << '2' << setw(5) << '3';
	while (6 * p - 1 < MAX)
	{
		if (isPrime(6 * p - 1))
		{
			cout << setw(5) << 6 * p - 1;
			num++;
		}
		if (isPrime(6 * p + 1))
		{
			cout << setw(5) << 6 * p + 1;
			num++;
		}
		p++;
	}
	cout << '\n' << "There were " << num << " prime numbers";
	return 0;
}

bool isPrime (int x)
{
	for (int i = 2; i <= floor(sqrt(x)); i++) //floor 向下取整
		if (x % i == 0)
			return 0;
	return 1;
}