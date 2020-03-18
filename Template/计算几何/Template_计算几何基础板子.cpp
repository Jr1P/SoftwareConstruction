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
#define P4 P& p1, P& p2, P& q1, P& q2
typedef double db;
typedef long long ll;

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

    inline db alpha() { return atan2(y, x); }
    inline db dot(P p) { return x*p.x + y*p.y; }
    inline db cross(P p) { return x*p.y - y*p.x; }
    inline db abs() { return sqrt(x*x + y*y); }
    inline db distTo(P p) { return (*this-p).abs(); }
    inline P normalize() { return *this/abs(); }
    inline P rot(db angle) { return {x*cos(angle) - y*sin(angle), x*sin(angle) + y*cos(angle)}; }
    inline bool operator < (const P& p) const {
        int c = cmp(x, p.x);
        if(c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    inline bool operator == (const P& p) const {
        return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
    }
};

inline void _swap(P& a, P& b) {
    P tmp = a;
    a = b;
    b = tmp;
}

inline bool cmp1(P a, P b) {
    int c = cmp(atan2(a.y, a.x), atan2(b.y, b.x));
    if(c) return c == -1;
    return a.x < b.x;
} // 利用atan2函数进行极角排序, 有精度误差

inline bool cmp2(P a, P b) {
    int c = cmp(a.cross(b), 0.0);
    if(c) return c == 1;
    return a.x < b.x;
} // 利用叉积进行极角排序

inline db cross(P3) {
    return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
} // p1p2 和 p1p3的叉积

inline int crossOp(P3) {
    return sign(cross(p1, p2, p3));
} // 返回p1p2,p1p3叉积的符号

inline bool chkLL(P4) {
    Vector P(p2-p1), Q(q2-q1);
    int c = cmp(P.cross(Q), 0.0);
    if(!c) return true;
    return false;
} // 判断直线p1p2和q1q2是否平行

inline P isLL(P4) {
    db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
    return (p1*a2 + p2*a1)/(a1 + a2);
} // 两直线相交交点, 若直线平行会报错

inline db disToLine(Pabc) {
    Vector ab(b-a), ac(c-a);
    if(a == b) return ac.abs();
    return fabs(ab.cross(ac)/ab.abs()); //去掉绝对值为有向距离
} // 点c到直线ab的距离 

inline bool isLeft(Pabc) {
    Vector ab(b-a), bc(c-b);
    return cmp(ab.cross(bc), 0) > 0;
} // 判断折线bc是否在折线ab的左侧, 即是否在ab的逆时针方向

inline bool intersect(db l1, db r1, db l2, db r2) {
    if(cmp(l1, r1) == 1) swap(l1, r1);
    if(cmp(l2, r2) == 1) swap(l2 ,r2);
    return !(cmp(r1, l2) == -1 || cmp(r2, l1) == -1);
}

inline bool isSS(P4) {
    return intersect(p1.x, p2.x, q1.x, q2.x) && intersect(p1.y, p2.y, q1.y, q2.y) &&
    crossOp(p1, p2, q1)*crossOp(p1, p2, q2) <= 0 &&
    crossOp(q1, q2, p1)*crossOp(q1, q2, p2) <= 0;
} // 判断线段是否非严格相交

inline bool isMiddle(db a, db b, db c) {
    return sign(a-c) == 0 || sign(b-c) == 0 || (cmp(a, c) != cmp(b, c));
} // 包括端点

inline bool isMiddle(Pabc) {
    return isMiddle(a.x, b.x, c.x) && isMiddle(a.y, b.y, c.y);
}

inline bool onSeg(Pabc) {
    return crossOp(a, b, c) == 0 && isMiddle(a, b, c);
} // 判断c是否在线段ab上

inline P proj(Pabc) {
    Vector dir = b-a;
    return a + dir*(dir.dot(c-a)/dir.abs());
} // 返回c点在ab上的投影点

inline db nearest(Pabc) {
    P H = proj(a, b, c);
    if(isMiddle(a, b, H))
        return c.distTo(H);
    return min(c.distTo(a), c.distTo(b));
} // 返回c与线段ab的最短距离

inline db disSS(P4) {
    if(isSS(p1, p2, q1, q2)) return 0.0;
    return min(min(nearest(p1, p2, q1), nearest(p1, p2, q2)), min(nearest(q1, q2, p1), nearest(q1, q2, p2)));
} // 返回线段p1p2 q1q2的距离

int n, lowp, q, top;
int stk[10050];
db lowy = INF, lowx;
vector<P> poly;

db Polyarea() {
    db S = 0.0;
    int n = poly.size();
    for(int i = 1; i < n-1; i++)
        S += cross(poly[0], poly[i], poly[i+1]);
    return S*0.5;
} // 返回多边形的面积

int contain(P p) {
    int n = poly.size(), res = 0;
    for(int i = 0; i < n; i++) {
        P u = poly[i], v = poly[(i+1)%n];
        if(onSeg(u, v, p)) return 1;
        if(cmp(u.y, v.y) <= 0) swap(u, v);
        if(cmp(p.y, u.y) > 0 || cmp(p.y, v.y) <= 0) continue;
        res ^= crossOp(p, u, v) > 0;
    }
    return res*2;
} // 判断点P与多边形poly的包含关系, 2:inside, 1:onSeg, 0:outside;

db Graham() {
    db ans = 0.0;
    stk[++top] = 0; stk[++top] = 1;
    for(int i = 2; i < n; i++) {
        while(top >= 2 && !isLeft(poly[stk[top-1]], poly[stk[top]], poly[i]))
            top--;
        stk[++top] = i;
    }
    for(int i = 1; i < top; i++)
        ans += poly[stk[i]].distTo(poly[stk[i+1]]);
    ans += poly[stk[top]].distTo(poly[stk[1]]);
    return ans;
} //返回凸包的周长

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        db x, y;
        scanf("%lf%lf", &x, &y);
        P tmp(x, y);
        poly.push_back(tmp);
        if(cmp(y, lowy) == -1) lowp = i, lowy = y;
    }
    for(int i = 0; i < n; i++) {
        if(i == lowp) continue;
        poly[i].x -= poly[lowp].x;
        poly[i].y -= poly[lowp].y;
    }
    poly[lowp].x = 0; poly[lowp].y = 0;
    //_swap(lowp, 1);
    sort(poly.begin(), poly.end(), cmp1);
    printf("%.2f\n", Graham());
    return 0;
}