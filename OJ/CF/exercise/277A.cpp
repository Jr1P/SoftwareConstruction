#include <cstdio>
#include <vector>
#define N 105

int m, n;
int a[N], fa[N];
std::vector<int > p[N];

inline int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

inline void _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if(f1 == f2) return ;
	if(f1 > f2) fa[f1] = f2;
	else fa[f2] = f1;
}

int main() {
	bool f = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for(int j = 1; j <= k; j++) {
			int v;
			scanf("%d", &v);
			p[v].push_back(i);
			f = 1;
		}
	}
	for(int i = 1; i <= m; i++) {
		int sz = p[i].size();
		for(int j = 0; j < sz-1; j++)
			_union(p[i][j], p[i][j+1]);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		if(fa[i] == i) cnt++;
	if(f) cnt--;
	printf("%d\n", cnt);
	return 0;
}
