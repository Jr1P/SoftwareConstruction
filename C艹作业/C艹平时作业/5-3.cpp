#include <iostream>
#include <iomanip>
//#include <string.h>
using namespace std;
//jr.P

int main()
{
	const int PEOPLE = 5, PRODUCTS = 6;
	double v, totalSales, productSales[PRODUCTS] = {0.0};
	double value[PEOPLE][PRODUCTS] = {0.0};
	int sp, pr;
	//memset(value, 0.0, sizeof(value));
	cout << "Enter the sales person (1-4), "
		<< "product number (1-5)\nand total sales."
		<< "Enter -1 for the sales person to end input.\n";
	cin >> sp;
	while( sp != -1) {
		cin >> pr >> v;
		value[sp][pr] += v;
		cin >> sp;
	}
	cout << "\nThe total sales for each sales person "
		<< "are displayed\nat the end of each row,"
		<< "and the total sales for each\nproduct "
		<< "are displayed at the bottom of each column.\n"
		<< setw(10) << 1 << setw(10) << 2
		<< setw(10) << 3 << setw(10) << 4
		<< setw(10) << 5 << setw(12) << "Total\n"
		<< setiosflags( ios::fixed | ios:: showpoint );

	for( int i = 1; i < PEOPLE; ++i ) {
		totalSales = 0.0;
		cout << i;
		for (int j = 1; j < PRODUCTS; ++j ) {
			cout << setw(10) << setprecision(2)
				<< value[i][j];
			productSales[j] += value[i][j];
			totalSales += value[i][j];
		}

		cout << setw(10) << setprecision(2)
			<< totalSales << '\n';
	}

	cout << "\nTotal" << setw(6) << setprecision(2)
		<< productSales[1];

	for( int j = 2; j < PRODUCTS; ++j )
		cout << setw(10) << setprecision(2)
			<< productSales[j];

	cout << endl;
	return 0;
}