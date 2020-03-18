#include <iostream>
#include <iomanip>
using namespace std;
#define UNIT 1.609344

int main()
{
	double kilo = 0, mile = 0;
	cout<<"Please enter the number of miles(positive number greater than zero): ";
	cin>> mile;
	kilo = mile * UNIT;
	cout<<setw(10)<<"Miles"<<setw(20)<<"Kilometres"<<endl;
	cout << mile << kilo <<endl;
	cout << setw(10) << mile << setw(20) << kilo << endl;
	cout << setfill('*') << setw(10) << mile << setw(20) << kilo << endl;
	cout << setfill(' ') << setw(10) << mile << setw(20) << kilo << endl;
	cout << setw(10) << mile << setw(10) << fixed << setprecision(2) << kilo << endl;
	return 0;

}