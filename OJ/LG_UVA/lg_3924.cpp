#include <cstdio>
#define N 1000050

struct Node
{
	int l, r, sum;
	long long p; // p-possiblity
	inline int len() {
		return r - l + 1;
	}
}node[N << 2];

typedef long long ll;

int depth[N];
ll s[N], ans = 0;
int n, m, qwq, maxd;

inline ll max(ll x, ll y)
{
	return (x > y) ? x : y;
}

void build(int l, int r, int k, int d)
{
	node[k].l = l; node[k].r = r;
	if (l == r)
	{
		depth[l] = d;
		maxd = max(d, maxd);
		scanf("%d", &node[k].sum);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, k << 1, d + 1);
	build(mid + 1, r, k << 1 | 1, d + 1);
	node[k].sum = node[k << 1].sum + node[k << 1 | 1].sum;
}

void query(int k = 1)
{
    if(node[k].l == node[k].r)
    {
        node[k].p = node[k>>1].p>>1;
        ans += node[k].p*node[k].sum;
        return ;
    }
    //int mid = (l+r)>>1;
    int ls = k << 1, rs = k << 1 | 1;
	node[ls].p = node[k].p >> 1;
	node[rs].p = node[k].p >> 1;
    query(k<<1);
    query(k<<1|1);
    ans += node[k].p*node[k].sum;
}

inline ll gcd(ll x, ll y)
{
	return (x%y == 0) ? y : gcd(y, x%y);
}

int main()
{
	scanf("%d%d%d", &n, &m, &qwq);
    build(1, n, 1, 1);
    long long y = 1 << (maxd - 1);
    node[1].p = y;
    ll yy = gcd(y, qwq);
    y /= yy; qwq /= yy;
	query();
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + (1 << maxd) - (1 << (maxd - depth[i]));
	while (m--)
	{
		int l, r, add;
		scanf("%d%d%d", &l, &r, &add);
		ans += (s[r] - s[l - 1])*add;
		printf("%lld\n", ans / y * qwq);
	}
	return 0;
}
