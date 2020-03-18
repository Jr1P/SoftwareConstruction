#include <cstdio>
#include <algorithm>
typedef long long ll;

ll n, ans = 0, i = 1;
int a[100];

int main() {
	scanf("%lld", &n);
	while(true) {
		if(n < i) break;
		n -= i;
		a[++ans] = i;
		i <<= 1;
	}
	if(n != 0) a[++ans] = n;
	std::sort(a+1, a+ans+1);
	printf("%lld\n", ans);
	for(int i = 1; i < ans; i++)
		printf("%d ", a[i]);
	printf("%d\n", a[ans]);
	return 0;
}
