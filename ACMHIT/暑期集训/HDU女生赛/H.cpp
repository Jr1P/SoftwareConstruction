#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100050

struct Time
{
	int h, m, s;
}tim[N];

int n, h0, m0, s0;

inline bool cmp(Time &a, Time &b)
{
	if (a.h < b.h)
		return true;
	else if (a.h > b.h)
		return false;
	else 
		return (a.m != b.m) ? a.m < b.m: a.s < b.m;
}

int main()
{
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d%d%d", &h0, &m0, &s0);
		if(h0 >= 12)
			h0 -= 12;
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &tim[i].h, &tim[i].m, &tim[i].s);
			tim[i].s -= s0;
			if(tim[i].s < 0)
			{
				tim[i].s += 60;
				tim[i].m--;
			}
			tim[i].m -= m0;
			if(tim[i].m < 0)
			{
				tim[i].m += 60;
				tim[i].h--;
			}
			tim[i].h -= h0;
			if(tim[i].h < 0)
				tim[i].h += 12;
			else if(tim[i].h >= 12)
				tim[i].h -= 12;
		}
		h0 = 0, m0 = 0, s0 = 0;
		sort(tim+1, tim+n+1, cmp);
		int ans, tmp;
		ans = tim[n].h*60*360+tim[n].m*360+tim[n].s*6;
		tmp = ans;
		ans = (12-tim[1].h)*60*360-tim[1].m*360-tim[1].s*6;
		if(tmp > ans)
			tmp = ans;
		int p;
		for(p = 1; p <= n; p++)
			if(tim[p].h >= 6)
				break;
		int ans1 = tim[p-1].h*60*360+tim[p-1].m*360+tim[p-1].s*6;
		int ans2 = (12-tim[p].h)*60*360-tim[p].m*360-tim[p].s*6;
		if(ans1 < ans2)
			ans = 2*ans1+ans2;
		else
			ans = 2*ans2+ans1;
		if(tmp > ans)
			tmp = ans;
		printf("%d.00\n", tmp);
	}
	return 0;
}