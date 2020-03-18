#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define N 10
#define eps 1e-6
const char c1[] = "No Solution";

int n;
int r[N], pos[N];
double dis[N], p[N], pp[N];
double c, dpv, mx, now = 0.0;//mx表示装满油时可到达的距离

inline bool cmp(double a, double b)
{
	return a < b-eps;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> dis[0] >> c >> dpv >> p[0] >> n;
	pp[0] = p[0];
	mx = c*dpv;
	for(int i = 1; i <= n; i++)
	{
		cin >> dis[i] >> p[i];
		pp[i] = p[i];
	}
	while(now+mx < )
	{

	}
	/*sort(pp, pp+n+1, cmp);
	for(int i = 0; i <= n; i++)
	{
		r[i] = lower_bound(pp, pp+n+1, p[i])-pp+1;
		pos[r[i]] = i;
	}*/

	return 0;
}