#include <cstdio>
#include <cmath>
#define PI 3.14159265358979323

double S, r2, l, h, V;

int main() {
    while(scanf("%lf", &S) != EOF) {
        r2 = S / (PI * 4.0);
        double r = sqrt(r2);
        // l = S / (PI * r) - r;
        h = sqrt((S - PI * r2) * (S - PI * r2) / (PI * PI * r2) - r2);
        V = PI * r2 * h / 3.0;
        printf("%.2f\n%.2f\n%.2f\n", V, h, r);
    }
    return 0;
}