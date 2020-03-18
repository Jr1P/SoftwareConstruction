#include <cstdio>
#include <cstring>
const int MAXL = 200;
char x1[MAXL], x2[MAXL];
int a[MAXL], b[MAXL], c[MAXL];

inline int max(int x, int y) { return (x > y) ? x : y; }

int main() {
    scanf("%s", x1);
    int len1 = strlen(x1), len;
	for(int i = 0; i < len1; ++i) a[i] = x1[len1 - i - 1] - '0';
	while (1) {
		scanf("%s", x2); getchar();
        if(x2[0] == '0') break;
		int add = 0, len2 = strlen(x2);
		len = max(len1, len2);
		memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c));
		for(int i = 0; i < len2; ++i) b[i] = x2[len2 - i - 1] - '0';
		for(int i = 0; i < len; ++i) {
			c[i] = a[i] + b[i] + add;
			add = c[i] / 10;
			c[i] %= 10;
		}
		if(add > 0)
            c[len++] = add;
        for(int i = 0; i < len; i++) a[i] = c[i];
        len1 = len;
	}
    for(int i = len1 - 1; i >= 0; --i)
        printf("%d", a[i]);
    puts("");
	return 0;
}
