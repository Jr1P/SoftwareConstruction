#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int n;
int cnt[200];

int main()
{
	int ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		cnt[s[0]]++;
	}
	for(int i = 'a'; i <= 'z'; i++)
	{
		int s = cnt[i]/2;
		int r = cnt[i]-s;
		ans += (s-1)*s/2+r*(r-1)/2;
	}
	printf("%d\n", ans);
	return 0;
}