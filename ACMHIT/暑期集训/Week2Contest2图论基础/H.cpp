#include <cstdio>
#include <iostream>
#include <algorithm>
const int MAXN = 2e3+50;
const int MAXM = 1e4+50;
using namespace std;

int n, m, father[MAXN], cnt = 0;

struct EDGE {
	int u, v, w;
}e[MAXM];

inline int cmp(const EDGE &x, const EDGE &y) {
	return x.w < y.w;
}

inline int find(int x) {
	if (father[x] != x)
		father[x] = find(father[x]);
	return father[x];
}

inline bool _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if (f1 == f2) 
		return false;
	else
		father[f2] = f1;
	return true;
}

int main()
{
	int MST = 0;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	sort(e+1, e+m+1, cmp);
	for(int i = 1; i <= n; i++)
		father[i] = i;
	int e_num = 1;
	while (cnt < n-1 && e_num <= m) {
		if(_union(e[e_num].u, e[e_num].v)) {
			cnt++;
			MST = e[e_num].w;
		}
		e_num++;
	}
    printf("%d\n", MST);
	return 0;
}