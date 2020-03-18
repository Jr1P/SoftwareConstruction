#include <cstdio>
#include <algorithm>
#include <cstring>
const int MAXN = 1e5+50;
using namespace std;

int n, m, k, ans;
int father[MAXN];
bool x[MAXN];

struct EDGE {
	int u, v, w;
}e[MAXN];

inline bool cmp(const EDGE &x, const EDGE &y) {
	return x.w < y.w;
}

inline int find(int x) {
    if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

int main() {
    while(scanf("%d%d%d", &n, &m, &k) != EOF) {
        memset(x, 0, sizeof(x));
        for(int i = 1; i <= k; i++) {
            int p;
            scanf("%d", &p);
            x[p] = 1;
        }
        for(int i = 1; i <= m; i++)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        sort(e+1, e+m+1, cmp);
        for(int i = 1; i <= n; i++)
            father[i] = i;
        ans = 0;
        for(int i = 1; i <= m; i++) {
            int f1 = find(e[i].u), f2 = find(e[i].v);
            if(f1 != f2) {
                if(x[f1] && x[f2])
                    ans = e[i].w;
                else if(x[f1] || x[f2]) {
                    x[f1] = 1;
                    x[f2] = 1;
                }
                father[f1] = f2;
            }
        }
        for(int i = 1; i < k; i++)
            printf("%d ", ans);
        printf("%d\n", ans);
    }
	return 0;
}