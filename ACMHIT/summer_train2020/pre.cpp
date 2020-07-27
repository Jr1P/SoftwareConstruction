#include <cstdio>
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define drep(i, a, b) for(int i = a; i >= b; i--)

int n, m;
int a[50];

int main() {
	scanf("%d", &n);
	rep(i, 0, n) scanf("%d", a + i);
	printf("%d\n", a[0]);
	return 0;
}
