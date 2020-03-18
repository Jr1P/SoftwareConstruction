#include <cstdio>
#define N 1000050
typedef long long ll;

int d[N], s[N], t[N];
int x, y;
bool f = false;

ll ans = 0, add;
//p为待查询或修改点,[x,y]为待查询或修改区间,ans区间查询的答案, 使用前初始化为0 add为增值
struct node
{
	int l, r, lazy; // [l, r], w-weight为权重, lazy为懒标记
	ll w;
}tree[N<<2];

void build(int l, int r, int k);
	//建树, k为节点序号 初始状态 (1, n, 1)
inline void down(int k);
	//懒标
void intervalModify(int k);
	//区间修改,[l, r]为待修改区间,k为当前节点,初始 (l, r, 1, add)
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld%d%d", &add, &x, &y);
		add = -add;
		intervalModify(1);
		if (f)
		{
			printf("-1\n%d\n", i);
			break;
		}
	}
	if(!f) printf("0\n");
	return 0;
}

void build(int l, int r, int k)
{
	tree[k].l = l; tree[k].r = r;
	if (l == r)
	{
		scanf("%lld", &tree[k].w);
		return ;
	}
	int mid = (l + r) >> 1;
	int ls = k<<1, rs = k << 1|1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	tree[k].w = tree[ls].w + tree[rs].w;
}

inline void down(int k)
{
	int ls = k<<1, rs = k << 1|1;
	tree[ls].lazy += tree[k].lazy;
	tree[rs].lazy += tree[k].lazy;
	tree[ls].w += tree[k].lazy*(tree[ls].r-tree[ls].l+1);
	tree[rs].w += tree[k].lazy*(tree[rs].r-tree[rs].l+1);
	if(tree[ls].w < 0 || tree[rs].w < 0)
		f = true;
	tree[k].lazy = 0;
}

void intervalModify(int k)
{
	if (tree[k].l >= x && tree[k].r <= y)
	{
		tree[k].w += (tree[k].r-tree[k].l+1) * add;
		if(tree[k].w < 0) f = true;
		tree[k].lazy += add;
		return ;
	}
	if (tree[k].lazy)
		down(k);
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (x <= mid)
		intervalModify(k<<1);
	if (y > mid)
		intervalModify(k<<1|1);
	tree[k].w = tree[k<<1].w + tree[k<<1|1].w;
}