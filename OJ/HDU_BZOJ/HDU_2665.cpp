#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5+5;

struct Tree
{
	int ls, rs, sum; //num为该节点对应区间的数据个数
}node[N*20];

int a[N], b[N], rt[N];
int tot, size, q, n, T;
//size为去重后数组大小, T为样例个数, n为数组大小

void build(int &o, int l, int r)
{
	o = ++tot;
	node[o].sum = 0;
	if(l == r)
		return ;
	int mid = (l+r) >> 1;
	build(node[o].ls, l, mid);
	build(node[o].rs, mid+1, r);
}

void update(int &o, int l, int r, int last, int p)
//o为当前结点的线段树树根, last为前一状态的线段树的树根, p为用于更新的数
{
	o = ++tot;
	node[o].ls = node[last].ls;
	node[o].rs = node[last].rs;
	node[o].sum = node[last].sum+1;
	if(l == r)
		return ;
	int mid = (l+r) >> 1;
	if(p <= mid)
		update(node[o].ls, l, mid, node[last].ls, p);
	else
		update(node[o].rs, mid+1, r, node[last].rs, p);
}

int query(int pre, int now, int l, int r, int k)
{
	if(l == r)
		return l;
	int mid = (l+r) >> 1;
	int cnt = node[node[now].ls].sum - node[node[pre].ls].sum;
	if(k <= cnt)
		return query(node[pre].ls, node[now].ls, l, mid ,k);
	else
		return query(node[pre].rs, node[now].rs, mid+1, r, k);
}

void print()
{
	int l, r, k;
	scanf("%d%d%d", &l, &r, &k);
	int ans = query(rt[l-1], rt[r], 1, size, k);
	printf("%d\n", b[ans]);
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b+1, b+n+1);
		size = unique(b+1, b+n+1) - (b+1);
		tot = 0;
		build(rt[0], 1, size);
		for(int i = 1; i <= n; i++)
			a[i] = lower_bound(b+1, b+n+1, a[i]) - b;
		for(int i = 1; i <= n; i++)
			update(rt[i], 1, size, rt[i-1], a[i]);
		while(q--)
			print();
	}
	return 0;
}