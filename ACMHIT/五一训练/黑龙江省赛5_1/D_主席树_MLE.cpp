#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x7fffffff
#define N 100001

struct Node
{
	int ls, rs, sum, max, min; // sum表示区间中不同数的个数
}node[N*16];

int a[N], b[N], c[N], rt[N], pre[N]; // c[N]为a[N]离散化后的数组
int tot, size, n, q;
//p为当前更新值
int _max = 0, _min = INF;

inline int Max(int x, int y)
{
	return (x > y) ? x: y;
}

inline int Min(int x, int y)
{
	return (x < y) ? x: y;
}

void build(int& o, int l, int r)
{
	o = ++tot;
	node[o].sum = 0;
	node[o].ls = node[o].rs = 0;
	node[o].max = 0;
	node[o].min = INF;
	if(l == r)
		return ;
	int mid = (l+r)>>1;
	build(node[o].ls, l, mid);
	build(node[o].rs, mid+1, r);
}

void update(int &o, int l, int r, int pos, int val, int last)
{
	o = ++tot;
	node[o] = node[last];
	node[o].sum += val;
	node[o].max = Max(node[o].max, a[pos]);
	node[o].min = Min(node[o].min, a[pos]);
	if (l == r)
		return ;
	int mid = (l+r) >> 1;
	if (pos <= mid)
		update(node[o].ls, l, mid, pos, val, node[last].ls);
	else
		update(node[o].rs, mid+1, r, pos, val, node[last].rs);
}

int query(int pos, int now, int l, int r) // 查询区间[l, r]的不同数的个数
{
	if (l == r)
	{
		_max = Max(_max, a[l]);
		_min = Min(_min, a[l]);
		return node[now].sum;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid)
	{
		_max = Max(_max, node[node[now].rs].max);
		_min = Min(_min, node[node[now].rs].min);
		return node[node[now].rs].sum + query(pos, node[now].ls, l, mid);
	}
	else
		return query(pos, node[now].rs, mid + 1, r);
}

void print()
{
	int l, r, cnt;
	_max = 0, _min = INF;
	scanf("%d%d", &l, &r);
	cnt = query(l, rt[r], 1, size);
	if (cnt == _max-_min+1)
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		memset(pre, 0, sizeof(pre));
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d", a+i);
			b[i] = a[i];
		}
		sort(b+1, b+n+1);
		size = unique(b+1, b+n+1)-(b+1);
		tot = 0;
		build(rt[0], 1, size);
		for(int i = 1; i <= n; ++i)
			c[i] = lower_bound(b+1, b+size+1, a[i])-b;
		for(int i = 1; i <= n; ++i)
		{
			int pos = c[i];
			if(!pre[pos])
				update(rt[i], 1, size, i, 1, rt[i-1]);
			else
			{
				int tmp;
				update(tmp, 1, size, pre[pos], -1, rt[i-1]);
				update(rt[i], 1, size, i, 1, tmp);
			}
			pre[pos] = i;
		}
		while(q--)
			print();
	}
	return 0;
}