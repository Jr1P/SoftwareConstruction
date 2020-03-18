#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x7fffffff
const int N = 1e5+1;
//主席树查询区间[l, r]中有多少个互不相同的数
struct Node
{
	int ls, rs, sum; // sum表示区间中不同数的个数
}node[N*20];

int a[N], b[N], rt[N], pre[N];
int tot, size, n, q;
//p为当前更新值

void build(int& o, int l, int r)
{
	o = ++tot;
	node[o].sum = 0;
	node[o].ls = node[o].rs = 0;
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
		return node[now].sum;
	int mid = (l+r) >> 1;
	if(pos <= mid)
		return node[node[now].rs].sum+query(pos, node[now].ls, l, mid);
	else
		return query(pos, node[now].rs, mid+1, r);
}

void print()
{
	int l, r, cnt;
	scanf("%d%d", &l, &r);
	cnt = query(l, rt[r], 1, size);
	printf("%d\n", cnt);
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
			a[i] = lower_bound(b+1, b+size+1, a[i])-b;
		for(int i = 1; i <= n; ++i)
		{
			int pos = a[i];
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