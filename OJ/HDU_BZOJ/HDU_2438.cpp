#include <cstdio>
#include <cmath>
#define eps 1e-7
const double PI = acos(-1);

inline double gou(double h, double l) { // h - 高, l - 斜边
    return sqrt(l * l - h * h);
}

int main() {
    double x, y, l, w;
    while(~scanf("%lf%lf%lf%lf", &x, &y, &l, &w)) {
        bool f = false;
        if(w >= std::fmin(x, y)) {
            puts("no");
            continue;
        }
        double dy = 0.0;
        while(1) {
            double ry = fabs(x - dy);
            if(ry < 0.001) {
                dy += 0.1;
                continue;
            }
            double theta, alpha = asin(dy / l), beta;
            if(dy < x) {
                theta = atan(y / ry);
                beta = PI / 2 - theta + alpha;
            } else {
                theta = atan(ry / y);
                beta = alpha - theta;
            } 
            double L = sqrt(y * y + ry * ry);
            double dl = L * sin(beta);
            if(dl < 0 || dy - l > eps) break;
            // printf("%f\n", );
            if(w - dl < -1.0) dy += 0.1;
            else dy += 0.001;
            if(w - dl > eps) {
                f = true;
                break;
            }
        }
        if(f) puts("no");
        else puts("yes");
    }
}