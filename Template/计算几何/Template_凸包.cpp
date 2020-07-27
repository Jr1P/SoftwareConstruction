#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps 1e-9
#define N 10050
#define INF 2147483647.00
#define Vector Point
typedef double db;

inline int sign(db a) { return a < -eps? -1: a > eps; }
inline int cmp(db a, db b) { return sign(a-b); }

struct Point {
    db x, y;
    Point() {}
    Point(db _x, db _y) : x(_x), y(_y) {}
    Point operator + (Point p) { return {x+p.x, y+p.y}; }
    Point operator - (Point p) { return {x-p.x, y-p.y}; }
    Point operator * (db d) { return {x*d, y*d}; }
    Point operator / (db d) { return {x/d, y/d}; }

    inline db distTo(Point p) { return (*this-p).abs(); }
    inline db cross(Point p) { return x*p.y - y*p.x; }
    inline db abs() { return sqrt(x*x+y*y); }
    inline bool operator < (Point p) const {
        int c = cmp(x, p.x);
        if(c) return c == -1;
        return cmp(y, p.y) == -1;
    }
    inline bool operator == (Point p) const {
        return cmp(x, p.x) == 0 && cmp(y, p.y) == 0;
    }
}po[N];

inline bool cmp1(Point a, Point b) {
    int c = cmp(atan2(a.y, a.x), atan2(b.y, b.x));
    if(c) return c == -1;
    return a.x < b.x;
} // 利用atan2函数进行极角排序, 有精度误差

inline bool cmp2(Point a, Point b) {
    int c = cmp(a.cross(b), 0.0);
    if(c) return c == 1;
    return a.x < b.x;
} // 利用叉积进行极角排序

inline bool isLeft(Point A, Point B, Point C) {
    Vector AB(B-A), BC(C-B);
    return cmp(AB.cross(BC), 0) > 0;
} // 判断折线BC是否在折线AB的左侧, 即是否在AB的逆时针方向

int n, top, lowp;
db lowy = INF;
int stk[N];

inline void _swap(int a, int b) {
    db tmp = po[a].x;
    po[a].x = po[b].x;
    po[b].x = tmp;
    tmp = po[a].y;
    po[a].y = po[b].y;
    po[b].y = tmp;
}

db Graham() {
    db ans = 0.0;
    stk[++top] = 1; stk[++top] = 2;
    for(int i = 3; i <= n; i++) {
        while(top >= 2 && !isLeft(po[stk[top-1]], po[stk[top]], po[i]))
            top--;
        stk[++top] = i;
    }
    for(int i = 1; i < top; i++)
        ans += po[stk[i]].distTo(po[stk[i+1]]);
    ans += po[stk[top]].distTo(po[1]);
    return ans;
} //返回凸包的周长

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        db x, y;
        scanf("%lf%lf", &x, &y);
        po[i].x = x, po[i].y = y;
        if(cmp(y, lowy) == -1) lowp = i, lowy = y; // 找到y坐标最小点
    }
    for(int i = 1; i <= n; i++) { // 移动坐标系
        if(i == lowp) continue;
        po[i].x -= po[lowp].x;
        po[i].y -= po[lowp].y;
    }
    po[lowp].x = 0; po[lowp].y = 0;
    _swap(lowp, 1);
    sort(po + 2, po + n + 1, cmp2);
    printf("%.2f\n", Graham());
    return 0;
}