#include <iostream>
using namespace std;
//preg.
int gcd(int a, int b); //最大公约数

int main()
{
	int a, b, GCD, LCM;
	cout << "Please input two integers: ";
	cin >> a >> b;
	GCD = gcd(a, b);
	LCM = a * b / GCD;
	cout << "The GCD of them is " << GCD << '\n';
	cout << "The LCM of them is " << LCM << '\n';
	return 0;
}

int gcd(int a, int b)
{
	int r;
	r = a % b;
	if (r == 0)
		return b;
	else 
		return gcd(b, r);
}