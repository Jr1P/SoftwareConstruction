#include <iostream>
#include <cmath>
using namespace std;
const int MAXM = 1e6+1;
const char WA[] = "Crossing the line";
int n, m, cnt[MAXM];

inline bool isPrime(int x)
{
	for(int i = 2; i <= (int)sqrt(x); i++)
		if (x % i == 0)
			return false;
	return true;
}

void work()
{
	int num = 2;
	for(int i = 6; i-1 <= m; i = i+6)
	{
		if (isPrime(i-1)) 
			num++;
		cnt[i-1] = num;
		if (isPrime(i+1) && (i+1 <= m))
			num++;
		cnt[i+1] = num;
	}
	for(int i = 4; i <= m; i++)
		if(!cnt[i])
			cnt[i] = cnt[i-1];
}

int main()
{
	ios::sync_with_stdio(false);
	int l, r;
	cin >> n >> m;
	cnt[1] = 0; cnt[2] = 1; cnt[3] = 2;
	work();
	while(n--)
	{
		cin >> l >> r;
		if (l < 1 || r > m)
			cout << WA << '\n';
		else
		{
			int ans = cnt[r]-cnt[l-1]; 
			cout << ans << '\n';
		}
	}
	return 0;
}