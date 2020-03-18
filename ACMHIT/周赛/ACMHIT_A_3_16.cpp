#include <iostream>
using namespace std;
const int M = 40;
int main()
{
	int n, fb[M], m;
	fb[1] = 1; fb[2] = 1;
	for (int i = 3; i < M + 1; i++)
		fb[i] = fb[i - 1] + fb[i - 2];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		cout << fb[m] << '\n';
	}
	return 0;
}