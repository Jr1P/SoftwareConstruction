#include <iostream>
#include <cmath>
const int MAXN = 100000+5;
using namespace std;
typedef long long ll;

int t, n, s;

bool work(int l)
{
	bool flag = 1;
	int cc = 0, pos = 0;
	for (int j = l; j <= n+s; j++)
	{
		flag = 1;
		for (int i = 2; i <= sqrt(j); i++)
			if (j % i == 0)
			{
				flag = 0;
				break;
			}
		if (flag)
		{
			pos = j;
			cc++;
		}
		if (cc > 1)
			return 0;
	}
	if (cc == 1)
	{
		int ll;
		if (n >= s+1)
			ll = s;
		else
			ll = n;
		for(int i = l; i <= n+s; i++)
		{
			bool ff = 0;
			if (i == pos)
				continue;
			for (int j = 2; j <= ll ; j++)
				if (i % j == 0)
				{
					ff = 1;
					break;
				}
			if (!ff)
				return 0;
		}
	}
	return 1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	int cnt = 0;
	while (t--)
	{
		int l;
		cin >> n >> s;
		if (s == 1|| s == 0)
		{
			cnt++;
			cout << "Case #" << cnt <<": "<<"Yes";
			continue;
		}
		if (s+1 <= n)
			l = n+1;
		else
			l = s+1;
		bool f = work(l);
		cnt++;
		cout << "Case #" << cnt <<": ";
		if (f)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}

	return 0;
}