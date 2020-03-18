#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e5+10;

typedef long long ll;

int p, x, y, t;
int ans = 0, add;
//p为待查询或修改点,[x,y]为待查询或修改区间,ans区间查询的答案, 使用前初始化为0 add为增值
struct node
{
	int l, r, lazy; // [l, r], w-weight为权重, lazy为懒标记
	int w;
}tree[MAXN<<2];

void build(int l, int r, int k);
inline void down(int k);
void intervalInquiry(int k); 
void nodeModify(int k);
void intervalModify(int k);

int main()
{
	int n, m, kase = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d:\n", ++kase);
        scanf("%d", &n);
        build(1, n, 1);
        char ch[10];
        while (1)
        {
            cin >> ch;
            ans = 0;
            //scanf("%s", ch);
            if(ch[0] == 'E') break;
            else if(ch[0] == 'Q') {
                scanf("%d%d", &x, &y);
                intervalInquiry(1);
                printf("%d\n", ans);
            } else if(ch[0] == 'A') {
                scanf("%d%d", &x, &add);
                nodeModify(1);
            } else if(ch[0] == 'S'){
                scanf("%d%d", &x, &add);
                add = -add;
                nodeModify(1);
            }
        }
    }
	return 0;
}

void build(int l, int r, int k)
{
	tree[k].l = l; tree[k].r = r;
	if (l == r)
	{
		scanf("%d", &tree[k].w);
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
	tree[k].lazy = 0;
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
	if (x <= mid) 
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
	if (tree[k].l >= x && tree[k].r <= y)
	{
		tree[k].w += (tree[k].r - tree[k].l + 1) * add;
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