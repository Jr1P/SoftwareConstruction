#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 50

int a[N], b[N];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 1; i<= n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b+1, b+n+1);
	for(int i = 1; i <= n; i++)
	{
		int j = lower_bound(b+1, b+n+1, a[i])-b;
		if(j == n)
			j = 1;
		else j++;
		printf("%d ", b[j]);
	}
	printf("\n"); //  
	return 0;
}