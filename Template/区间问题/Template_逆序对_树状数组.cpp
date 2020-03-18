#include <cstdio>

using namespace std;
const int MAXN = 1e6+1;

int tree[MAXN], n;

inline int lowbit(int k) {
	return k&(-k);
}

inline void nodeUpdate(int x, int add) {
	for(int i = x; i <= n; i += lowbit(i))
		tree[i] += add;
}

inline int getSum(int r) {
	int ans = 0;
	for(int i = r; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

int main() {
	while(~scanf("%d", &n)) {
		int ans = 0;
		for(int i = 1; i <= n; i++) tree[i] = 0;
		for(int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			nodeUpdate(a, 1);
			ans += i-getSum(a);
		}
		printf("%d\n", ans);
	}
	return 0;
}