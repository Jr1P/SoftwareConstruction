#include <iostream>
using namespace std;
const int MAXN = 1e5;

int main()
{
	short T;
	unsigned long long ans = 0, E, N;
	cin >> T;
	for(int i = 0; i < T ; i++)
	{
		ans = 0;
		E = 0;
		cin >> N;
		E = N * (N - 1) / 2 * (N - 2) /3 * (N - 3) / 4;
		ans = E + N;
		cout << ans << '\n';
	}
	return 0;
}