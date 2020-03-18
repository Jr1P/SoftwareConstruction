#include <stdio.h>
using namespace std;
const int maxCampNum = 50000+1;
const int maxP = 100000+5;
//'I'----Increase, 'D'----Dec, 'Q'----Query;
int p, x, y, ans = 0, add;
//p为待查询或修改点,[x,y]为待查询或修改区间,ans区间查询的答案, 使用前初始化为0 add为增值
struct node
{
	int l, r, w, lazy; // [l, r], w-weight权重, lazy为懒标记
}tree[maxCampNum<<2];

void build(int l, int r, int k);
	//建树, k为节点序号 初始状态 (1, n, 1)
inline void down(int k);
	//懒标记下传
int nodeInquiry(int k); 
	//单点查询, p为待查询点 
void intervalInquiry(int k); 
	//区间查询, 查询区间为 [x, y], k为当前节点序号 初始 (1); 可以将查询区间设为全局变量以减少函数的参数量
void nodeModify(int k);
	//单点修改, 在x节点上加add, k为当前节点 初始 (1, add, x)
void intervalModify(int k);
	//区间修改,[l, r]为待修改区间,k为当前节点,初始 (l, r, 1, add)
int main()
{
	int cNum, eNum, qNum, u[maxCampNum], v[maxCampNum], C, C1, C2, K; //eNum = cNum - 1;
	char ch;
	while (scanf("%d %d %d", &cNum, &eNum, &qNum)!=EOF)
	{
		build(1, cNum, 1);
		for (int i = 1; i <= eNum; i++)
			scanf("%d %d", &u[i], &v[i]);
		for (int i = 1; i <= qNum; i++)
		{
			scanf("%c", &ch);
			if (ch == 'I')
			{
				scanf("%d %d %d", &C1, &C2, &K);
				
			}
			else if (ch == 'Q')
			{
				scanf("%d", &C);
			}
			else
			{
				scanf("%d %d %d", &C1, &C2, &K);
			}
		}
	}
}

void build(int l, int r, int k)
{
	tree[k].l = l; tree[k].r = r; tree[k].lazy = 0;
	if (l == r)
	{
		scanf("%d", &tree[k].w);
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, k<<1);
	build(mid + 1, r, k<<1|1);
	tree[k].w = tree[k<<1].w + tree[k<<1|1].w;
}

inline void down(int k)
{
	tree[k<<1].lazy += tree[k].lazy;
	tree[k<<1|1].lazy += tree[k].lazy;
	tree[k<<1].w += tree[k].lazy * (tree[k<<1].r - tree[k<<1].l + 1);
	tree[k<<1|1].w += tree[k].lazy * (tree[k<<1|1].r - tree[k<<1|1].l + 1);
	tree[k].lazy = 0;
}

int nodeInquiry(int k)
{
	if (tree[k].l == tree[k].r)
		return tree[k].w;
	if (tree[k].lazy)
		down(k);
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (p <= mid) 
		return nodeInquiry(k<<1);
	else 
		return nodeInquiry(k<<1|1);
}

void nodeModify(int k)
{
	if (tree[k].l == tree[k].r)
	{
		tree[k].w += add;
		return ;
	}
	if (tree[k].lazy)
    	down(k);
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (p <= mid) 
		nodeModify(k<<1);
	else 
		nodeModify(k<<1|1);
	tree[k].w = tree[k<<1].w + tree[k<<1|1].w;
}

void intervalInquiry(int k)
{
	if ((tree[k].l >= x) && (tree[k].r <= y))
	{
		ans += tree[k].w;
		return ;
	}
	if (tree[k].lazy)
		down(k);
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (x <= mid) 
		intervalInquiry(k<<1);
	if (y > mid)
		intervalInquiry(k<<1|1);
}

void intervalModify(int k)
{
	if (tree[k].l <= x && tree[k].r >= y)
	{
		tree[k].w = (tree[k].r - tree[k].l + 1) * add;
		tree[k].lazy += add;
		return ;
	}
	int mid = (tree[k].l + tree[k].r) >> 1;
	if (x <= mid)
		intervalModify(k<<1);
	if (y > mid)
		intervalModify(k<<1|1);
	tree[k].w = tree[k<<1].w + tree[k<<1|1].w;
}