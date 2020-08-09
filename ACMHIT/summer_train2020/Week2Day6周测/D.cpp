#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 1e5+5;
typedef long long ll;

int c[N], n, num[N], so[N];
ll a, b;

inline int lowbit(int k) { return k&(-k); }

inline void nodeUpdate(int x, int add) {
	for(int i = x; i <= n; i += lowbit(i))
		c[i] += add;
}

inline int getSum(int r) {
	int ans = 0;
	for(int i = r; i; i -= lowbit(i))
		ans += c[i];
	return ans;
}

int main() {
	while(~scanf("%d%lld%lld", &n, &a, &b)) {
		for(int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
            so[i] = num[i];
        }
        memset(c, 0, sizeof(c));
        std::sort(so + 1, so + n + 1);
        int sz = std::unique(so + 1, so + n + 1) - (so + 1);
        for(int i = 1; i <= n; i++)
            num[i] = std::lower_bound(so+1, so+n+1, num[i])-so;
        ll sum = 0;
        for(int i = 1; i <= n; i++) {
            nodeUpdate(num[i], 1);
            sum += i-getSum(num[i]);
        }
        printf("%lld\n", sum * std::min(a, b));
	}
	return 0;
}