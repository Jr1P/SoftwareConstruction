#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1e5+1;
const double eps = 1e-6;
const double INF = 1e20;

struct Point
{
	double x, y;
}point[MAXN];

int mpt[MAXN];

inline double min(double x, double y)
{
	return (x < y) ? x : y;
}

bool cmpx(const Point &a, const Point &b)
{
	if (fabs(a.x - b.x) < eps)
		return a.x-b.x < eps;
	return a.y-b.y < eps;
}

bool cmpy(const int &a, const int &b)
{
	return point[a].y - point[b].y < eps;
}

inline double dis(int i, int j)
{
	return sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));
}

double solve(int l, int r)
{
	double d = INF;
	if(l == r)
		return d;
	if(l+1 == r)
		return dis(l, r);
	int mid = (l+r)>>1;
	double d1 = solve(l, mid);
	double d2 = solve(mid+1, r);
	d = min(d1, d2);
	int cnt = 0;
	for(int i = l; i <= r; ++i)
		if(fabs(point[mid].x-point[i].x) < d)
			mpt[cnt++] = i;
	sort(mpt, mpt+cnt, cmpy);
	for(int i = 0; i < cnt; ++i)
		for(int j = i+1; j < cnt && point[mpt[j]].y-point[mpt[i]].y < d; ++j)
		{
			double d3 = dis(mpt[i], mpt[j]);
			d = min(d, d3);
		}
	return d;
}

int main()
{
	int n;
	while(1)
	{
		scanf("%d", &n);
		if (!n)
			break;
		for(int i = 0; i < n; ++i)
			scanf("%lf%lf", &point[i].x, &point[i].y);
		sort(point, point+n, cmpx);
		double ans = solve(0, n-1)/2;
		printf("%.2lf\n", ans);
	}
	return 0;
}