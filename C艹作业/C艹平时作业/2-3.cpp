#include <iostream>
using namespace std;
//

int main()
{
	char op;
	float data1, data2, ans;
	cout << "please input the equation:" << endl;
	cin >> data1 >> op >> data2;
	switch (op)
	{
		case '+':
			ans = data1 + data2;
			break;
		case '-':
			ans = data1 - data2;
			break;
		case '*':
			ans = data1 * data2;
			break;
		case '/':
			if (data2 == 0)
			{
				cout << "Error!";
				return 0;
			}
			else
			{
				ans = data1 / data2;
			}
			break;
		default:
			cout << "Invalid input!";
	}
	cout << data1 << op << data2 << '=' << ans;
	return 0;
}