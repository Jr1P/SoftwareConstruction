#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
const int MAXN = 100000+5;
using namespace std;
typedef long long ll;

int t, n;
char str[6][150];
string name[100];
char pre[100];

bool vaild(char ch)
{
	if ((ch >= 'A' && ch <= 'Z')||(ch == '-')||(ch == '_')||(ch >= '0' && ch <= '9')||(ch >= 'a' && ch <= 'z'))
		return 1;
	else
		return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while (t--)
	{
		int k = 0;
		cin >> n;
		cin.ignore(80, '\n');
		for (int i = 1; i <= n; i++)
		{
			int pos = 0;
			cin.getline(str[i], '\n');
			for(int j = 0; j < strlen(str[i]); j++)
			{
				if(str[i][j] != '@')
					continue;
				else
				{
					k++;
					if (j != 0)
						pre[k] =str[i][j-1];
					else
						pre[k] = '|';
					pos = j;
					break;
				}
			}
			if (pos)
			{
				while(pos < strlen(str[i]))
				{
					if (str[i][pos] == '@')
					{
						k++;
						pre[k] =str[i][pos-1];
						pos++;
						continue;
					}
					else
						while (vaild(pos))
						{
							name[k] += str[i][pos];
							pos++;
						}
				}
			}
		}
		sort(name+1, name+k+1);
		for(int i = 1; i <= k; i++)
			cout << name[i] << '\n';
	}

	return 0;
}