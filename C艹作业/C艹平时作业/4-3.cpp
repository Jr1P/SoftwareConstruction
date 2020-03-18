#include <iostream>
using namespace std;
//preg.

float Legendre(float x, int n);

int main()
{
	int n;
	float x;
	cout<<"Please input x and n: ";
	cin >> x >> n;
	cout<<"The result is "<< Legendre(x, n) <<endl;
	return 0;
}

float Legendre(float x, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return x;
	else if (n > 1)
		return ((2 * n - 1) * x * Legendre(x, n - 1) 
				- (n - 1) * Legendre(x, n - 2)) / n;
	else return -1;
}