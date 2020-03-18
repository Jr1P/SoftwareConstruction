#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
#define N 205

int a[N];
int n, t;

struct Milk
{
	int value, tj;
	string name;
}m[N];

bool cmp(Milk x, Milk y)
{
	return (x.value == y.value) ? x.tj > y.tj: x.value < y.value;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			cin >> m[i].name >> m[i].value >> m[i].tj;
			int q = m[i].tj / 200;
			if(q > 5)
				q = 5;
			if(m[i].tj < 200)
			{
				q = 1;
				m[i].value = 10000000;
			}
			m[i].value /= q;
		}
		sort(m+1, m+n+1, cmp);
		cout << m[1].name << endl;
	}
	return 0;
}