#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#define N 150

int n, ans;
int cnt[N];
string str;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		cin >> str;
		cnt[str[0]]++;
	}
	for(int i = 'a'; i <= 'z'; i++) {
		int s = cnt[i] / 2;
		int r = cnt[i] - s;
		ans += (s - 1) * s / 2 + r * (r - 1) / 2;
	}
	printf("%d\n", ans);
	return 0;
}