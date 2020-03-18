#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define eps 1e-9
#define INF 2147483647.00
#define Vector P
#define Pabc P& a, P& b, P& c
#define P3 P& p1, P& p2, P& p3
typedef double db;
typedef long long ll;

inline int sign(db a) { return a < -eps? -1: a > eps; }
inline int cmp(db a, db b) { return sign(a-b); }
inline bool min(db a, db b) { return cmp(a, b) == -1 ? a : b; }

struct P {
    db x, y;
    P() {}
    P(db _x, db _y) : x(_x), y(_y) {}
    P operator + (P p) { return {x+p.x, y+p.y}; }
    P operator - (P p) { return {x-p.x, y-p.y}; }
    P operator * (db d) { return {x*d, y*d}; }
    P operator / (db d) { return {x/d, y/d}; }

    inline db alpha() { return atan2(y, x); }
    inline db dot(P p) { return x*p.x + y*p.y; }
    inline db cross(P p) { return x*p.y - y*p.x; }
    inline db abs() { return sqrt(x*x + y*y); }
    inline db distTo(P p) { return (*this-p).abs(); }

    inline bool operator < (const P& p) const {
        int c = cmp(x, p.x);
        if(c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    inline bool operator == (const P& p) const {
        return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
    }
};

inline bool cmp1(P a, P b) {
    int c = cmp(atan2(a.y, a.x), atan2(b.y, b.x));
    if(c) return c == -1;
    return a.x < b.x;
} // 利用atan2函数进行极角排序, 有精度误差

inline db cross(P3) {
    return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
} // p1p2 和 p1p3的叉积

inline int crossOp(P3) {
    return sign(cross(p1, p2, p3));
} // 返回p1p2,p1p3叉积的符号

inline bool isMiddle(db a, db b, db c) {
    return sign(a-c) == 0 || sign(b-c) == 0 || (cmp(a, c) != cmp(b, c));
} // 包括端点

inline bool isMiddle(Pabc) {
    return isMiddle(a.x, b.x, c.x) && isMiddle(a.y, b.y, c.y);
}

inline bool onSeg(Pabc) {
    return crossOp(a, b, c) == 0 && isMiddle(a, b, c);
} // 判断c是否在线段ab上

int n, lowp, q;
db lowy = INF, lowx;
vector<P> poly;

int contain(P p) {
    int n = poly.size(), res = 0;
    for(int i = n-1; i >= 0; i--) {
        P u = poly[i], v = poly[(i-1+n)%n];
        if(onSeg(u, v, p)) return 1;
        if(cmp(u.y, v.y) <= 0) swap(u, v);
        if(cmp(p.y, u.y) > 0 || cmp(p.y, v.y) <= 0) continue;
        res ^= crossOp(p, u, v) > 0;
    }
    return res*2;
} // 判断点P与多边形poly的包含关系, 2:inside, 1:onSeg, 0:outside;

int main() {
    while(scanf("%d", &n) != EOF) {
        //freopen("output.txt", "w", stdout);
        poly.clear();
        lowy = INF;
        for(int i = 0; i < n; i++) {
            db x, y;
            scanf("%lf%lf", &x, &y);
            if(cmp(y, lowy) == -1) {
                lowy = y;
                lowp = i;
            }
            P tmp(x, y);
            poly.push_back(tmp);
        }
        lowx = poly[lowp].x;
        for(int i = 0; i < n; i++) {
            if(i == lowp) continue;
            poly[i].x -= lowx;
            poly[i].y -= lowy;
        }
        poly[lowp].x = 0.0, poly[lowp].y = 0.0;
        //sort(poly.begin(), poly.end(), cmp1);
        scanf("%d", &q);
        while(q--) {
            db x, y;
            scanf("%lf%lf", &x, &y);
            P tar(x-lowx, y-lowy);
            if(contain(tar)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}