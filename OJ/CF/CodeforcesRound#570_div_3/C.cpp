#include <cstdio>
#include <iostream>
using namespace std;
#define Q 100050

int q;
long long n, a, b, k;

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		cin >>k >> n >> a >> b;
		if(k <= n*b)
			printf("-1\n");
		else if(k > n*a)
			cout << n << endl;
		else
		{
			k -= n*b;
			cout << (k-1)/(a-b) << endl;
		}
	}
	return 0;
}