#include <cstdio>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 505*505;

map<int ,int> ma;
bool f[N];
int a[N];
int n, _max, __max;
int num[550];

inline int max(int a, int b)
{
	return a > b? a: b;
}

inline int gcd(int a, int b)
{
	return a%b == 0? b: gcd(b, a%b);
}

int main()
{
	scanf("%d", &n);
	_max = 0; __max = 0;
	for(int i = 1; i <= n*n; i++)
	{
		scanf("%d", &a[i]);
		if(a[i] > _max)
		{
			__max = _max;
			_max = a[i];	
		}
		else if(a[i] > __max)
			__max = a[i];
	}
	int cnt = 0;
	sort(a+1, a+1+n*n);
	int g;
	for(int i = n*n; i > 0 && cnt < n; i--)
	{
		if(ma[a[i]] > 0) {
			ma[a[i]]--;
			continue;
		}
		f[i] = true;
		for(int j = 1; j <= cnt; j++)
		{
			g = gcd(a[i], num[j]);
			ma[g] += 2;
		}
		num[++cnt] = a[i];
	}
	
	for(int i = 1; i < n; i++)
		printf("%d ", num[i]);
	printf("%d\n", num[n]);
	return 0;
}