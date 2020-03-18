#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t;

char s[1005];


inline int init()
{
	int len = strlen(s);
	int cnt = 0, ect = 1;
	int tot = 0;
	int ans = 0;
	while (tot < len)
	{
		int k = s[len - 1] - '0';
		int cd = 0;
		if (k % 2 == 1)
		{
			ans += cnt;
		}
		for (int i = tot; i < len; i++)
		{
			k = s[i] - '0';
			if (cd)
				k += 10, cd = 0;
			if (k % 2)
				cd = 1;
			k = k / 2;
			s[i] = k + '0';
		}
		if (s[tot] == '0') tot++;
		cnt = pow(2, ect) - 1;
		ect++;
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	for (int e = 1; e <= t; e++)
	{
		cin >> s;
		printf("%d\n", init());
	}
	return 0;
}