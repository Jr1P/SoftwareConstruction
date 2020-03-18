#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a[1050];
string s;

int main()
{
	while(cin >> s)
	{
		for(int i = 0; i < 1000; i++)
			a[i] = 0;
		int cnt = 1;
		for(unsigned i = 0; i < s.length(); i++)
		{
			if(s[i] == '5')
			{
				if (i == 0)
					continue;
				if (s[i-1] != '5' && i != s.length()-1)
					cnt++;
			}
			else
				a[cnt] = a[cnt]*10+s[i]-48;
		}
		if(s[s.length()-1] == '5' && s[s.length()-2] == '5')
			cnt--;
		sort(a+1, a+cnt+1);
		for(int i = 1; i <= cnt; i++)
			if (i != cnt) printf("%lld ", a[i]);
			else printf("%lld\n", a[i]);
	}
	return 0;
}