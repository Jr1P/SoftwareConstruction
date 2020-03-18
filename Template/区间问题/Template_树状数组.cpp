#include <cstdio>

const int N = 1e6 + 5;

int tree[N], n, q;

inline int lowbit(int k) { return k & (-k); }

inline void update(int x, int add) {
	for(int i = x; i <= n; i += lowbit(i))
		tree[i] += add;
}

inline int sum(int r) {
	int ans = 0;
	for(int i = r; i; i -= lowbit(i))
		ans += tree[i];
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		update(i, a);
	}
	for(int i = 1; i <= q; i++) {
		char ch;
		scanf("%c", &ch);
		if (ch == '2') //ch == '2' 表示查询[l, r]区间和
		{
			int l, r, res;
			scanf("%d%d", &l, &r);
			res = sum(r) - sum(l-1);
			printf("%d\n", res);
		}
		else //ch == '1' 表示单点修改, 在a[x]处加add
		{
			int x, add;
			scanf("%d%d", &x, &add);
			update(x, add);
		}
	}
	return 0;
}