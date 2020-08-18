#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#define eps 1e-9
#define Vector P
#define P3 P& p1, P& p2, P& p3
#define P4 P& p1, P& p2, P& q1, P& q2
typedef double db;

inline int sign(db a) { return a < -eps? -1: a > eps; }
inline int cmp(db a, db b) { return sign(a-b); }
inline db min(db a, db b) { return cmp(a, b) == -1 ? a : b; }

struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator + (P p) { return {x+p.x, y+p.y}; }
    P operator - (P p) { return {x-p.x, y-p.y}; }
    P operator * (db d) { return {x*d, y*d}; }
    P operator / (db d) { return {x/d, y/d}; }

    inline db cross(P p) { return x*p.y - y*p.x; } // 叉积
    inline db abs() { return sqrt(x*x + y*y); } // 向量模长
    inline db distTo(P p) { return (*this-p).abs(); } // 两点间距离
};

inline db cross(P3) {
    return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
}

inline int crossOp(P3) {
    return sign(cross(p1, p2, p3));
}

inline bool intersect(db l1, db r1, db l2, db r2) {
    if(cmp(l1, r1) == 1) std::swap(l1, r1);
    if(cmp(l2, r2) == 1) std::swap(l2 ,r2);
    return !(cmp(r1, l2) == -1 || cmp(r2, l1) == -1);
}

inline bool isSS(P4) {
    return intersect(p1.x, p2.x, q1.x, q2.x) && intersect(p1.y, p2.y, q1.y, q2.y) &&
    crossOp(p1, p2, q1)*crossOp(p1, p2, q2) <= 0 &&
    crossOp(q1, q2, p1)*crossOp(q1, q2, p2) <= 0;
}

int n;

int main() {
    scanf("%d", &n);
    while(n--) {
        P p1, p2, p3, p4, l1, l2;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &l1.x, &l1.y, &l2.x, &l2.y,
         &p1.x, &p1.y, &p3.x, &p3.y);
        p2.x = p1.x, p2.y = p3.y;
        p4.x = p3.x, p4.y = p1.y;
        if(p1.y < p2.y) std::swap(p1, p2), std::swap(p3, p4);
        if(p1.x > p4.x) std::swap(p1, p4), std::swap(p2, p3);
        if(l1.x >= p1.x && l1.y <= p1.y && l1.x <= p3.x && l1.y >= p3.y) {
            puts("T");
            continue;
        }
        if(isSS(p1, p2, l1, l2) || isSS(p1, p4, l1, l2) || isSS(p2, p3, l1, l2)
            || isSS(p3, p4, l1, l2)) puts("T");
        else puts("F");
    }
    return 0;
}