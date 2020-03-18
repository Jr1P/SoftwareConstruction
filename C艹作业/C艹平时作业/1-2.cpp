#include <iostream>
#include <iomanip>
using namespace std;
//

int main()
{
	char c1[] = "###", c2[] = "#####" ,
		 c3[] = "#######", c4[] = "#########";
	cout << setw(5) << '#' << '\n';
	cout << setw(6) << c1 << '\n';
	cout << setw(7) << c2 << '\n';
	cout << setw(8) << c3 << '\n';
	cout << setw(9) << c4 << '\n';
	return 0;
}