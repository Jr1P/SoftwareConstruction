#include <cstdio>
#include <vector>
#include <algorithm>
#define Pabc P& a, P& b, P& c
#define P3 P& p1, P& p2, P& p3
#define eps 1e-7
// typedef int int;
const int N = 1050;

inline int sign(int a) { return a < 0? -1: a > 0; }
inline int cmp(int a, int b) { return sign(a-b); }

struct P {
    int x, y;
    P() {}
    P(int x, int y) : x(x), y(y) {}
    P operator + (P p) { return {x+p.x, y+p.y}; }
    P operator - (P p) { return {x-p.x, y-p.y}; }
    P operator * (int d) { return {x*d, y*d}; }

    inline int cross(P p) { return x*p.y - y*p.x; }
};

inline int cross(P3) {
    return (p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y-p1.y);
}

inline int crossOp(P3) {
    return sign(cross(p1, p2, p3));
}

inline bool isMiddle(int a, int b, int c) {
    return sign(a-c) == 0 || sign(b-c) == 0 || (cmp(a, c) != cmp(b, c));
}

inline bool isMiddle(Pabc) {
    return isMiddle(a.x, b.x, c.x) && isMiddle(a.y, b.y, c.y);
}

inline bool onSeg(Pabc) {
    return crossOp(a, b, c) == 0 && isMiddle(a, b, c);
}

int contain(P p, std::vector<P> poly) {
    int n = poly.size(), res = 0;
    for(int i = 0; i < n; i++) {
        P u = poly[i], v = poly[(i+1)%n];
        if(onSeg(u, v, p)) return 1;
        if(cmp(u.y, v.y) <= 0) std::swap(u, v);
        if(cmp(p.y, u.y) > 0 || cmp(p.y, v.y) <= 0) continue;
        res ^= crossOp(p, u, v) > 0;
    }
    return res*2;
}

int n, m;
int cnt[N], re[N];
P po[N];
std::vector<P> poly[N];

inline bool cmp1(P a, P b) {
    return a.x < b.x;
}

int main() {
    int x1, y1, x2, y2;
    while(~scanf("%d", &n) && n) {
        scanf("%d%d%d%d%d", &m, &x1, &y1, &x2, &y2);
        for(int i = 0; i <= n; i++) poly[i].clear();
        for(int i = 0; i <= m; i++) cnt[i]  = re[i] = 0;
        // P p1 = P(x1, y1), p2 = P(x1, y2), p3 = P(x2, y2), p4 = P(x2, y1);
        po[0] = P(x1, x1);
        for(int i = 1; i <= n; i++)
            scanf("%d%d", &po[i].x, &po[i].y);
        po[++n] = P(x2, x2);
        std::sort(po, po+n+1, cmp1);
        for(int i = 1; i <= m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            int le = 0, ri = n, ans;
            while(le < ri) {
                int mid = (le+ri)>>1;
                std::vector<P> tmp; tmp.clear();
                tmp.push_back(P(po[le].x, y1));
                tmp.push_back(P(po[le].y, y2));
                tmp.push_back(P(po[mid+1].y, y2));
                tmp.push_back(P(po[mid+1].x, y1));
                if(contain(P(x, y), tmp)) {
                    ri = mid;
                    ans = mid;
                } else le = mid+1;
            }
            cnt[ans]++;
        }
        for(int i = 0; i <= n; i++) re[cnt[i]]++;
        puts("Box");
        for(int i = 1; i <= m; i++)
            if(re[i]) printf("%d: %d\n", i, re[i]);
    }
    return 0;
}