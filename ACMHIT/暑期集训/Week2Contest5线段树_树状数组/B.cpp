#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN = 1e5+10;

typedef long long ll;

int p, x, y, t;
ll ans = 0;

struct Node
{
	int l, r, ma;
	ll w;
}node[MAXN<<2];

void build(int l, int r, int k) {
	node[k].l = l; node[k].r = r;
	if (l == r) {
		scanf("%lld", &node[k].w);
		node[k].ma = node[k].w;
		return ;
	}
	int mid = (l + r) >> 1;
	int ls = k<<1, rs = k << 1|1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	node[k].w = node[ls].w + node[rs].w;
	node[k].ma = max(node[k<<1].ma, node[k<<1|1].ma);
}

void intervalInquiry(int k) {
	if ((node[k].l >= x) && (node[k].r <= y)) {
		ans += node[k].w;
		return ;
	}
	int mid = (node[k].l + node[k].r) >> 1;
	if (x <= mid) 
		intervalInquiry(k<<1);
	if (y > mid)
		intervalInquiry(k<<1|1);
}

void intervalModify(int k) {
	if(node[k].ma == 1 || node[k].ma == 0) return ;
	if(node[k].l == node[k].r) {
		node[k].ma = sqrt(node[k].ma);
		node[k].w = sqrt(node[k].w);
		return ;
	}
	int mid = (node[k].l + node[k].r) >> 1;
	if (x <= mid)
		intervalModify(k<<1);
	if (y > mid)
		intervalModify(k<<1|1);
	node[k].w = node[k<<1].w + node[k<<1|1].w;
	node[k].ma = max(node[k<<1].ma, node[k<<1|1].ma);
}

int main() {
	int n, m;
    scanf("%d", &n);
    build(1, n, 1);
    scanf("%d", &m);
    while (m--) {
      	scanf("%d%d%d", &t, &x, &y);
      	if(t == 1) {
      		ans = 0;
      		intervalInquiry(1);
      		printf("%lld\n", ans);
      	} else {
      		intervalModify(1);
      	}
    }
	return 0;
}