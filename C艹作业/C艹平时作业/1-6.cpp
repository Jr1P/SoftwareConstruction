#include <iostream>
using namespace std;
const char c1[] = "Enter two integers: ";
const char c2[] = " is a multiple of ";
const char c3[] = " is not a multiple of ";

int main()
{
	int a, b;
	cout << c1;
	cin >> a >> b;
	if ((a == 0) || (b == 0) || (a % b != 0))
	{
		cout << a << c3 << b;
	} 
	else 
	{
		cout << a << c2 << b;
	}
	return 0;
}