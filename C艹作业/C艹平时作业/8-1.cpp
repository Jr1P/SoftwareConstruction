#include<iostream>
using namespace std;
const char nf[] = "Not found";
const char hf[] = "These two numbers are "; 

int main()
{
	int n, sum;
	cout << "Input n: ";
	cin >> n;
	cout << "Input array: ";
	int *p = new int[n];
	for(int i = 0; i < n; i++)
		cin >> *(p+i);
	cout << "Input sum: ";
	cin >> sum;
	int *head = p, *tail = p+n-1;
	while (*head <= *tail)
	{
		if ((*head + *tail) == sum)
		{
			cout << hf << *head << " and " << *tail << '\n';
			delete[] p;
			return 0;
		}
		else if ((*head + *tail) > sum)
			tail--;
		else
			head++;
	}
	delete[] p;
	cout << nf << '\n';
	return 0;
}