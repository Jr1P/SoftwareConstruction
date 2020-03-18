#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#define L 100050
using namespace std;

int t;
char a[L], b[L], a1[L];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s%s", a, b);
		int l = strlen(a), ans = 0;
		for(int i = 0; i < l; i++)
			a1[l-i-1] = a[i];
		bool f = false;
		for(int i = 0; i <= l/2; i++) {
			if(a[i] != b[i] && a1[i] != b[i]) {
				f = true;
				break;
			}
			if (ans % 2 == 0) {
				if(a[i] == b[i]) continue;
				else ans++;
			}
			else {
				if(a1[i] == b[i]) continue;
				else ans++;
			}
		}
		if(f) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}