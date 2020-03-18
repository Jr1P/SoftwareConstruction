#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps 1e-10
#define Vector P
#define P3 P p1, P p2, P p3
#define P4 P p1, P p2, P q1, P q2
#define N 300
typedef double db;

inline int sign(db a) { return a < -eps? -1: a > eps; }
inline int cmp(db a, db b) { return sign(a-b); }
inline db min(db a, db b) { return cmp(a, b) == -1 ? a : b; }
inline db max(db a, db b) { return cmp(a, b) == -1 ? b : a; }

struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator + (P p) { return {x+p.x, y+p.y}; }
    P operator - (P p) { return {x-p.x, y-p.y}; }
    P operator * (db d) { return {x*d, y*d}; }
    P operator / (db d) { return {x/d, y/d}; }

    inline db cross(P p) { return x*p.y - y*p.x; }
    inline db abs() { return sqrt(x*x + y*y); }
    inline db distTo(P p) { return (*this-p).abs(); }
}poly[N];

inline db cross(P3) {
    return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
}

inline int crossOp(P3) {
    return sign(cross(p1, p2, p3));
}

inline bool intersect(db l1, db r1, db l2, db r2) {
    if(cmp(l1, r1) == 1) swap(l1, r1);
    if(cmp(l2, r2) == 1) swap(l2 ,r2);
    return !(cmp(r1, l2) == -1 || cmp(r2, l1) == -1);
}

inline bool isSS(P4) {
    return 
    crossOp(p1, p2, q1)*crossOp(p1, p2, q2) < 0 &&
    crossOp(q1, q2, p1)*crossOp(q1, q2, p2) < 0;
}

inline P isLL(P4) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return (p1*a2 + p2*a1)/(a1 + a2);
} 

int n;
db ans;

void solve(int x) {
    P o = poly[x];
    for(int i = x+1; i < n; i++) {
        P to = poly[i];
        db ans1 = 0.0;
        bool flag = false;
        //if(x == i || x+1 == i || x-1 == i) continue;
        for(int j = 0; j < n; j++) {
            P u = poly[j], v = poly[(j+1)%n];
            if(isSS(o, to, u, v)) {
                P k = isLL(o, to, u, v);
                ans = max(ans, o.distTo(k));
                ans = max(ans, k.distTo(to));
                flag = true;
            }
        }
        if(!flag) ans = max(ans, o.distTo(to));
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        db x, y;
        scanf("%lf%lf", &x, &y);
        poly[i].x = x; poly[i].y = y;
    }
    for(int i = 0; i < n; i++)
        ans = max(ans, poly[i].distTo(poly[(i+1)%n]));
    for(int i = 0; i < n; i++) 
        solve(i);
    printf("%.9f\n", ans);
    return 0;
}