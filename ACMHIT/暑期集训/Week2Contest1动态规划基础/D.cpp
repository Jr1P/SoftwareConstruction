#include <cstdio>
#include <algorithm>
//#include <queue>
using namespace std;
#define N 10050
typedef long long ll;

int n, s;
ll c[N], y[N];
ll ans = 0, m = 10000000000000000;

int main() {
	scanf("%d%d", &n, &s);

	for(int i = 1; i <= n; i++)
		scanf("%lld%lld", &c[i], &y[i]);
	for(int i = 1; i <= n; i++) {
		m += s;
		if(m > c[i]) m = c[i];
		ans += m*y[i];
	}
	printf("%lld\n", ans);//
	return 0;
}