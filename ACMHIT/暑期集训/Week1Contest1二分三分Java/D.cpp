#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int t, l;
string s;

int main() 
{
	cin >> t;
	while(t--)
	{
		int m = 0;
		cin >> l;
		cin >> s;
		if(l < 11)
			cout << "NO\n";
		else
		{
			for(int i = 0; i < l; i++)
			{
				if(s[i] != '8')
					m++;
				else 
					break;
			}
			if(l-m < 11)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}