#include <cstdio>
#include <algorithm>
using namespace std;
#define N 50050

int l, n, m;
int d[N];

int main()
{
	d[0] = 0;
	scanf("%d%d%d", &l, &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%d", &d[i]);
		sort(d+1, d+n+1);
		//for(int i = 1; i <= n; i++)
			//d[i] -= d[i-1];
		d[n+1] = l;
		int pre = 0;
		int ll = 0, rr = l, cnt = 0;
		bool f = false;
		while(ll <= rr-1 && !f)
		{
			if(ll == rr-1)
				f = true;
			cnt = 0; pre = 0;
			int mid = (ll+rr)>>1;
			for(int i = 1; i <= n+1; i++)
			{
				if(mid > d[i]-pre)
					cnt++;
				else
					pre = d[i];
			}
			if(cnt > m)
				rr = mid;
			else
				ll = mid;
		}
		cnt = 0; pre = 0;
		for(int i = 1; i <= n+1; i++)
		{
			if(rr > d[i]-pre)
				cnt++;
			else
				pre = d[i];
		}
		if(cnt == m)
			printf("%d\n", rr);
		else
			printf("%d\n", ll);
	return 0;
}