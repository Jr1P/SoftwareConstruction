#include <cstdio>
#include <cmath>
#include<algorithm>
using namespace std;
#define N 300050

int a[N];
int n;

int max(int x, int y)
{
	return x > y? x: y;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i<= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] /= max((n-i), i-1);
	}
	sort(a+1, a+n+1);
	int k = a[1];
	printf("%d\n", k);
	return 0;
}