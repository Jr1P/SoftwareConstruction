#include <cstdio>
#include <algorithm>
using namespace std;
#define N 105

int dis, fa[N];
int n, m, cnt = 0, MST = 0;

struct EDGE{
    int u, v, w;
}e[N*N];

inline bool cmp(EDGE a, EDGE b) {
    return a.w < b.w;
}

inline int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

inline bool _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if (f1 == f2) 
		return false;
	else if(f1 < f2)
		fa[f2] = f1;
    else
        fa[f1] = f2;
	return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) {
            scanf("%d", &dis);
            if(j > i) {
                e[++cnt].w = dis;
                e[cnt].u = i;
                e[cnt].v = j;
            }
        }
    sort(e+1, e+1+cnt, cmp);
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        _union(u, v);
    }
    for(int i = 1; i <= cnt; i++)
        if(_union(e[i].u, e[i].v))
            MST += e[i].w;
    printf("%d\n", MST);
    return 0;
}