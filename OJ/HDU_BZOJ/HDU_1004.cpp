#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAXN = 1005;

string str[MAXN];
int num[MAXN];

int main()
{
	int n;
	ios::sync_with_stdio(false);
	while(1)
	{
		int pos = 0, cnt = 0, max = 0;
		cin >> n;
		memset(num, 0, sizeof(num));
		if(n == 0)
			break;
		else
		{
			int i, j;
			string s;
			for(i = 1; i <= n; ++i)
			{
				bool f = 0;
				cin >> s;
				for(j = 1; j <= cnt; ++j)
					if(str[j] == s)
					{
						f = 1;
						break;
					}
				if (!f)
				{
					cnt++;
					str[cnt] = s;
				}
				num[j]++;
			}
		}
		for(int i = 1; i <= cnt; i++)
			if (num[i] > max)
			{
				max = num[i];
				pos = i;
			}
		cout << str[pos] << '\n';
	}
	return 0;
}