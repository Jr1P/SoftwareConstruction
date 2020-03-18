#include <cstdio>
#include <cmath>
#define eps 1e-7

struct Point
{
	double x, y;
}a, b, c, d;

double lab, lcd;
double p, q, R;
double ans;

inline double dis(Point M, Point N) {
	double dx = M.x-N.x;
	double dy = M.y-N.y;
	return sqrt(dx*dx+dy*dy);
}

void read() {
	scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
	scanf("%lf%lf%lf%lf", &c.x, &c.y, &d.x, &d.y);
	scanf("%lf%lf%lf", &p, &q, &R);
}

double calc(double r1, double r2) {
	Point e, f;
	e.x = r1*(-a.x+b.x)+a.x;
	e.y = r1*(-a.y+b.y)+a.y;
	f.x = r2*(-c.x+d.x)+c.x;
	f.y = r2*(-c.y+d.y)+c.y;
	double t = lab*r1/p+dis(e, f)/R+lcd*(1.0-r2)/q;
	return t;
}

double three_divide_f(double r1) {
	double l = 0.0, r = 1.0;
	while(r-l > eps) {
		double mid = (l+r)/2;
		double mmid = (mid+r)/2;
		if(calc(r1, mmid)-calc(r1, mid) > eps)
			r = mmid;
		else l = mid;
	}
	Point e, f;
	e.x = r1*(-a.x+b.x)+a.x;
	e.y = r1*(-a.y+b.y)+a.y;
	f.x = l*(-c.x+d.x)+c.x;
	f.y = l*(-c.y+d.y)+c.y;
	double t = lab*r1/p+dis(e, f)/R+lcd*(1.0-l)/q;
	return t;
}

void three_divide_e() {
	double l = 0.0, r = 1.0;
	while(r-l > eps) {
		double mid = (l+r)/2;
		double mmid = (mid+r)/2;
		if(three_divide_f(mmid)-three_divide_f(mid) > eps)
			r = mmid;
		else l = mid;
	}
	printf("%.2f\n", three_divide_f(l));
}

int main() {
	read();
	lab = dis(a, b);
	lcd = dis(c, d);
	three_divide_e();
	return 0;
}