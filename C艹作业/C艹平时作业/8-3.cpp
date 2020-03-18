#include<iostream>
#define N 5
using namespace std;

int main()
{
	int num_class[N], num_pass[N];
	int **p = new int* [N];
	cout << "Input the number of each class: ";
	for(int i = 0; i < N; i++)
	{
		cin >> num_class[i];
		num_pass[i] = 0;
	}
	for(int i = 0; i < N; i++)
	{
		cout << "Input the score of " << num_class[i] << " student(s) in class" << i+1 << ": ";
		*(p+i) = new int [num_class[i]];
		for(int j = 0; j < num_class[i]; j++)
		{
			cin >> *(*(p+i)+j);
			if (*(*(p+i)+j) >= 60)
				num_pass[i]++;
		}
	}
	for(int i = 0; i < N; i++)
		cout << num_pass[i] << " student(s) in class" << i+1 << " have passed English examination." << endl;
	for (int i = 0; i < N; i++)
		delete[] *(p+i);
	delete[] p;
	return 0;
}