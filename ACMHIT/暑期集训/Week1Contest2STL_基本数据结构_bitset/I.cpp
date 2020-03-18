#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100050

struct Point
{
	int num, type;
}p[N<<1];
//    
int n, t;
int l[N], r[N];

inline bool cmp(Point& a, Point& b)
{
	return (a.num == b.num)? a.type < b.type: a.num < b.num;
}

inline int max(int x, int y)
{
	return x > y? x: y;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			p[i*2-1].num = l;
			p[i*2].num = r;
			p[i*2-1].type = 1;
			p[i*2].type = 2;
		}
		sort(p+1, p+n*2+1, cmp);
		int ans = 0, ma = -1;
		for(int i = 1; i <= n+n; i++)
		{
			if(p[i].type == 1)
				ans++;
			else
				ans--;
			ma = max(ma, ans);
		}
		printf("%d\n", ma);
	}
	return 0;
}