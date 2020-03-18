#include <cstdio>
#include <algorithm>
#include <cmath>
const double eps = 1e-8;
const int MAXN = 2e5;
using namespace std;

int n, m, father[MAXN], cnt, t;
double x[MAXN], x2[MAXN];
double yy1 = 0.0, yy2 = 0.0, dy = 0.0;

struct EDGE {
	int u, v;
    double w;
}e[MAXN<<1];

inline double dis(double x1, double x2) {
    return sqrt((x1-x2)*(x1-x2)+dy*dy);
}

inline int cmp(const EDGE &x, const EDGE &y) {
	return x.w+eps < y.w;
}

inline int find(int x) {
	if(x == father[x]) return x;
    return father[x] = find(father[x]);
}

inline bool _union(int x, int y) {
	int f1 = find(x);
	int f2 = find(y);
	if (f1 == f2) 
		return false;
	else if(f1 < f2)
		father[f2] = f1;
    else father[f1] = f2;
	return true;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        cnt = 0;
        double MST = 0;
        scanf("%lf%lf%d%d", &yy1, &yy2, &n, &m);
        dy = yy1-yy2;
        for(int i = 1; i <= n; i++)
            scanf("%lf", &x[i]);
        sort(x+1, x+n+1);
        for(int i = 1; i < n; i++) {
            e[++cnt].u = i;
            e[cnt].v = i+1;
            e[cnt].w = x[i+1]-x[i];
        }
        for(int i = 1; i <= m; i++)
            scanf("%lf", &x2[i]);
        sort(x2+1, x2+1+m);
        for(int i = 1; i < m; i++) {
            e[++cnt].u = n+i;
            e[cnt].v = n+i+1;
            e[cnt].w = x2[i+1]-x2[i];
        }
        for(int i = 1; i <= n; i++) {
            int j = lower_bound(x2+1, x2+1+m, x[i])-x2;
            if(j != 1) {
                e[++cnt].u = i;
                e[cnt].v = j-1+n;
                e[cnt].w = dis(x[i], x2[j-1]);
            }
            if(j > m) j = m;
            e[++cnt].u = i;
            e[cnt].v = j+n;
            e[cnt].w = dis(x[i], x2[j]);
        }
        for(int i = 1; i <= n+m; i++)
            father[i] = i;
        sort(e+1, e+cnt+1, cmp);
        for(int i = 1; i <= cnt; i++) {
            if(_union(e[i].u, e[i].v))
                MST += e[i].w;
        }
		printf("%.2f\n", MST);
    }
	return 0;
}