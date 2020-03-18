#include <cstdio>
#include <algorithm>
const int N = 105;
const int M = 10050;
using namespace std;

int n, m, father[N];

struct EDGE {
	int u, v, w;
}e[M];

inline int cmp(const EDGE &x, const EDGE &y) {
	return x.w < y.w;
}

inline int find(int x) {
	if (father[x] == x) return x;
	return father[x] = find(father[x]);
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

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int MST = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        sort(e + 1, e + m + 1, cmp);
        for(int i = 1; i <= n; i++)
            father[i] = i;
        for(int i = 1; i <= m; i++)
            if(_union(e[i].u, e[i].v))
                MST += e[i].w;
        printf("%d\n", MST);
    }
	return 0;
}