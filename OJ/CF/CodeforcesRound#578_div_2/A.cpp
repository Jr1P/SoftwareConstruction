#include <cstdio>

int n;
int nxt[100050], pre[100050];
char str[100050], ans[15];

int main() {
	scanf("%d", &n);
	scanf("%s", str);
	for(int i = 0; i < 11; i++) {
		ans[i] = '0';
	}
	for(int i = 0; i < n; i++) {
		if(str[i] == 'L') {
			for(int j = 0; j < 10; j++)
				if(ans[j] == '0') {
					ans[j] = '1';
					break;
				}
		} else if(str[i] == 'R') {
			for(int j = 9; j >= 0; j--)
				if(ans[j] == '0') {
					ans[j] = '1';
					break;
				}
		} else {
			int p = str[i]-'0';
			ans[p] = '0';
		}
	}
	ans[10] = '\0';
	printf("%s\n", ans);
	return 0;
}