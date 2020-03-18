#include <iostream>
using namespace std;
//

int main()
{
	int a, digit[6];
	cout <<"Enter a five-digit number: ";
	cin >> a;
	for (int i = 0; i < 5; i++)
	{
		digit[i] = a % 10;
		a /= 10;
	}
	for (int i = 4; i > 0; i--)
		cout << digit[i] << "  ";
	cout << digit[0] << endl;
	return 0;
}