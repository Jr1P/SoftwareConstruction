#include <cstdio>
#define N 30050

int father[N], n, m, size[N];

inline void init() {
	for(int i = 0; i < n; i++) {
		father[i] = i;
		size[i] = 1;
	}
}

inline int find(int x) {
	if (x != father[x])
		father[x] = find(father[x]);
	return father[x];
}

inline void update(int fa, int sz) {
	size[fa] += sz;
	if(father[fa] != fa)
		update(father[fa], sz);
}

inline void _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if (f1 < f2) {
		father[f2] = f1;
		update(f1, size[f2]);
	}
	else if(f1 > f2) {
		father[f1] = f2;
		update(f2, size[f1]);
	}
}

int main() {
	while(~scanf("%d%d", &n, &m)) {
		if(n == 0) break;
		init();
		while(m--) {
			int k, rt;
			scanf("%d%d", &k, &rt);
			for(int i = 1; i < k; i++) {
				int son;
				scanf("%d", &son);
				_union(rt, son);
			}
		}
		printf("%d\n", size[0]);
	}
	return 0;

}
