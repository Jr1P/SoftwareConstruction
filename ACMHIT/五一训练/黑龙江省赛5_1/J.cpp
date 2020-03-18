#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e5+1;

int f[MAXN];
int n;

int main()
{
	int t = 0;
	scanf("%d", &t);
	for(int e = 1; e <= t; e++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &f[i]);
		int tot = 1, ans = 0;
		while(tot <= n)
		{
			if(f[tot] == tot)
				tot++;
			else{ 
				swap(f[tot], f[f[tot]]);
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}