#include <cstdio>
#include <algorithm>
using namespace std;
#define N 105
int t, n;
int l[N], r[N];

struct RR
{
	int l, r;
}R[N];

bool cmp(RR a, RR b){
	return a.r < b.r;
}

int main()
{
	while(scanf("%d", &n))
	{
		if (n == 0)
			break;
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &R[i].l, &R[i].r);
		sort(R+1, R+n+1, cmp);
		int now = 0, ans = 0;
		for(int i = 1; i <= n; i++)
			if(now <= R[i].l)
			{
				ans++;
				now = R[i].r;
			}
		printf("%d\n", ans);
	}
	return 0;
}