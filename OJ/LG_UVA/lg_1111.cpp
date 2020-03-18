#include <cstdio>
#include <algorithm>
#define N 1050
#define M 100050

struct Edge {
	int u, v, val;
}e[M << 1];

int n, m;
int fa[N];

inline int cmp(Edge a, Edge b) {
	return a.val < b.val;
}

inline int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

inline bool _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if(f1 == f2) return false;
	if(f1 < f2)
		fa[f2] = f1;
	else
		fa[f1] = f2;
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].val);
	std::sort(e + 1, e + 1 + m, cmp);
	int cnt = 0, MST = 0;
	for(int i = 1; i <= m; i++) {
		if(cnt == n-1) break;
		if(_union(e[i].u, e[i].v)) {
			cnt++;
			MST = e[i].val;
		}
	}
	if(cnt == n-1) printf("%d\n", MST);
	else puts("-1");
	return 0;
}