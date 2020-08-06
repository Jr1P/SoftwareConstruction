#include <cstdio>
#include <iostream>
const double eps = 1e-6;
const int N = 1e5 + 5;

int n;
double p;
double a[N], b[N];

bool check(double mid) {
    double all = mid * p, time = 0.0;
    for(int i = 1; i <= n; i++) {
        double t = mid * a[i] - b[i];
        if(t >= 0)
            time += t;
    }
    return time <= all;
}

int main() {
    scanf("%d%lf", &n, &p);
    double sum = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%lf%lf", a + i, b + i);
        sum += a[i];
    }
    if(sum <= p) {
        puts("-1");
        return 0;
    }
    double l = 0.0, r = 1e10;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    std::cout << l << std::endl;
    return 0;
}