#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define N 100005
#define logN 20
#define INF 2147483647

struct MO
{
	int l, r, id, sum, block;
}q[N];

int color[N], b[N], sum[N];
int dp1[N][logN], dp2[N][logN];
int size, T, n, m, unit, ans;

inline void init()
{
	ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 20; j++)
		{
			dp1[i][j] = 0;
			dp2[i][j] = INF;
		}
	return ;
}

inline int Max(int x, int y)
{
	return (x > y)? x: y;
}

inline int Min(int x, int y)
{
	return (x < y)? x: y;
}

inline bool cmp(MO a, MO b)
{
	return (a.block == b.block)? (a.r < b.r): (a.block < b.block);
}

inline bool CMP(MO a, MO b)
{
	return a.id < b.id;
}

void ST()
{
	for(int j = 1; (1<<j) <= n; j++)
		for(int i = 1; i+(1<<j)-1 <= n; i++)
		{
			int k = 1<<(j-1);
			dp1[i][j] = Max(dp1[i][j-1], dp1[i+k][j-1]);
			dp2[i][j] = Min(dp2[i][j-1], dp2[i+k][j-1]);
		}
}

inline int RMQ(int l, int r)
{
	int k = log2((double)(r-l+1));
	int maxium = Max(dp1[l][k], dp1[r-(1<<k)+1][k]);
	int minium = Min(dp2[l][k], dp2[r-(1<<k)+1][k]);
	return (maxium-minium+1);
}

inline void inc(int x)
{
	int tmp = color[x];
	sum[tmp]++;
	if (sum[tmp] == 1)
		ans++;
}

inline void dec(int x)
{
	int tmp = color[x];
	sum[tmp]--;
	if (sum[tmp] == 0)
		ans--;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		init();
		scanf("%d%d", &n, &m);
		unit = sqrt(n);
		for(int i = 1; i <= n; i++)
		{
			sum[i] = 0;
			scanf("%d", color+i);
			b[i] = color[i];
			dp1[i][0] = color[i];
			dp2[i][0] = color[i];
		}
		sort(b+1, b+n+1);
		size = unique(b+1, b+n+1)-(b+1);
		for(int i = 1; i <= n; i++)
			color[i] = lower_bound(b+1,b+size+1, color[i])-b;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &q[i].l, &q[i].r);
			q[i].id = i;
			q[i].sum = 0;
			q[i].block = q[i].l/unit+1;
		}

		ST();
		sort(q+1, q+m+1, cmp);
		int l = 1, r = 0;
		for(int i = 1; i <= m; i++)
		{
			while(l < q[i].l)
                dec(l++);
            while(l > q[i].l)
                inc(--l);
            while(r < q[i].r)
                inc(++r);
            while(r > q[i].r)
                dec(r--);
			q[i].sum = ans;
		}

		sort(q+1, q+m+1, CMP);
		for(int i = 1; i <= m; i++)
		{
			int len = RMQ(q[i].l, q[i].r);
			if (len == q[i].sum)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}