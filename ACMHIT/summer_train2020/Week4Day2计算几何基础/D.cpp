#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
typedef double db;
const int N = 105;
const int INF = __INT_MAX__;
#define Vector P
#define eps 1e-7

inline int sign(db a) { return a < -eps? -1: a > eps; }
inline int cmp(db a, db b) { return sign(a-b); }

struct P {
    db x, y; int id;
    P() {}
    P(db x, db y, int id=-1) : x(x), y(y), id(id) {}
    P operator - (P p) { return {x-p.x, y-p.y, id}; }
    inline db abs() { return sqrt(x*x + y*y); }
    inline db dot(P p) { return x*p.x + y*p.y; }
    inline db cross(P p) { return x*p.y - y*p.x; }

} p[N];

int lowy = INF, lowp, cnt, n;
int ans[N];
bool vis[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        lowy = INF; cnt = 0;
        memset(vis, false, sizeof(vis));
        for(int i = 1; i <= n; i++) {
            int id, x, y;
            scanf("%d%d%d", &id, &x, &y);
            p[i] = P(x, y, id);
            if(y < lowy) lowy = y, lowp = i;
        }
        for(int i = 1; i <= n; i++) {
            if(i == lowp) continue;
            p[i] = p[i]-p[lowp];
        }
        p[lowp].x = p[lowp].y = 0;
        P tmp(1, 0), po = p[lowp];
        Vector q(tmp-po);
        vis[lowp] = true;
        ans[++cnt] = lowp;
        for(int i = 2; i <= n; i++) {
            db theta = INF;
            int pos;
            for(int j = 1; j <= n; j++)
                if(!vis[j]) {
                    Vector tt(p[j]-po);
                    db ang = acos(tt.dot(q)/(tt.abs()*q.abs()));
                    if(cmp(theta, ang) == 1) {
                        theta = ang;
                        pos = j;
                    } else if(cmp(theta, ang) == 0) {
                        Vector v(p[pos]-po);
                        if(cmp(v.abs(), tt.abs()) == 1)
                            pos = j;
                    }
                }
            q = p[pos]-po;
            ans[++cnt] = pos;
            po = p[pos];
            vis[pos] = true;
        }
        printf("%d", n);
        for(int i = 1; i <= n; i++) printf(" %d", ans[i]);
        puts("");
    }
    return 0;
}