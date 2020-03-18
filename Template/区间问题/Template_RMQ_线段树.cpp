#include <cstdio>
using namespace std;
const int MAXN = 2e5+1;
const int MAXM = 5e3+1;
//RMQ问题的线段树实现, 通过Update和Inquiry函数来更新和查询
//支持单点更新和区间最值查询 
int n, q, ll, rr, pos, num; //[ll, rr]为待查询区间 , pos为待修改点, num为修改值, _max为查询到的最大值

struct TREE
{
	int l, r, max;
}tree[MAXN<<2];

inline int max(int x, int y)
{
	return (x>y)?x:y;
}

inline int getMid(int k)
{
	return ((tree[k].l+tree[k].r)>>1);
}

void build(int l, int r, int k)
{
	tree[k].l = l; tree[k].r = r;
	if(l == r)
	{
		scanf("%d", &tree[k].max);
		return ;
	}
	int mid = getMid(k);
	build(l, mid, k<<1);
	build(mid+1, r, k<<1|1);
	tree[k].max = max(tree[k<<1].max, tree[k<<1|1].max);
}

int inquiry(int k)
{
	if(tree[k].l >= ll && tree[k].r <= rr)
		return tree[k].max;
	int mid = getMid(k);
	int a = 0, b = 0;
	if(ll <= mid)
		a = inquiry(k<<1);
	if(rr > mid)
		b = inquiry(k<<1|1);
	return max(a, b);
}

void update(int k)
{
	if (tree[k].l == tree[k].r)
	{
		tree[k].max = num;
		return ;
	}
	int mid = getMid(k);
	if (pos <= mid)
		update(k<<1);
	else
		update(k<<1|1);
	tree[k].max = max(tree[k<<1].max, tree[k<<1|1].max);
}

int main()
{
	while(scanf("%d %d", &n, &q) != EOF)
	{	
		build(1, n, 1);
		while(q--)
		{
			int a ,b;
			char ch[2];
			scanf("%s%d%d", ch, &a, &b);
			if (ch[0] == 'U')
			{
				pos = a;
				num = b;
				update(1);
			}
			else if (ch[0] == 'Q')
			{
				ll = a;
				rr = b;
				printf("%d\n", inquiry(1));
			}
		}
	}
	return 0;
}