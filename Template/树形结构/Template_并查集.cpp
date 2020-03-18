#include <cstdio>
const int MAXN = 1e5+1;
const int MAXQ = 1e5+1;
int father[MAXN], n ,q;

inline void init() {
	for(int i = 1; i <= n; i++)
		father[i] = i;
}

inline int find(int x) {
	if (x != father[x])
		father[x] = find(father[x]);
	return father[x];
}

inline void _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if (f1 != f2)
		father[f2] = f1;
}

int main() {
	scanf("%d %d", &n, &q);
	init();
	for(int i = 1; i <= q; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		_union(x, y);
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", father[i]);
	return 0;
}