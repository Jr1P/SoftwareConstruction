#include <iostream>
#include <iomanip>
using namespace std;
//jr.P
inline void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	const int SIZE = 10;
	int a[SIZE] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
	int numberOfComp = 0;

	cout << "Data items in original order\n";
	for ( int i = 0; i < SIZE; ++i )
		cout << setw(4) << a[i];

	cout << "\n\n";
	/* Write bubble sort implementation here */
	for (int j = 0; j < SIZE - 1; j++)
	{
		cout<<"After pass "<< j <<": ";
		for (int k = 1; k < SIZE - j; k++)
		{
			numberOfComp++;
			if (a[k] < a[k-1])
				swap(a[k], a[k-1]);
			cout << setw(3) << a[k-1];
		}
		cout << setw(3) << a[SIZE -1 - j];
		cout << '\n';
	}
	cout << "\nData items in ascending order\n";
	for ( int j = 0; j < SIZE; ++j )
		cout << setw(4) << a[j];
	cout << "\nNumber of comparisons = " << numberOfComp << endl;
	return 0;
}