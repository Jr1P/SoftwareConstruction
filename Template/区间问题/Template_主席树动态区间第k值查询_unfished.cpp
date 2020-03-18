#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
//动态区间查询的主席树模板
struct Node
{
	int ls, rs, sum;
}node[N*50];

int root[N], a[N], b[N];
int tot, size, q, n, t, cmd, p, k;
// tot是当前总共结点数, size是去重后数组大小
// q是询问数, n是数组大小, t样例个数
// cmd为操作类型 1 -- 修改 2--查询, k- k-th number

inline int lowbit(int x)
{
	return x&(-x);
}

void build(int &o, int l, int r)
{
	o = ++tot;
	node[o].sum = 0;
	if(l == r)
		return ;
	int mid = (l+r)>>1;
	build(node[o].ls, l, mid);
	build(node[o].rs, mid+1, r);
}

void update(int &o, int l, int r, int last)
{
	o = ++tot;
	node[o] = node[last];
	node[o].sum++;
	if(l == r)
		return ;
	int mid = (l+r)>>1;
	if(p <= mid)
		update(node[o].ls, l, mid, node[last].ls);
	else
		update(node[o].rs, mid+1, r, node[last].rs);
}

int query(int pre, int now, int l, int r)
{
	if(l == r)
		return l;
	int mid = (l+r)>>1;
	int cnt = node[node[now].ls].sum - node[node[pre].ls].sum;
	if (k <= cnt)
		return query(node[pre].ls, node[now].ls, l, mid, k);
	else
		return query(node[pre].rs, node[now].rs, mid+1, r, k-cnt);
}

inline void print()
{
	int l, r; //[l, r] k-th number
	scanf("%d%d%d", &l, &r, &k);
	int ans = query(rt[l-1], rt[r], 1, size);
	printf("%d\n" , b[ans]);
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &q);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", a+i);
			b[i] = a[i];
		}
		sort(b+1, b+n+1);
		size = unique(b+1, b+size+1) - (b+1);
		tot = 0;
		build(rt[0], 1, size);
		for(int i = 1; i <= n; i++)
			a[i] = lower_bound(b+1, b+size+1, a[i]) - b;
		for(int i = 1; i <= n; i++)
		{
			p = a[i];
			update(rt[i], 1, size, rt[i-1]);
		}
		while(q--)
		{
			printf("%d\n", cmd);
			if (cmd == 1)//修改
			{

			}
			else//查询
				print();
		}
	}
	return 0;
}