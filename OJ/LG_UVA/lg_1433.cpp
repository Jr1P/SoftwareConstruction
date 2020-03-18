#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define N 20
const double eps = 1e-6;

int n;
double x[N], y[N];
double ans = 1e10, now, pre;
bool vis[N];

inline double min(double x, double y)
{
	return (x < y-eps)? x: y;
}

inline double dis(int a, int b)
{
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

void dfs(int x, int depth)
{
	if (now > ans-eps)
		return ;
	if (depth == n)
	{
		if (now < ans-eps)
			ans = now;
		return ;
	}
	for(int i = 1; i <= n; i++)
		if (!vis[i])
		{
			vis[i] = true;
			now += dis(x, i);
			dfs(i, depth+1);
			vis[i] = false;
			now -= dis(x, i);
		}
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x[i] >> y[i];
		vis[i] = false;
	}
	dfs(0, 0);
	cout << fixed << setprecision(2) << ans << '\n';
	return 0;
}