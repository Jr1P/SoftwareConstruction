#include <iostream>
#include <string>
using namespace std;
const char c1[] = "-Sunday", c2[] = "-Monday", 
	  c3[] = "-Tuesday", c4[] = "-Wednesday",
	  c5[] = "-Thursday", c6[] = "-Friday",
	  c7[] = "-Saturday";
//tzk

int main()
{
	unsigned date;
	string str[] = {"Sunday", "Monday", "Tuesday", 
	"Wednesday", "Thursday", "Friday", "Saturday"};
	cout << "Input a number:";
	cin >> date;
	//if (date > 6 || date < 0)
	//	cout << "Invalid number!";
	switch ( date )
	{
		case 0:
			cout << date << c1;
			break;
		case 1:
			cout << date << c2;
			break;
		case 2:
			cout << date << c3;
			break;
		case 3:
			cout << date << c4;
			break;
		case 4:
			cout << date << c5;
			break;
		case 5:
			cout << date << c6;
			break;
		case 6:
			cout << date << c7;
			break;
		default:
			cout << date << "-Invalid number!";
	}
	//else
	//	cout << str[date] << '\n';
	return 0;
}