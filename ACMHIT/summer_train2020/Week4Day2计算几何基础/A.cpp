#include <cstdio>
#include <cmath>
#define eps 1e-9
#define db double
const int N = 1e6+5;

int n;

struct P {
    double x, y;
}poly[N];

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%lf%lf", &poly[i].x, &poly[i].y);
        P u = poly[0], v, g;
        g.x = 0, g.y = 0;
        double S = 0.0, tmp;
        for(int i = 1; i <= n; i++) {
            v = poly[i%n];
            tmp = u.x*v.y - u.y*v.x;
            S += tmp*0.5;
            g.x += (u.x+v.x)*tmp;
            g.y += (u.y+v.y)*tmp;
            u = v;
        }
        printf("%.2f %.2f\n", g.x/(S*6), g.y/(S*6));
    }
    return 0;
}