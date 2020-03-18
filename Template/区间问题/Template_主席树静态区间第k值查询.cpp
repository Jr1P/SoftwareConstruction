#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100000 + 5;
//hdu2665 不带修改的主席树, 区间第 k大数

struct Tree
{
	int ls, rs, sum; //ls-leftson结点编号, rs-rightson结点编号
}node[N*20];

int a[N], b[N], rt[N];
//a是原数组, b是排序后数组用于离散化, rt-root结点编号,表示第i棵线段树的根节点编号 
int n, q, T, p;
//q为查询数, T为样例数
int tot, size;
//tot-total, size为去重后数组b的大小

void build(int& o, int l, int r){//o表示当前节点
    o = ++tot;
    node[o].sum = 0;
    if(l == r)
    	return ;
    int mid = (l+r)>>1;
    build(node[o].ls, l, mid);
    build(node[o].rs, mid+1, r);
}

void update(int& o, int l, int r, int last){
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

int query(int pre, int now, int l, int r, int k){ //查询[l,r] k-th
    if(l == r)
    	return l;
    int mid = (l+r) >> 1;
    int cnt = node[node[now].ls].sum-node[node[pre].ls].sum;
    if(k <= cnt)
    	return query(node[pre].ls, node[now].ls, l, mid, k);
    else
    	return query(node[pre].rs, node[now].rs, mid+1, r, k - cnt);
}

void print(){ //输出
	int l, r, k; //[l,r] k-th number
    scanf("%d%d%d", &l, &r, &k);
    int ans = query(rt[l - 1], rt[r], 1, size, k);
    printf("%d\n", b[ans]);
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++)
        {
        	scanf("%d", a+i);
        	b[i] = a[i]; // b数组用于后续离散化操作
        }
        sort(b+1, b+n+1);
        size = unique(b+1, b+n+1)-(b + 1); //unique去重后的数组大小
        tot = 0;
        build(rt[0], 1, size); // 建一棵空树
        for(int i = 1; i <= n; i++)//nlogn
        	a[i] = lower_bound(b+1, b+size+1, a[i])-b;//用lower_bound进行离散化
        for(int i = 1; i <= n; i++)
        {
            p = a[i];
        	update(rt[i], 1, size, rt[i-1]);
        }
        while(q--)
        	print();
    }
    return 0;
}