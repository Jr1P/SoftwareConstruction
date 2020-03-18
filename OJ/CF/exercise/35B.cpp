#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define L 20
#define N 40
#define Q 2050

int n, m, q;
bool exist[N*N];
map<string, int > mp;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//ios::sync_with_stdio(false);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; i++)
	{
		char op, a;
		string s;
		getchar();
		scanf("%c%c", &op, &a);
		if (op == '+')
		{
			int r, c;
			scanf("%d%d", &r, &c);
			cin >> s;
			int pos = (r - 1)*m + c;
			while (exist[pos] && pos <= n*m)
				pos++;
			if (pos > n*m)
				continue;
			mp.insert(pair<string, int>(s, pos));
			exist[pos] = true;
		}
		else
		{
			cin >> s;
			if (mp.count(s))
			{
				int c = mp[s] % m, r = mp[s] / m + 1;
				if (!c)
					c = m, r--;
				printf("%d %d\n", r, c);
				exist[mp[s]] = false;
				mp.erase(s);
			}
			else printf("-1 -1\n");
		}
	}
	return 0;
}
