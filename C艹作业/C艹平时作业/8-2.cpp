#include<iostream>
using namespace std;
const char pn[] = "Positive number: ";
const char nn[] = "Negative number: "; 

int main()
{
	int n, zero = 0, Pos = 0, Neg = 0;
	cout << "Input array size n: ";
	cin >> n;
	cout << "Input array: ";
	float *p = new float[n];
	for(int i = 0; i < n; i++)
		cin >> *(p+i);
	float *head = p;
	while (head < p+n)
	{
		if (*head == 0)
			zero++;
		else if (*head < 0)
			Neg++;
		else
			Pos++;
		head++;
	}
	delete[] p;
	cout << pn << Pos << '\n';
	cout << nn << Neg << '\n';
	cout << "Zero: " << zero << '\n';
	return 0;
}